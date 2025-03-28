#include <iostream>
#include "entidadGenerica.hpp"


#ifndef ENEMIGOS_HPP
#define ENEMIGOS_HPP

class Enemigo : public EntidadGenerica
{
    private:
        float m_damage;
        float m_armor;
        float m_type;
    public:
        void showInfo()
        {
            std::cout<<"Nombre :" << m_name << "\n" ;
            std::cout<<"Daño :" << m_damage << "\n" ;
            std::cout<<"Armadura :" << m_armor << "\n" ;
            std::cout<<"Tipo :" << m_type << "\n" ;
        }
        void doAction()
        {
            std::cout<< "Soy un enenemigo, vamos pelear !";
        }
};

#endif