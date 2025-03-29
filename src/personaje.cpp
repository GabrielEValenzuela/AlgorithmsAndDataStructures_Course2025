#include "personaje.hpp"
#include <iostream>

//Declaro variables para almacenar set y get que seran "copias" de la variable original.
std::string faction;
int edad;

//Implementación de showInfo()
void Personaje::showInfo() 
{
    std::cout << "Nombre: " << m_name << std::endl;
    std::cout << "Facción: " << m_faction << std::endl;
    std::cout << "Edad: " << m_edad << std::endl;
}

//Implementación de doAction()
void Personaje::doAction() 
{
    std::cout << "Hola, soy " << m_name << ", de la facción " << m_faction << ", y tengo " << m_edad << " años." << std::endl;
}

//Setters
     void Personaje::setFaction(std::string& m_faction)
     {
        faction = m_faction;
     }
     void Personaje::setEdad(int& m_edad)
     {
        edad = m_edad;
     }

//Getters
     std::string Personaje::getFaction()
     {
        return faction;
     }
     int Personaje::getEdad()
     {
        return edad;
     }

    

