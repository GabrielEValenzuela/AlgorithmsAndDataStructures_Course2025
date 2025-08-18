#ifndef ENGINEDATA_HPP
#define ENGINEDATA_HPP

#include <cstdint>
#include <string_view>

namespace EngineData
{

    /**
     * @brief: Información de la facción
     */
    enum class Faction
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
    enum class Resources
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
    enum class UniqueArtifactType
    {
        WEAPON,     //< Arma
        ARMOR,      //< Armadura
        VEHICLE,    //< Vehículo
        RELIC,      //< Reliquia
        TECH,       //< Tecnología
    };

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
            int minEnemy;
            int maxEnemy;
            double surrenderChance; // Probabilidad de rendición del enemigo
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
            int eventsPerSecond; // Frecuencia de eventos por segundo
            double rateRefugee;  // Tasa de aparición de refugiados
            double rateBrother;  // Tasa de aparición de hermanos
            double rateEnemy;    // Tasa de aparición de enemigos
            double rateCommerce; // Tasa de aparición de comerciantes
            double rateCaravane; // Tasa de aparición de caravanas
        } events;
    };

    /**
     *   @brief: Convierte el enum de recursos a string
     *   @tparam: value Valor del enum
     *   @return: String con el nombre del recurso
     */
    template<typename TData>
    static std::string_view valueToString(const TData& value)
    {
        if constexpr (std::is_same_v<TData, EngineData::Resources>)
        {
            switch (value)
            {
                case EngineData::Resources::FOOD: return "Comida";
                case EngineData::Resources::WATER: return "Agua";
                case EngineData::Resources::MEDICINE: return "Medicina";
                case EngineData::Resources::AMMO: return "Municiones";
                case EngineData::Resources::WEAPONS: return "Armas";
                case EngineData::Resources::ARMOR: return "Armadura";
                case EngineData::Resources::TOOLS: return "Herramientas";
                case EngineData::Resources::MATERIALS: return "Materiales";
                case EngineData::Resources::ELECTRONICS: return "Electrónica";
                case EngineData::Resources::ALCHOHOL: return "Alcohol";
                default: return "Unknown";
            }
        }
        else if constexpr (std::is_same_v<TData, EngineData::Faction>)
        {
            switch (value)
            {
                case EngineData::Faction::WATER_MERCHANTS: return "Mercaderes de agua";
                case EngineData::Faction::MERCHANTS: return "Mercaderes";
                case EngineData::Faction::REFUGEES: return "Refugiados";
                case EngineData::Faction::LOOTERS: return "Saqueadores";
                case EngineData::Faction::STEEL_BROTHERS: return "Hermanos de acero";
                case EngineData::Faction::ENCLAVE: return "Enclave";
                case EngineData::Faction::MUTANTS: return "Mutantes";
                case EngineData::Faction::RAIDERS: return "Asaltantes";
                case EngineData::Faction::GHOULS: return "Ghouls";
                case EngineData::Faction::CARAVAN: return "Caravanas";
                default: return "Unknown";
            }
        }
        else if constexpr (std::is_same_v<TData, EngineData::UniqueArtifactType>)
        {
            switch (value)
            {
                case EngineData::UniqueArtifactType::WEAPON: return "Arma";
                case EngineData::UniqueArtifactType::ARMOR: return "Armadura";
                case EngineData::UniqueArtifactType::VEHICLE: return "Vehículo";
                case EngineData::UniqueArtifactType::RELIC: return "Reliquia";
                case EngineData::UniqueArtifactType::TECH: return "Tecnología";
                default: return "Unknown";
            }
        }
        else
        {
            return "Unknown";
        }
    }

} // namespace EngineData

#endif // ENGINEDATA_HPP
