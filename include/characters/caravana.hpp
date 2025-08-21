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
    explicit Caravan(const std::string& nombre, bool confia, RandomEventGenerator* randomGenerator)
        : EntidadGenerica(nombre)
        , m_confia(confia)
        , m_randomgenerator(randomGenerator)
    {
        inicializarStock();
    }

    /**
     * @brief Muestra información de la caravana
     */
    void showInfo() const override
    {
        std::cout << "🚚 CARAVANA: " << m_name << "\n"
                  << " - ¿Confía en el refugio?: " << (m_confia ? "Sí" : "No") << "\n"
                  << " - Bolsa de recursos:\n";

        for (const auto& [resource, quantity] : m_bag)
        {
            std::cout << "\t\t* " << EngineData::valueToString(resource) << ": " << static_cast<int>(quantity) << "\n";
        }
    }

    /**
     * @brief Devuelve si la caravana confía en el refugio
     * @return true si confía, false en caso contrario
     */
    bool confia() const
    {
        return m_confia;
    }

    /**
     * @brief Genera una bolsa de recursos aleatoria para la caravana
     * @return Mapa de recursos y cantidades
     */
    void inicializarStock();
};

#endif // CARAVAN_HPP