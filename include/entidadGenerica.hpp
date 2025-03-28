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
#include <utility>

/**
 * @brief Define los elementos en común para los entes del board
 */
class EntidadGenerica
{
protected:
    std::string m_name;

public:
    /**
        * @brief Constructor de la clase
        * @param name Nombre del ente
        * @note Se usa explicit para evitar conversiones implícitas , esto es, que el compilador no pueda convertir un
    tipo de dato a otro. Es una buena práctica y ayuda a evitar errores. Además, de que se usa std::move para mover el
    contenido de name a m_name así se evita copiar el contenido de name.
     */
    explicit EntidadGenerica(std::string name)
        : m_name(std::move(name))
    {
    }
    /**
     * @brief Destructor virtual de la clase
     * @note Se usa virtual para que el compilador sepa que debe llamar al destructor de la clase hija, si no se usa
     * virtual, el compilador llamará al destructor de la clase padre. Se usa default para que el compilador genere
     * el destructor por defecto.
     */
    virtual ~EntidadGenerica() = default;

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
