#ifndef NPC_TYPES_HPP
#define NPC_TYPES_HPP

#include <cstdint>

namespace NPC
{

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

    struct VisitantChance
    {
        VisitantCategory type;
        double weight;
    };
} // namespace NPC

#endif // NPC_TYPES_HPP
