#include "entidadGenerica.hpp"
#include "engine.hpp"

#ifndef PERSONAJES_HPP
#define PERSOANJES_HPP

class Personaje : public EntidadGenerica
{
 private:
    std::string m_faction;
    char m_sex;
 public:
    void showInfo()
    {
        std::cout<<"Nombre :" << m_name << "\n" ;
        std::cout<<"Faccion :" << m_faction << "\n" ;
        std::cout<<"Sexo :" << m_sex << "\n" ;

    }
    void doAction()
    {
        std::cout<<"Mi nombre es: "<<m_name <<".Soy parte de la faccion de "<< m_faction;
    }
};

#endif