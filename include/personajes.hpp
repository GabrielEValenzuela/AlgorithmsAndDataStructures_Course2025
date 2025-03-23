//
// Created by ignac on 3/23/2025.
//

#endif //PERSONAJES_HPP
#ifndef PERSONAJES_HPP
#define PERSONAJES_HPP

#include "entidadGenerica.hpp"

    class Personaje : public EntidadGenerica {
    public:
        Personaje(const std::string& name) : EntidadGenerica(name) {}

        void showInfo() const override;
        void doAction() const override;
    };

#endif // PERSONAJES_HPP