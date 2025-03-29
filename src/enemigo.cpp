#include "enemigo.hpp"
#include <iostream>

//Declaro variables para el setter
std::string faction;
int armor;
int damage;
int health;

void Enemigo::showInfo()
{
    std::cout << "Vida: "<< m_health << std::endl;
    std::cout << "Armadura: " << m_armor << std::endl;
    std::cout << "Daño: " << m_damage << std::endl;
}
void Enemigo::doAction()
{
    std::cout << "¿Que haces aqui? No podras contra mi armadura de " << m_armor << ", y mis " << m_health << " puntos de vida";
}

    //Setters
    void Enemigo::setFaction(std::string& m_faction)
    {
        faction = m_faction;
    }
    void Enemigo::setArmor(int& m_armor)
    {
        armor = m_armor;
    }
    void Enemigo::setHealth(int& m_health)
    {
        health = m_health;
    }
    void Enemigo::setDamage(int& m_damage)
    {
        damage = m_damage;
    }

    //Getters
    std::string Enemigo::getFaction()
    {
        return faction;
    }
    int Enemigo::getArmor()
    {
        return armor;
    }
    int Enemigo::getDamage()
    {
        return damage;
    }
    int Enemigo::getHealth()
    {
        return health;
    }
