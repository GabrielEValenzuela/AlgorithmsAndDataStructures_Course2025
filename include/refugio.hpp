#ifndef REFUGIO_HPP
#define REFUGIO_HPP

#include "entidadGenerica.hpp"
#include "wrapperVector.hpp"
#include <iostream>
#include <string>
#include <utility>
#include "list.hpp"

/**
 * @class Refugio
 * @brief Representa un refugio dentro del Yermo
 *
 * Un refugio proporciona seguridad y almacenamiento de recursos para los moradores.
 * Tiene capacidades de defensa y ataque, además de una lista de refugiados y recursos disponibles.
 */
class Refugio : public EntidadGenerica
{
    struct Visitante {
        std::string nombre;
        std::string faccion;
    };
private:
    float m_defense;                                          ///< Nivel de defensa del refugio
    float m_attack;                                           ///< Capacidad de ataque del refugio
    wrapperVector<std::string> m_refugees;                    ///< Lista de moradores dentro del refugio
    wrapperVector<std::pair<std::string, float>> m_resources; ///< Lista de recursos con su cantidad
    DoublyLinkedList<Visitante>* m_visitants;                  ///< Lista de visitantes registrados

    void printRecursive(DoublyListNode<Visitante>* mNode);

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
     *@brief Verifica que el recurso exista
     *@param resource Nombre del recurso
     *@return index(i) si el recurso esta entre los recursos, 0 si el recurso no esta entre los recursos
     */
    size_t verifyResource(const std::string& resource);

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
    void registerVisitant(const std::string& nombre, const std::string& faccion);

    /**
     * @brief Muestra todos los visitantes registrados
     */
    void showVisits();

    /**
     * @brief Busca si una facción ha visitado el refugio
     */
    bool hasFactionVisited(const std::string& faccion) const;
};

#endif // REFUGIO_HPP
