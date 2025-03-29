#ifndef MINAEXP_HPP
#define MINAEXP_HPP

#include "entidadGenerica.hpp"

class Mina : public EntidadGenerica
{
private:
    int m_health;
    int m_damage;
    int m_range;

public:
    void showInfo();
    void doAction();

    //Setters
    void setHealth(int& m_health);
    void setDamage(int& m_damage);
    void setRange(int& m_range);

    //Getters
    int getHealth();
    int getDamage();
    int getRange();
    
#endif
};