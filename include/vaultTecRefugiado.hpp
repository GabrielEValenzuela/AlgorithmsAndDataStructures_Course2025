//
// Created by ignac on 3/23/2025.
//

#ifndef VAULTTECREFUGIADO_HPP
#define VAULTTECREFUGIADO_HPP

#include "personajes.hpp"
#include <string>

    class VaultTecRefugiado : public Personaje {
    public:
        VaultTecRefugiado(const std::string& name) : Personaje(name) {}

        void showInfo() const override {
            std::string info = "Nombre: " + m_name + "\nFacción: Vault-Tec Refugiado";
        }

        void doAction() const override {
            std::string action = m_name + " está buscando refugio en un Vault.";
        }
    };

#endif //VAULTTECREFUGIADO_HPP
