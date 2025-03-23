//
// Created by ignac on 3/23/2025.
//

#ifndef HERMANDADDELACERO_HPP
#define HERMANDADDELACERO_HPP

#include "personajes.hpp"
#include <string>

    class HermandadAcero : public Personaje {
    public:
        HermandadAcero(const std::string& name) : Personaje(name) {}

        void showInfo() const override {
            std::string info = "Nombre: " + m_name + "\nFacción: Hermandad del Acero";
        }

        void doAction() const override {
            std::string action = m_name + " está protegiendo el yermo con tecnología avanzada.";
        }
    };

#endif // HERMANDADACERO_HPP
