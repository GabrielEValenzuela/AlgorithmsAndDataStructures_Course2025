#ifndef ARTEFACTOUNICO_HPP
#define ARTEFACTOUNICO_HPP

#include "engineData.hpp"
#include "entidadGenerica.hpp"
#include <iostream>
#include <string>

/**
 * @class ArtefactoUnico
 * @brief Representa un artefacto único dentro del universo de Refugio 33.
 *
 * Los artefactos únicos son ítems extremadamente valiosos, difíciles de encontrar y muy codiciados por facciones
 * como los Steel Brothers o las Caravanas. Pueden tener diversos efectos sobre el refugio si son activados o reparados.
 */
class ArtefactoUnico : public EntidadGenerica
{
private:
    std::string m_rarity; ///< Rareza del artefacto (por ejemplo: "Legendario", "Prototipo", "Desconocido")
    EngineData::UniqueArtifactType m_type;          ///< Tipo de artefacto (por ejemplo: "Tecnología", "Arma", "Medicina", "Módulo de defensa")
    double m_durability; ///< Nivel de durabilidad restante del artefacto (de 0.0 a 100.0)

public:
    /**
     * @brief Constructor del artefacto único
     * @param name Nombre del artefacto
     * @param rarity Rareza del artefacto
     * @param type Tipo del artefacto
     * @param durability Durabilidad inicial
     */
    ArtefactoUnico(const std::string& name,
                   const std::string& rarity,
                   const EngineData::UniqueArtifactType type,
                   double durability)
        : EntidadGenerica(name)
        , m_rarity(rarity)
        , m_type(type)
        , m_durability(durability)
    {
    }

    /**
     * @brief Muestra la información del artefacto único
     */
    void showInfo() const override
    {
        std::cout << "🧪 Artefacto: " << m_name << "\n"
                  << " - Tipo      : " << typeToString(m_type) << "\n"
                  << " - Rareza    : " << m_rarity << "\n"
                  << " - Durabilidad: " << m_durability << "%" << std::endl;
    }

    std::string_view typeToString(EngineData::UniqueArtifactType type) const
    {
        switch (type)
        {
            case EngineData::UniqueArtifactType::WEAPON: return "Arma";
            case EngineData::UniqueArtifactType::ARMOR: return "Armadura";
            case EngineData::UniqueArtifactType::VEHICLE: return "Vehículo";
            case EngineData::UniqueArtifactType::RELIC: return "Reliquia";
            case EngineData::UniqueArtifactType::TECHNOLOGY: return "Tecnología";
            default: return "Desconocido";
        }
    }

    /**
     * @brief Simula el uso del artefacto, reduciendo su durabilidad
     * @param amount Cantidad de desgaste
     */
    void use(double amount)
    {
        m_durability -= amount;
        if (m_durability < 0.0)
            m_durability = 0.0;
    }

    /**
     * @brief Verifica si el artefacto está roto
     * @return true si la durabilidad es cero, false en caso contrario
     */
    bool isBroken() const
    {
        return m_durability <= 0.0;
    }
};

#endif // ARTEFACTOUNICO_HPP
