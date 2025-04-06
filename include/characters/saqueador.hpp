#ifndef SAQUEADOR_HPP
#define SAQUEADOR_HPP

#include "entidadGenerica.hpp"
#include <cstdint>
#include <iostream>

enum class Estilo : uint8_t
{
    AGRESIVO,
    SIGILOSO,
    OPORTUNISTA
};

/**
 * @class Saqueador
 * @brief Representa un grupo de saqueadores en el mundo post-apocalíptico.
 *
 * Los saqueadores pueden presentarse como agresivos, sigilosos u oportunistas.
 * Sus fuerzas varían entre 5 y 10 miembros.
 */
class Saqueador : public EntidadGenerica
{
private:
    int m_numMiembros; ///< Número de integrantes del grupo
    Estilo m_estilo;   ///< Estilo de saqueo del grupo

public:
    /**
     * @brief Constructor del saqueador
     * @param nombre Nombre del grupo de saqueadores
     * @param estilo Estilo de comportamiento del grupo
     * @param numMiembros Número de miembros del grupo
     */
    Saqueador(const std::string& nombre, Estilo estilo, int numMiembros)
        : EntidadGenerica(nombre)
        , m_numMiembros(numMiembros)
        , m_estilo(estilo)
    {
    }

    /**
     * @brief Muestra la información del grupo de saqueadores
     */
    void showInfo() const override
    {
        std::cout << "💀 Saqueadores: " << m_name << "\n"
                  << " - Estilo: " << (uint8_t)m_estilo << "\n"
                  << " - Miembros: " << m_numMiembros << "\n";
    }

    /**
     * @brief Simula una amenaza del grupo
     */
    void amenazar() const
    {
        switch (m_estilo)
        {
            case Estilo::AGRESIVO:
                std::cout << "💬" << m_name << " >>> ¡Entréganos tus recursos o lo pagarán caro!" << std::endl;
                break;
            case Estilo::SIGILOSO:
                std::cout << "💬" << m_name << " >>> Nadie nos vio entrar, nadie los verá salir..." << std::endl;
                break;
            case Estilo::OPORTUNISTA:
                std::cout << "💬" << m_name << " >>> Solo estamos aquí por lo que sobra... si queda algo." << std::endl;
                break;
        }
    }
};

#endif // SAQUEADOR_HPP
