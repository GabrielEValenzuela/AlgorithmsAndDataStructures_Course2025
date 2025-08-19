#ifndef CARAVAN_HPP
#define CARAVAN_HPP

#include "engine/engineData.hpp"
#include "entidadGenerica.hpp"
#include "randomEventGenerator.hpp"
#include <iostream>
#include <unordered_map>

/**
 * @class Caravan
 * @brief Representa una caravana de comerciantes en el Yermo.
 *
 * Las caravanas viajan entre asentamientos, comerciando bienes y recursos.
 * Pueden ofrecer suministros a los refugios a cambio de protección o favores.
 */
class Caravan : public EntidadGenerica
{
private:
    bool m_confia;                                            ///< Si confía en el refugio
    RandomEventGenerator* m_randomgenerator {nullptr};        ///< Generador de eventos aleatorios
    std::unordered_map<EngineData::Resources, uint8_t> m_bag; ///< Bolsa de recursos

public:
    /**
     * @brief Constructor
     * @param nombre Nombre de la caravana
     * @param confia Si confía en el refugio
     */
    explicit Caravan(const std::string& nombre,
                     bool confia,
                     RandomEventGenerator* randomGenerator,
                     std::unordered_map<EngineData::Resources, uint8_t> bag)
        : EntidadGenerica(nombre)
        , m_confia(confia)
        , m_randomgenerator(randomGenerator)
        , m_bag(std::move(bag))
    {
    }

    /**
     * @brief Muestra información de la caravana
     */
    void showInfo() const override
    {
        std::cout << "🚚 CARAVANA: " << m_name << "\n"
                  << " - ¿Confía en el refugio?: " << (m_confia ? "Sí" : "No") << "\n";
    }

    /**
     * @brief Devuelve si la caravana confía en el refugio
     * @return true si confía, false en caso contrario
     */
    bool confia() const
    {
        return m_confia;
    }
};

#endif // CARAVAN_HPP