#ifndef ASALTANTE_HPP
#define ASALTANTE_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <random>

/**
 * @class Asaltante
 * @brief Representa una banda de asaltantes en el Yermo.
 *
 * Los Raiders suelen operar en grupos armados y bien organizados. Atacan para saquear,
 * pero en ocasiones pueden rendirse y pedir asilo si las cosas no salen como esperaban.
 */
class Asaltante : public EntidadGenerica
{
private:
    int m_integrantes; ///< Cantidad de miembros en la banda
    int m_poderFuego;  ///< Nivel de ataque general
    bool m_rendidos;   ///< Indica si se han rendido
    bool m_seUnieron;  ///< Indica si fueron aceptados en el refugio

public:
    /**
     * @brief Constructor
     * @param nombre Nombre del grupo raider
     */
    explicit Asaltante(const std::string& nombre)
        : EntidadGenerica(nombre)
        , m_integrantes(generarCantidad())
        , m_poderFuego(generarPoder())
        , m_rendidos(false)
        , m_seUnieron(false)
    {
    }

    /**
     * @brief Muestra información del grupo raider
     */
    void showInfo() const override
    {
        std::cout << "🔫 Asaltantes: '" << m_name << "'\n"
                  << " - Miembros: " << m_integrantes << "\n"
                  << " - Poder de fuego: " << m_poderFuego << "\n"
                  << " - ¿Rendidos?: " << (m_rendidos ? "Sí" : "No") << "\n"
                  << " - ¿Se unieron al refugio?: " << (m_seUnieron ? "Sí" : "No") << "\n";
    }

    /**
     * @brief Simula el intento de rendición
     */
    void intentarRendicion()
    {
        static std::mt19937 rng(std::random_device {}());
        std::bernoulli_distribution chance(0.3); // 30% de posibilidad de rendirse

        if (chance(rng))
        {
            m_rendidos = true;
            std::cout << "💬 " << m_name << " >>> ¡Nos rendimos! ¡Déjennos vivir!" << std::endl;
        }
        else
        {
            std::cout << "💬 " << m_name << " >>> ¡Nunca nos rendiremos!" << std::endl;
        }
    }

    /**
     * @brief Acepta a los raiders en el refugio si se rindieron
     */
    bool aceptarEnRefugio()
    {
        if (m_rendidos)
        {
            m_seUnieron = true;
            std::cout << "✅ Los raiders se han unido al refugio. Serán vigilados de cerca..." << std::endl;
            return true;
        }

        std::cout << "❌ No se puede aceptar a un grupo hostil sin rendirse." << std::endl;
        return false;
    }

    /**
     * @brief Devuelve el poder total del grupo
     */
    int poderTotal() const
    {
        return m_integrantes * m_poderFuego;
    }

    bool estanRendidos() const
    {
        return m_rendidos;
    }
    bool seUnieron() const
    {
        return m_seUnieron;
    }

private:
    int generarCantidad() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_int_distribution<int> dist(10, 15);
        return dist(rng);
    }

    int generarPoder() const
    {
        static std::mt19937 rng(std::random_device {}());
        std::uniform_int_distribution<int> dist(15, 30);
        return dist(rng);
    }
};

#endif // ASALTANTE_HPP
