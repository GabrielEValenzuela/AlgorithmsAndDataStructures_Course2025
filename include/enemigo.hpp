#ifndef ENEMIGO_HPP
#define ENEMIGO_HPP

#include "entidadGenerica.hpp"

class Enemigo : public EntidadGenerica 
{
    private:
        std::string m_faction;
        int m_health;
        int m_damage;
        int m_armor;

    public:
        /* Constructor???
        Enemigo(std::string& m_name, int& m_health, int& m_armor, int& m_damage);
        */
        //Presento metodos a llamar/utilizar en cpp
        void showInfo();
        void doAction();
        
        //Getters
        std::string getFaction();
        int getHealth();
        int getDamage();
        int getArmor();
        
        //Setters
        void setFaction(std::string& m_faction);
        void setHealth(int& m_health);
        void setDamage(int& m_damage);
        void setArmor(int& m_armor);
                
#endif
};