//
// Created by Usuario on 21/03/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "entidadGenerica.hpp"
#include "wrapperVector.hpp"


/**
 * @class Personaje
 * @brief Representa un personaje de una faccion de persnajes
 */
class Personaje: public EntidadGenerica {
private:
    float m_health;
    float m_strength;
    float m_defense;
    float m_intelligence;
    std::string m_faction;
    wrapperVector<std::pair<std::string, float>> m_inventory;
public:
    /**
     * @brief Constructor de personajes
     *
     * @param name Nombre del personaje
     *
     */
    Personaje(const std::string& name, float health, float strength, float defense, float intelligence, std::string faction);

    /**
     * @brief Muestra la información del personaje
     */
    void showInfo() const override;

    /**
     * @brief Ejecuta una acción específica del personaje
     */
    void doAction() const override;

    /**
     * @brief Verifica si un objeto existe en el inventario
     * @param object Nombre del objeto
     * @return i(indice) del objeto si se encontro, 0 si el objeto no se encontro
     */
    size_t verifyObject(const std::string& object);

    /**
     * @brief Agrega un objeto al inventario
     * @param object Nombre del objeto
     * @param amount Cantidad del objeto a agregar
     */
    void addObject(const std::string& object, float amount);

    /**
     * @brief Dropea un objeto del inventario
     * @param object Nombre del objeto
     * @param amount Cantidad del objeto a dropear
     */
    void dropObject(const std::string& object, float amount);
};



#endif //PERSONAJE_H
