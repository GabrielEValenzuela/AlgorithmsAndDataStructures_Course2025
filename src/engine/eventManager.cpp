#include "engine/eventManager.hpp"
#include "engine/engine.hpp"
#include "engineData.hpp"
#include <chrono>

auto constexpr DELAY {30}; ///< Delay en segundos para el hilo de eventos

void EventManager::start()
{
    constexpr size_t MAX_QUEUE_SIZE = 10;
    double intervalSeconds = 1.0 / m_engine->engineConfig().events.eventsPerSecond;

    m_eventThread = std::thread(
        [this, intervalSeconds]()
        {
            while (m_running.load())
            {
                {
                    std::unique_lock<std::mutex> lock(m_eventMutex);
                    if (m_eventQueue.size() >= MAX_QUEUE_SIZE)
                    {
                        lock.unlock(); // Libera el mutex a drede para evitar el deadlock
                        std::this_thread::sleep_for(std::chrono::seconds(DELAY));
                        continue;
                    }
                }

                wrapperVector<NPC::VisitantChance> visitants;
                visitants.push_back({NPC::VisitantCategory::REFUGEE, m_engine->engineConfig().events.rateRefugee});
                visitants.push_back({NPC::VisitantCategory::ENEMY, m_engine->engineConfig().events.rateEnemy});
                visitants.push_back({NPC::VisitantCategory::CARAVAN, m_engine->engineConfig().events.rateCaravane});

                double totalWeight = 0.0;
                for (const auto& v : visitants)
                {
                    totalWeight += v.weight;
                }

                double roll = m_engine->wrapperRandomDouble(0.0, totalWeight);
                double cumulative = 0.0;

                for (const auto& visitant : visitants)
                {
                    cumulative += visitant.weight;
                    if (roll <= cumulative)
                    {
                        EngineData::Faction faction {EngineData::Faction::UNKNOWN};

                        switch (visitant.type)
                        {
                            case NPC::VisitantCategory::REFUGEE: faction = EngineData::Faction::REFUGEES; break;
                            case NPC::VisitantCategory::ENEMY:
                            {
                                std::vector<EngineData::Faction> enemies = {EngineData::Faction::RAIDERS};
                                faction = m_engine->wrapperRandomChoice(enemies);
                                break;
                            }
                            case NPC::VisitantCategory::CARAVAN: faction = EngineData::Faction::CARAVAN; break;
                        }

                        auto npc = m_factory->create(faction);

                        {
                            std::lock_guard<std::mutex> lock(m_eventMutex);
                            if (m_eventQueue.size() < MAX_QUEUE_SIZE)
                            {
                                m_eventQueue.emplace(std::move(npc));
                                m_eventCount.fetch_add(1);
                                m_eventCv.notify_one();
                            }
                        }

                        break; // Salir del loop de elección de visitante
                    }
                }

                std::this_thread::sleep_for(std::chrono::duration<double>(intervalSeconds));
            }
        });
}

void EventManager::stop()
{
    m_running.store(false);
    if (m_eventThread.joinable())
    {
        m_eventThread.join();
    }

    clearQueue();
}

bool EventManager::isEmpty()
{
    std::lock_guard<std::mutex> lock(m_eventMutex);
    return m_eventQueue.empty();
}

NPC::VisitanteVariant EventManager::popEvent()
{
    std::unique_lock<std::mutex> lock(m_eventMutex);
    m_eventCv.wait(lock, [this] { return !m_eventQueue.empty() || !m_running.load(); });

    if (m_eventQueue.empty())
    {
        throw std::runtime_error("EventManager is not running");
    }

    auto event = m_eventQueue.front();
    m_eventQueue.pop();
    return event;
}

void EventManager::clearQueue()
{
    std::lock_guard<std::mutex> lock(m_eventMutex);
    while (!m_eventQueue.empty())
    {
        m_eventQueue.pop();
    }
}
