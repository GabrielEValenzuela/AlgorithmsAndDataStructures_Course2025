#ifndef NPC_TYPES_HPP
#define NPC_TYPES_HPP

#include "characters/asaltante.hpp"
#include "characters/caravana.hpp"
#include "characters/refugiado.hpp"
#include <cstdint>
#include <variant>

namespace NPC
{
    using VisitanteVariant = std::variant<Refugee, Raider, Caravan>;

    /**
     * @brief: Categorías posibles de visitantes para el sistema de eventos
     */
    enum class VisitantCategory : uint8_t
    {
        REFUGEE,  //< Visitantes refugiados
        BROTHER,  //< Hermanos de acero
        ENEMY,    //< Enemigos como mutantes, ghouls, enclave, saqueadores
        MERCHANT, //< Mercaderes normales o de agua
        CARAVAN   //< Caravanas con artefactos únicos
    };

    /**
     * @brief: Estructura que contiene la categoría y el peso de cada visitante
     */
    struct VisitantChance
    {
        VisitantCategory type; ///< Tipo de visitante
        double weight;         ///< Peso del visitante
    };
} // namespace NPC

#endif // NPC_TYPES_HPP
