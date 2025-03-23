//
// Created by ignac on 3/23/2025.
//

#ifndef MERCADERESDEAGUA_HPP
#define MERCADERESDEAGUA_HPP

#include "personajes.hpp"
#include <string>

    class MercaderAgua : public Personaje {
    public:
        MercaderAgua(const std::string& name) : Personaje(name) {}

        void showInfo() const override {
            std::string info = "Nombre: " + m_name + "\nFacción: Mercaderes de Agua";
        }

        void doAction() const override {
            std::string action = m_name + " está vendiendo agua a los sobrevivientes.";
        }
    };

#endif // MERCADERAGUA_HPP
