//
// Created by Usuario on 21/03/2025.
//

#include "../include/enemigo.h"

#include <iostream>

Enemigo::Enemigo(const std::string& name, float health, float strength, float defense):
EntidadGenerica(name), m_health(health), m_strength(strength), m_defense(defense)
{
}

void Enemigo::showInfo() const
{
    std::cout << "Enemigo: " << m_name << "\n";
    std::cout << "\t  Vida: " << m_health << "\n";
    std::cout << "\t⚔️  Fuerza: " << m_strength << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "Loot: ";
    for (int i = 0; i < m_loot.size(); i++)
    {
        std::cout << "\t -Objeto: " << m_loot.at(i).first << "- Cantidad: " << m_loot.at(i).second << std::endl;
    }
}

void Enemigo::doAction() const
{
    std::runtime_error("Not implemented yet");
}

size_t Enemigo::verifyObject(const std::string& object)
{
    for (size_t i = 0; i < m_loot.size(); i++)
    {
        if (object == m_loot.at(i).first)
        {
            return i;
        }
    }
    return static_cast<size_t>(-1);
}

void Enemigo::addLootObject(const std::string& object, float amount)
{
    size_t index = verifyObject(object);
    if (index != static_cast<size_t>(-1))
    {
        std::cout << "El objeto " << object << " ya esta en el loot" << std::endl;
        m_loot[index].second += amount;
    }
    else
    {
        std::cout << "El objeto " << object << "NO esta en el loot, se lo agrega" << std::endl;
        m_loot.push_back(std::make_pair(object, amount));
    }
}

wrapperVector<std::pair<std::string, float>> Enemigo::lootObject(const std::string& object, float amount)
{
    size_t index = verifyObject(object);
    wrapperVector<std::pair<std::string, float>> lootedObject;
    if (index != static_cast<size_t>(-1))
    {
        std::cout << "El objeto " << object << " esta disponible para lootearlo" << std::endl;
        if (amount <= m_loot.at(index).second)
        {
            std::cout << "Looteando " << amount << " de " << object << std::endl;
            lootedObject.push_back(std::make_pair(object, amount));
            m_loot[index].second -= amount;
            if (m_loot[index].second == 0)
            {
                // eliminar el objeto del wrappervector m_loot
                m_loot.remove_at(m_loot[index].first);
            }
        }
        else
        {
            std::cout << "Solo hay " << m_loot.at(index).second << " de " << object << ". Tomandolo todo" << std::endl;
            lootedObject.push_back(std::make_pair(object, m_loot[index].second));
            m_loot[index].second = 0;
            // eliminar el objeto del wrappervector m_loot
        }
    }
    else
    {
        std::cout << "El objeto " << object << " NO esta disponible para lootearlo" << std::endl;
    }
    return lootedObject;
}