//
// Created by Usuario on 21/03/2025.
//

#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "entidadGenerica.hpp"

#include <wrapperVector.hpp>

/**
 * @class Enemigo
 * @brief Represneta un enemigo
 */
class Enemigo: public EntidadGenerica {
private:
    float m_health;
    float m_strength;
    float m_defense;
    wrapperVector<std::pair<std::string, float>> m_loot;    // Loot que deja al morir
public:
    Enemigo(const std::string& name, float health, float strength, float defense);

    /**
     * @brief Muestra la información del personaje
     */
    void showInfo() const override;

    /**
     * @brief Ejecuta una acción específica del personaje
     */
    void doAction() const override;

    /**
    * @brief Verifica si un objeto existe en el loot
    * @param object Nombre del objeto
    * @return i(indice) del objeto si se encontro, 0 si el objeto no se encontro
    */
    size_t verifyObject(const std::string& object);

    /**
     * @brief Agrega al loot un objeto
     * @param object Nombre del objeto
     * @param amount Cantidad del objeto
     */
    void addLootObject(const std::string& object, float amount);

    /**
     * @brief Lootea un objeto del enemigo
     * @param object Nombre del objeto
     * @param amount Cantidad del objeto
     */
    wrapperVector<std::pair<std::string, float>> lootObject(const std::string& object, float amount);
};



#endif //ENEMIGO_H
