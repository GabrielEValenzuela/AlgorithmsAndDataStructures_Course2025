//
// Created by ignac on 3/23/2025.
//

#ifndef GOLUS_HPP
#define GOLUS_HPP

#include "enemigos.hpp"
#include <string>

    class Gohuls : public Enemigo {
    public:
        Gohuls(const std::string& name) : Enemigo(name) {}

        void showInfo() const override {
            std::string info = "Nombre: " + m_name + "\nTipo: Góhul";
        }

        void doAction() const override {
            std::string action = m_name + " está merodeando en busca de carne humana.";
        }
    };

#endif // GOHULS_HPP