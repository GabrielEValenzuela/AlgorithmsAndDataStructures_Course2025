#include "refugio.hpp"

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
    std::cout << "👥 Moradores: ";
    for (int refugee = 0; refugee < m_refugees.size(); refugee++)
    {
        std::cout << "\t - " << m_refugees.at(refugee) << std::endl;
    }
    std::cout << "\n";
    std::cout << "\t📦 Recursos: \n";
}

void Refugio::doAction() const
{
    std::cout << "Los refujiados se encuentran criogenizados aun. Esperando niveles de radiacion segura en la superficie" << std::endl;
}

void Refugio::addRefugee(const std::string& refugee)
{
    m_refugees.push_back(refugee);

}

void Refugio::addResource(const std::string& resource, float amount)
{
    m_resources.push_back({resource, amount});
}

bool Refugio::consumeResource(const std::string& resource, float amount)
{
    for (int i = 0; i < (int)m_resources.size(); i++)
    {
        if (m_resources[i].first == resource)
        {
            if (m_resources.at(i).second < amount)
            {
                return false;
            }
            m_resources[i].second -= amount;
            return true;
        }
        i++;

    }
}

void Refugio::registerVisitant(const std::string& nombre, const EngineData::Faction faccion)
{
    if (!isSafeFaction(faccion))
    {
        std::cout << "La faccion: " << nombre << "; no puede entrar al refugio. No es seguro!" "\n";
    }

    Visitante nuevoVisitante {nombre, faccion};
    m_visitants->push_front(nuevoVisitante);
    std::cout << "Visitante: " << nombre << " registrado existosamente en el refugio." << std::endl;
}

void Refugio::showVisits()
{
    std::cout << "📖 Registro de visitas al Refugio " << m_name << ":\n";
    printRecursive(m_visitants->get_head());
}

void Refugio::printRecursive(DoublyListNode<Visitante>* mNode)
{
    if (!mNode)
    {
        std::cout << "Fin del registro!" << std::endl;
        return;
    }
    printRecursive(mNode->next);
    std::cout << mNode->data.nombre << "\n";
}


bool Refugio::isSafeFaction(const EngineData::Faction faccion) const
{
    return (faccion == EngineData::Faction::REFUGEES || faccion == EngineData::Faction::WATER_MERCHANTS ||
            faccion == EngineData::Faction::MERCHANTS || faccion == EngineData::Faction::STEEL_BROTHERS ||
            faccion == EngineData::Faction::CARAVAN);
}
