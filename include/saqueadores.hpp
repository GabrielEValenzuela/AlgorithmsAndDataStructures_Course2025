//
// Created by ignac on 3/23/2025.
//

#ifndef SAQUEADORES_HPP
#define SAQUEADORES_HPP

#include "enemigos.hpp"
#include <string>

    class Saqueadores : public Enemigo {
    public:
        Saqueadores(const std::string& name) : Enemigo(name) {}

        void showInfo() const override {
            std::string info = "Nombre: " + m_name + "\nTipo: Saqueador";
        }

        void doAction() const override {
            std::string action = m_name + " está saqueando las ciudades destruidas.";
        }
    };

#endif // SAQUEADORES_HPP