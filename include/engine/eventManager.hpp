#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include "engine.hpp"
#include <atomic>
#include <mutex>

class EventManager
{
public:
    using Event = int; // Define el tipo de evento, puedes cambiarlo según tus necesidades.

    explicit EventManager(Engine& engine);

    // Inicia el hilo que genera eventos aleatorios.
    void start();

    // Detiene el hilo y limpia la cola.
    void stop();

    // Consulta si la cola está vacía.
    bool isEmpty() const;

    // Obtiene el siguiente evento de la cola.
    bool enqueueEvent(const std::string& event);

    // Vacía la cola de eventos.
    void clearQueue();

    // Eventos
    std::vector<std::string>& pendingEvents();

    void setEngine(Engine* engine)
    {
        m_engine = engine;
    }

private:
    std::atomic<bool> m_running;
    std::thread m_eventThread;
    std::mutex m_mutex;
    std::queue<std::string> m_eventQueue;
    Engine* m_engine = nullptr;
};

#endif // EVENT_MANAGER_HPP