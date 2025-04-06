
#ifndef GAME_CONSOLE_HPP
#define GAME_CONSOLE_HPP

#include "engine.hpp"
#include <string>
#include <vector>

/**
 * @class GameConsole
 * @brief Maneja los comandos de la consola (status, check, explore, etc.) y su interacción con el Engine.
 *
 * Esta clase proporciona una interfaz para interactuar con el motor del juego (Engine) a través de una consola.
 * Permite procesar comandos de texto, mantener un historial de comandos y generar salidas relacionadas con
 * las operaciones realizadas en el motor del juego.
 */
class GameConsole
{
public:
    void interativeLoop();

    void processCommand(const std::string& input);

    void setEngine(Engine* engine)
    {
        m_engine = engine;
    }

private:
    // Stores the history of commands
    std::vector<std::string> commandHistory;

    // Stores the output of the console
    std::vector<std::string> outputBuffer;

    // Helper method to execute a command
    void executeCommand(const std::string& command);

    Engine* m_engine = nullptr;
};

#endif // GAME_CONSOLE_HPP
