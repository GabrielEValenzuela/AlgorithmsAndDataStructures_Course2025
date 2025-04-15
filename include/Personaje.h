//
// Created by balta on 24/3/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <string>Balta

enum class Faction
{
    VaultTec_Refugiado,
    Hermandad_del_Acero,
    Mercaderes_de_Agua
};


class Personaje : public EntidadGenerica{

    private: Faction faction;

    public:
    Personaje(Faction _faction, std::string _ente_Name)
    : EntidadGenerica(std::move(_ente_Name)), faction(_faction)
    {}
    ~Personaje() = default;


    void showInfo() const override
    {
        std::cout << "Facción: " << factionToString(getFaction()) << std::endl;
    }

    void doAction() const override
    {
        switch (faction) {
            case Faction::VaultTec_Refugiado: std::cout << "Despertando de la criogenisacion" << std::endl; break;
            case Faction::Hermandad_del_Acero: std::cout << "Reparando servoarmadura" << std::endl; break;
            case Faction::Mercaderes_de_Agua: std::cout << "Limpiando filtros de agua" << std::endl; break;
            default: std::cout << "Desconocido" << std::endl;
        }

    }

    std::string factionToString(Faction faction) {
        switch (faction) {
            case Faction::VaultTec_Refugiado: return "Vault-Tec Refugiado";
            case Faction::Hermandad_del_Acero: return "Hermandad del Acero";
            case Faction::Mercaderes_de_Agua: return "Mercaderes de Agua";
            default: return "Desconocido";
        }
    }

    Faction getFaction() const
    {
        return faction;
    }

    void ChangeFaction(Faction _faction)
    {
        faction = _faction;
    }

};
#endif //PERSONAJE_H
