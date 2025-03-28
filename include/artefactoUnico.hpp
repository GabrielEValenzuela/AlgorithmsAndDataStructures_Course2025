#include <iostream>
#include "entidadGenerica.hpp"

#ifndef ARTEFACTO_HPP
#define ARTEFACTO_HPP

class ArtefactoUnico : public EntidadGenerica
{
    private:
     std::string m_rarity;
     std::string m_type;
     float m_durability;
    public:
     void showInfo()
     {
        std::cout<<"Nombre :" << m_name << "\n" ;
        std::cout<<"Rareza :" << m_rarity << "\n" ;
        std::cout<<"Tipo :" << m_type << "\n" ;
        std::cout<<"Durabilidad :" << m_durability << "\n" ;
        
     }

     void doAction()
     {
        std::cout<< m_name << " De rareza "<< m_rarity << ", con durabilidad de " << m_durability;
     }
     
};

#endif