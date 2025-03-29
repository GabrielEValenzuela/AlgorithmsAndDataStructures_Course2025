#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include "entidadGenerica.hpp"

class Personaje : public EntidadGenerica 
{
    private:
        std::string m_faction;
        int m_edad;

    public:
        /* Constructor???
        Personaje (const std::string& name, const std::string& m_faction, int& m_edad);
        */
        //Presento metodos a llamar/utilizar en cpp
        void showInfo();
        void doAction();
        
        //Getters
        std::string getFaction();
        int getEdad();
        
        //Setters
        void setFaction(std::string& m_faction);
        void setEdad(int& m_edad);
                
#endif
};

