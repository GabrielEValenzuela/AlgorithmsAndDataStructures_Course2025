//
// Created by Usuario on 27/03/2025.
//
#include <utility>
#include <iostream>
#include "../include/artefactoUnico.h"

ArtefactoUnico::ArtefactoUnico(const std::string& name, float durability):
EntidadGenerica(name), m_durability(durability)
{

}

void ArtefactoUnico::showInfo() const
{
    std::cout << "Artefacto: " << m_name << "\n";
    std::cout << "\t🛡️  Durabilidad: " << m_durability << "\n";
}

void ArtefactoUnico::doAction() const
{
    std::runtime_error("Not implemented yet");
}
