#include "refugio.hpp"

Refugio::Refugio(const std::string& name, float defense, float attack): EntidadGenerica(name), m_defense(defense), m_attack(attack){}

void Refugio::showInfo() const
{
    std::cout << "🏠 Refugio: " << m_name << "\n";
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

void Refugio::registerVisitant(const std::string& nombre, const std::string& faccion)
{
    // if (!isSafeFaction(faccion)) {
    throw std::runtime_error("Not implemented yet");
    // }
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

    std::cout << "\t - " << mNode->data.nombre << " de la facción " << mNode->data.faccion << std::endl;
    printRecursive(mNode->next);
}

bool Refugio::hasFactionVisited(const std::string& faccion) const
{
    throw std::runtime_error("Not implemented yet");
}
