#include <iostream>
#include <sstream>
#include <thread>

#include "engine.hpp"

int main()
{
    std::cout << "Bienvenida/o sistema de control 'Refugio 33'" << std::endl;
    // Crea un nuevo jugador
    PlayerInfo player;
    std::cout << "Ingrese tu nombre: ";
    std::string playerName;
    std::getline(std::cin, playerName);
    std::cout << "Ingrese tu nivel: ";
    std::string level;
    std::getline(std::cin, level);

    player.level = level;
    player.name = playerName;

    auto engine = std::make_unique<Engine>();

    std::cout << "Cargando";

    for (int i = 0; i <= 100; i += 10)
    {
        std::cout << "[" << i << "%]" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (i < 100)
        {
            std::cout << "\b\b\b\b\b" << std::flush;
        }
    }

    std::cout << std::endl;
    std::cout << "Sistema de control 'Refugio 33' iniciado correctamente" << std::endl;
    engine->start(player);
    return 0;
}


