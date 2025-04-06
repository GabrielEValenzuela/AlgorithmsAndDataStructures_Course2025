#ifndef ENGINEDATA_HPP
#define ENGINEDATA_HPP

#include <string_view>
#include <cstdint>

namespace EngineData
{
    /**
     * @brief: Información de la facción
     */
    enum class Faction : uint8_t
    {
        WATER_MERCHANTS, //< Mercaderes de agua
        MERCHANTS,       //< Mercaderes
        REFUGEES,        //< Refugiados
        LOOTERS,         //< Saqueadores
        STEEL_BROTHERS,  //< Hermanos de acero
        ENCLAVE,         //< Enclave
        MUTANTS,         //< Mutantes
        RAIDERS,         //< Asaltantes
        GHOULS,          //< Ghouls
        CARAVAN,         //< Caravanas
        UNKNOWN          //< Desconocido
    };

    /**
     * @brief: Información de los recursos
     */
    enum class Resources : uint8_t
    {
        FOOD,        //< Comida
        WATER,       //< Agua
        MEDICINE,    //< Medicina
        AMMO,        //< Municiones
        WEAPONS,     //< Armas
        ARMOR,       //< Armaduras
        TOOLS,       //< Herramientas
        MATERIALS,   //< Materiales
        ELECTRONICS, //< Electrónica
        ALCHOHOL,    //< Alcohol
    };

    /**
     * @brief: Información del artefacto único
     */
    enum class UniqueArtifactType : uint8_t
    {
        WEAPON,     //< Arma
        ARMOR,      //< Armadura
        VEHICLE,    //< Vehículo
        RELIC,      //< Reliquia
        TECHNOLOGY, //< Tecnología
    };

    template<typename TData>
    auto valueToString(const TData& value) -> std::string_view
    {
        if constexpr (std::is_same_v<TData, EngineData::Resources>)
        {
            return resourceToString(value);
        }
        else if constexpr (std::is_same_v<TData, EngineData::Faction>)
        {
            return factionToString(value);
        }
        else if constexpr (std::is_same_v<TData, EngineData::UniqueArtifactType>)
        {
            return uniqueArtifactTypeToString(value);
        }
    }

    /**
     * @brief: Información del jugador
     */
    struct PlayerInfo
    {
        std::string_view name;
        std::string_view level;
    };

    /**
     * @brief: Información del juego
     * @details: Contiene la configuración del juego, incluyendo las probabilidades de éxito y los multiplicadores
     *           para las diferentes acciones que el jugador puede realizar.
     * @note: Las probabilidades deben estar en el rango de 0.0 a 1.0. Por defecto, se inicializan en 0.2
     */
    struct GameConfig
    {
        struct Exploration
        {
            double successRate;  // Probabilidad de éxito al explorar (0.0 - 1.0)
            double lootChance;   // Posibilidad de encontrar recursos
            double dangerChance; // Riesgo de evento hostil
        } exploration;

        struct Fight
        {
            double criticalHitChance;         // Probabilidad de golpe crítico (0.0 - 1.0)
            double criticalHitMultiplier;     // Multiplicador de daño por golpe crítico
            double enemyAttackMultiplier;     // Multiplicador de ataque enemigo
            double enemyDefenseMultiplier;    // Multiplicador de defensa enemigo
            double enemyHealthMultiplier;     // Multiplicador de salud enemigo
            double enemyLootMultiplier;       // Multiplicador de botín enemigo
            double enemyExperienceMultiplier; // Multiplicador de experiencia enemigo
            double luckyFactor;               // Factor de suerte para el jugador
        } fight;

        struct Resources
        {
            double successRate;
            double lootChance;
            double badLuckChance;
            double durationFactor;
        } resources;

        struct Shelter
        {
            double defenseFactor;
            double attackFactor;
            double visitantsRate;
        } shelter;

        struct Events
        {
            int eventsPerSecond;
            double rateRefugee;
            double rateBrother;
            double rateEnemy;
            double rateCommerce;
            double rateCaravane;
        } events;
    };

} // namespace EngineData

#endif // ENGINEDATA_HPP