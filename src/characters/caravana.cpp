#include "characters/caravana.hpp"
#include <utility>
#include <unordered_map>
#include "engine/engineData.hpp"

/**
 * @brief Inicializa el stock de la caravana con recursos aleatorios
 */
void Caravan::inicializarStock()
{
    if (m_randomgenerator)
    {
        // Generar una cantidad aleatoria de recursos entre 5 y 20
        int numResources = m_randomgenerator->getInt(5, 20);
        for (int i = 0; i < numResources; ++i)
        {
            // Seleccionar un recurso aleatorio
            EngineData::Resources resource = static_cast<EngineData::Resources>(
                m_randomgenerator->getInt(0, static_cast<int>(EngineData::Resources::ALCHOHOL)));
            // Generar una cantidad aleatoria del recurso entre 1 y 10
            uint8_t quantity = static_cast<uint8_t>(m_randomgenerator->getInt(1, 10));
            // Añadir el recurso a la bolsa
            m_bag[resource] += quantity;
        }
    }
}