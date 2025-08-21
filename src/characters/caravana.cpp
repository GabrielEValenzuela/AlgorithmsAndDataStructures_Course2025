#include "characters/caravana.hpp"

void Caravan::inicializarStock()
{
    std::unordered_map<EngineData::Resources, uint8_t> bag = {
        {EngineData::Resources::FOOD, static_cast<uint8_t>(m_randomgenerator->getInt(1, 5))},
        {EngineData::Resources::WATER, static_cast<uint8_t>(m_randomgenerator->getInt(1, 5))},
        {EngineData::Resources::MEDICINE, static_cast<uint8_t>(m_randomgenerator->getInt(0, 2))},
        {EngineData::Resources::AMMO, static_cast<uint8_t>(m_randomgenerator->getInt(0, 3))},
        {EngineData::Resources::TOOLS, static_cast<uint8_t>(m_randomgenerator->getInt(0, 2))}};

    m_bag = std::move(bag);
}