#include "refugio.hpp"
#include "asaltante.hpp"
#include "refugiado.hpp"
#include <variant>

Refugio::Refugio(const std::string& name, const std::string& leader)
    : EntidadGenerica(name)
    , m_leader(leader)
{
}

void Refugio::showInfo() const
{
    std::cout << "🏠 Refugio: " << m_name << "\t A cargo de: " << m_leader << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "\t⚔️  Ataque: " << m_attack << "\n";
    std::cout << "👥 Moradores: " << "\n";
    for (const auto& refugee : m_refugees)
    {
        refugee.showInfo();
    }
    std::cout << "\n";
    std::cout << "\t📦 Recursos: \n";
}

void Refugio::doAction() const
{
    throw std::runtime_error("Not implemented yet");
}

void Refugio::addRefugee(const std::string& refugee)
{
    throw std::runtime_error("Not implemented yet");
}

void Refugio::addResource(const std::string& resource, float amount)
{
    throw std::runtime_error("Not implemented yet");
}

bool Refugio::consumeResource(const std::string& resource, float amount)
{
    throw std::runtime_error("Not implemented yet");
    return false;
}

void Refugio::registerVisitant(const NPC::VisitanteVariant& visitante)
{
    std::visit(
        [this](const auto& visitor)
        {
            using VisitorType = std::decay_t<decltype(visitor)>;

            if constexpr (std::is_same_v<VisitorType, Raider>)
            {
                std::cout << " 🔺 VAULT detecta problemas... " << '\n';
                visitor.showInfo();
            }
            else if constexpr (std::is_same_v<VisitorType, Refugee>)
            {
                visitor.showInfo();
                m_refugees.push_back(visitor);
            }
            else if constexpr (std::is_same_v<VisitorType, Caravan>)
            {
                visitor.showInfo();
                if (visitor.confia())
                {
                    std::cout << "🚚 La caravana confía en el refugio y se queda." << '\n';
                }
                else
                {
                    std::cout << "🚚 La caravana no confía en el refugio y se va." << '\n';
                }
            }
            else
            {
                std::cout << "👀 Visitante sin comportamiento definido." << '\n';
                throw std::runtime_error("Visitante sin comportamiento definido");
            }
        },
        visitante);
}

void Refugio::showVisits()
{
    std::cout << "📖 Registro de visitas al Refugio " << m_name << ":\n";
    printRecursive(m_visitants->get_head());
}

void Refugio::printRecursive(DoublyListNode<NPC::VisitanteVariant>* mNode)
{
    if (!mNode)
    {
        std::cout << "Fin del registro!" << '\n';
        return;
    }
}

bool Refugio::isSafeFaction(const EngineData::Faction faccion) const
{
    return (faccion == EngineData::Faction::REFUGEES || faccion == EngineData::Faction::WATER_MERCHANTS ||
            faccion == EngineData::Faction::MERCHANTS || faccion == EngineData::Faction::STEEL_BROTHERS ||
            faccion == EngineData::Faction::CARAVAN);
}
