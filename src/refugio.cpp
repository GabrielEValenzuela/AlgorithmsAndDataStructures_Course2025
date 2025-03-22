#include "refugio.hpp"

Refugio::Refugio(const std::string& name, float defense, float attack)
    : EntidadGenerica(name)
    , m_defense(defense)
    , m_attack(attack)
{
}

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
