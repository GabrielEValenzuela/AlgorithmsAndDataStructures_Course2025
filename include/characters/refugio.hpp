#ifndef REFUGIO_HPP
#define REFUGIO_HPP

#include "engine.hpp"
#include "engineData.hpp"
#include "entidadGenerica.hpp"
#include "list.hpp"
#include "wrapperVector.hpp"
#include <iostream>
#include <string>
#include <utility>

/**
 * @class Refugio
 * @brief Representa un refugio dentro del Yermo
 *
 * Un refugio proporciona seguridad y almacenamiento de recursos para los moradores.
 * Tiene capacidades de defensa y ataque, además de una lista de refugiados y recursos disponibles.
 */
class Refugio : public EntidadGenerica
{

    /**
     * @struct Visitante
     * @brief Representa un visitante del refugio
     *
     * Contiene el nombre y la facción del visitante.
     */
    struct Visitante
    {
        std::string nombre;
        EngineData::Faction faccion;
    };

private:
    double m_defense;                                         ///< Nivel de defensa del refugio
    double m_attack;                                          ///< Capacidad de ataque del refugio
    wrapperVector<std::string> m_refugees;                    ///< Lista de moradores dentro del refugio
    wrapperVector<std::pair<std::string, float>> m_resources; ///< Lista de recursos con su cantidad
    DoublyLinkedList<Visitante>* m_visitants;                 ///< Lista de visitantes registrados

    std::string m_leader;                                     ///< Nombre del líder del refugio

    void printRecursive(DoublyListNode<Visitante>* mNode);

    /**
     * @brief Devuelve la faccion en formato de string para su impresion.
     */
    std::string faccionToString(EngineData::Faction faccion) const;

public:
    /**
     * @brief Constructor del refugio
     *
     * @param name Nombre del refugio
     * @param leader Nombre del líder del refugio
     */
    Refugio(const std::string& name, const std::string& leader);

    /**
     * @brief Muestra la información del refugio
     */
    void showInfo() const override;

    /**
     * @brief Ejecuta una acción específica del refugio
     */
    void doAction() const;

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

    /**
     * @brief Registra un visitante en el refugio (nombre y facción)
     * @param nombre Nombre del visitante
     * @param faccion Facción del visitante
     */
    void registerVisitant(const std::string& nombre, EngineData::Faction faccion);

    /**
     * @brief Muestra todos los visitantes registrados
     */
    void showVisits();

    /**
     * @brief Busca si una facción ha visitado el refugio
     */
    bool hasFactionVisited(EngineData::Faction faccion) const;

    /**
     *
     * @param faccion Faccion a verificar si es segura.
     * @return Booleano si es segura o no.
     */
    bool isSafeFaction(EngineData::Faction faccion) const;
};

#endif // REFUGIO_HPP
