#ifndef CARAVAN_HPP
#define CARAVAN_HPP

#include "artefactoUnico.hpp"
#include "entidadGenerica.hpp"
#include <iostream>
#include <memory>
#include <vector>

/**
 * @class Caravana
 * @brief Representa a los comerciantes itinerantes de artefactos únicos.
 *
 * La caravana viaja por el yermo ofreciendo artículos extremadamente raros a precios elevados.
 */
class Caravana : public EntidadGenerica
{
private:
    std::vector<std::shared_ptr<ArtefactoUnico>> m_stock; ///< Lista de artefactos únicos disponibles
    bool m_confia;                                        ///< Confianza en el refugio

public:
    /**
     * @brief Constructor
     * @param nombre Nombre de la caravana
     * @param confia Indica si la caravana está dispuesta a comerciar
     */
    Caravana(const std::string& nombre, bool confia)
        : EntidadGenerica(nombre)
        , m_confia(confia)
    {
        inicializarStock();
    }

    /**
     * @brief Muestra el inventario de la caravana
     */
    void showInfo() const override
    {
        std::cout << "🚚 Caravana: " << m_name << "\n";
        std::cout << " - Confianza: " << (m_confia ? "Sí" : "No") << "\n";
        std::cout << " - Artefactos disponibles:\n";
        for (const auto& item : m_stock)
        {
            std::cout << "  ";
            item->showInfo();
        }
    }

    /**
     * @brief Intenta comprar un artefacto
     * @param nombre Nombre del artefacto
     * @return Puntero al artefacto si se realizó la transacción, nullptr en caso contrario
     */
    std::shared_ptr<ArtefactoUnico> comprarArtefacto(const std::string& nombre)
    {
        if (!m_confia)
        {
            std::cout << "💬 " << m_name << " >>> No confiamos lo suficiente en tu refugio para hacer negocios."
                      << std::endl;
            return nullptr;
        }

        for (auto it = m_stock.begin(); it != m_stock.end(); ++it)
        {
            if ((*it)->getNombre() == nombre)
            {
                std::cout << "💬 " << m_name << " >>> Excelente elección. Espero que lo uses bien." << std::endl;
                auto item = *it;
                m_stock.erase(it);
                return item;
            }
        }

        std::cout << "💬 " << m_name << " >>> No tenemos ese artefacto en este momento." << std::endl;
        return nullptr;
    }

    /**
     * @brief Simula una evaluación de confianza futura
     */
    void evaluarConfianza()
    {
        m_confia = true; // Lógica temporal, puede depender del nivel del refugio
    }

private:
    void inicializarStock()
    {
        using EngineData::UniqueArtifactType;

        m_stock.emplace_back(std::make_shared<ArtefactoUnico>(
            "Detector de Radiación", "Épico", UniqueArtifactType::TECHNOLOGY, 250.0));

        m_stock.emplace_back(std::make_shared<ArtefactoUnico>(
            "Pistola Láser Táctica", "Legendaria", UniqueArtifactType::WEAPON, 400.0));

        m_stock.emplace_back(std::make_shared<ArtefactoUnico>(
            "Batería de Fusión", "Rara", UniqueArtifactType::TECHNOLOGY, 320.0));
    }

};

#endif // CARAVAN_HPP
