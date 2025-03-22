#ifndef REFUGIO_HPP
#define REFUGIO_HPP

#include "entidadGenerica.hpp"
#include "wrapperVector.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/**
 * @class Refugio
 * @brief Representa un refugio dentro del Yermo
 *
 * Un refugio proporciona seguridad y almacenamiento de recursos para los moradores.
 * Tiene capacidades de defensa y ataque, además de una lista de refugiados y recursos disponibles.
 */
class Refugio : public EntidadGenerica
{
private:
    float m_defense;                                          ///< Nivel de defensa del refugio
    float m_attack;                                           ///< Capacidad de ataque del refugio
    wrapperVector<std::string> m_refugees;                    ///< Lista de moradores dentro del refugio
    wrapperVector<std::pair<std::string, float>> m_resources; ///< Lista de recursos con su cantidad

public:
    /**
     * @brief Constructor del refugio
     *
     * @param name Nombre del refugio
     * @param defense Nivel de defensa inicial
     * @param attack Nivel de ataque inicial
     */
    Refugio(const std::string& name, float defense, float attack);

    /**
     * @brief Muestra la información del refugio
     */
    void showInfo() const override;

    /**
     * @brief Ejecuta una acción específica del refugio
     */
    void doAction() const override;

    /**
     * @brief Agrega un morador al refugio
     * @param refugee Nombre del morador
     */
    void addRefugee(const std::string& refugee);

    /**
     * @brief Agrega un recurso al refugio
     * @param resource Nombre del recurso
     * @param amount Cantidad del recurso
     */
    void addResource(const std::string& resource, float amount);

    /**
     * @brief Consume un recurso del refugio
     * @param resource Nombre del recurso a consumir
     * @param amount Cantidad a consumir
     * @return true si el consumo fue exitoso, false si no hay suficiente recurso
     */
    bool consumeResource(const std::string& resource, float amount);
};

#endif // REFUGIO_HPP
