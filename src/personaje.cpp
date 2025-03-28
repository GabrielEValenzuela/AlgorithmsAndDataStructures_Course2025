//
// Created by Usuario on 21/03/2025.
//

#include <utility>
#include <iostream>

#include "../include/personaje.h"

Personaje::Personaje(const std::string& name, float health, float strength, float defense, float intelligence, std::string faction):
EntidadGenerica(name), m_health(health), m_strength(strength), m_defense(defense), m_intelligence(intelligence), m_faction(std::move(faction))
{
}
void Personaje::showInfo() const
{
    std::cout << "Personaje: " << m_name << "\n";
    std::cout << "🏠 Faccion: " << m_faction << "\n";
    std::cout << "\t  Vida: " << m_health << "\n";
    std::cout << "\t⚔️  Fuerza: " << m_strength << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "\t  Inteligencia: " << m_intelligence << "\n";
    std::cout << "Inventario: \n";
    for (int i = 0; i < m_inventory.size(); i++)
    {
        std::cout << "\t -Objeto: " << m_inventory.at(i).first << "- Cantidad: " << m_inventory.at(i).second << std::endl;
    }
}

void Personaje::doAction() const
{
    std::runtime_error("Not implemented yet");
}

size_t Personaje::verifyObject(const std::string& object)
{
    for (size_t i = 0; i < m_inventory.size(); i++)
    {
        if (object == m_inventory.at(i).first)
        {
            return i;
        }
    }
    return static_cast<size_t>(-1);
}

void Personaje::addObject(const std::string& object, float amount)
{
    size_t index = verifyObject(object);
    if (index != static_cast<size_t>(-1))
    {
        std::cout << "El objeto " << object << " ya esta en el inventario" << std::endl;
        std::cout << "Se le agregara al objeto " << object << "la cantidad de: " << amount << std::endl;
        m_inventory[index].second += amount;
    }
    else
    {
        m_inventory.push_back(std::make_pair(object, amount));
    }
}

void Personaje::dropObject(const std::string& object, float amount)
{
    size_t index = verifyObject(object);
    if (index != static_cast<size_t>(-1))
    {
        std::cout << "El objeto " << object << " ya esta en el inventario" << std::endl;
        if (amount <= m_inventory.at(index).second)
        {
            std::cout << "Se dropeara la cantidad de  " << amount << " del objeto " << object << std::endl;
            m_inventory[index].second -= amount;
        }
        else
        {
            std::cout << "Se dropeara toda la cantidad del objeto " << object << std::endl;
            m_inventory[index].second = 0;
        }
    }
}