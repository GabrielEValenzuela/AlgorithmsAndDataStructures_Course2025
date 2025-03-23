//
// Created by gvalenzuela on 3/20/25.
//

// Simular diferentes entes:
// - Refugio
// - Personaje
// - Enemigos (gohuls)
// - Otro elemento a definir

#ifndef ENTIDADGENERICA_HPP
#define ENTIDADGENERICA_HPP

#include <string>

/**
 * @brief Define los elementos en común para los entes del board
 */
class EntidadGenerica
{
protected:
    std::string m_name;

public:
    EntidadGenerica(const std::string& name)
        : m_name(name)
    {
    }
    virtual ~EntidadGenerica() {}

    /**
     * @brief Muestra la información del ente. Mostrando el nombre y otros atributos
     */
    virtual void showInfo() const = 0;

    /**
     * @brief Realiza la acción específica del ente
     */
    virtual void doAction() const = 0;
};

#endif // ENTIDADGENERICA_HPP
