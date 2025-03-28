//
// Created by Usuario on 27/03/2025.
//

#ifndef ARTEFACTOUNICO_H
#define ARTEFACTOUNICO_H

#include "entidadGenerica.hpp"


class ArtefactoUnico: public EntidadGenerica {
private:
    float m_durability;
public:
    ArtefactoUnico(const std::string& name, float durability);

    /**
     * @brief Muestra la información del artefacto
     */
    void showInfo() const override;

    /**
     * @brief Ejecuta una acción específica del artefacto
     */
    void doAction() const override;
};



#endif //ARTEFACTOUNICO_H
