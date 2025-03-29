#include "mina.hpp"
#include <iostream>

//Variables para set y get
int health;
int damage;
int range;

void Mina::showInfo() //Mina explosiva es una herramienta de defensa, la cual tiene cierta vida, daño y rango de explosion.
{
std::cout << "Vida: " << m_health << std::endl;
std::cout << "Daño: " << m_damage << std::endl;
std::cout << "Rango: " << m_range << std::endl;
}

    //Setters
    void Mina::setHealth(int& m_health)
    {
        health = m_health;
    }
    void Mina::setDamage(int& m_damage)
    {
        damage = m_damage;
    }
    void Mina::setRange(int& m_range)
    {
        range = m_range;
    }

    //Getters
    int Mina::getHealth()
    {
        return health;
    }
    int Mina::getDamage()
    {
        return damage;
    }
    int Mina::getRange()
    {
        return range;
    }