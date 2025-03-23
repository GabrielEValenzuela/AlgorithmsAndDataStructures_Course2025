//
// Created by ignac on 3/23/2025.
//

#ifndef ENEMIGOS_HPP
#define ENEMIGOS_HPP

#include "entidadGenerica.hpp"

    class Personaje : public EntidadGenerica {
    public:
        Personaje(const std::string& name) : EntidadGenerica(name) {}

        void showInfo() const override;
        void doAction() const override;
    };

#endif // PERSONAJES_HPP