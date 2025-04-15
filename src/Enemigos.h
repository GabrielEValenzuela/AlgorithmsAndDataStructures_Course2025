//
// Created by balta on 26/3/2025.
//

#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <iostream>
#include <magic_enum.hpp>
#include <>

enum class TipoEnemigo
{
    Gohuls,
    Saqueadores,
    Protetron,
    Radscorpion
};

class Enemigos : public EntidadGenerica{
    private:
    TipoEnemigo tipo;
public:
    Enemigos(TipoEnemigo t) : EnidadGenerica(magic_enum::enum_name(t)), tipo(t)
    {}
    ~Enemigos() = default;

    void showInfo() const override
    {
        switch (tipo) {
            case tipo::Gohuls: std::cout << "Gohuls: Humano expuesto a la radiacion" << std::endl; break;
            case tipo::Saqueadores: std::cout << "Saqueadores: Supervivientes del refugio 15" << std::endl; break;
            case tipo::Protetron: std::cout << "Protetron: Robot fabricado por RobCo" << std::endl; break;
            case tipo::Radscorpion: std::cout << "Radscorpion: Poseen aguijones altamente venenosos" << std::endl; break;
            default: std::cout << "Desconocido" << std::endl;
        }
    }
    virtual void doAction() const
    {
        case tipo::Gohuls: std::cout << "Atacando al jugador" << std::endl; break;
        case tipo::Saqueadores: std::cout << "Atacando al jugador" << std::endl; break;
        case tipo::Protetron: std::cout << "Atacando al jugador" << std::endl; break;
        case tipo::Radscorpion: std::cout << "Atacando al jugador" << std::endl; break;
        default: std::cout << "Desconocido" << std::endl;
    }
};

#endif //ENEMIGOS_H