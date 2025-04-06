#ifndef GAME_SERIALIZER_HPP
#define GAME_SERIALIZER_HPP

#include <string>
#include "engine.hpp"


class Engine; // Forward declaration

class GameSerializer
{
public:
    /**
     * @brief Guarda el estado actual del juego en un archivo
     * @param engine Referencia al motor del juego
     * @param path Ruta del archivo de guardado
     */
    static void save(const Engine& engine, const std::string& path);

    /**
     * @brief Carga el estado del juego desde un archivo
     * @param engine Referencia al motor del juego a poblar
     * @param path Ruta del archivo de guardado
     * @return true si la carga fue exitosa
     */
    static bool load(Engine& engine, const std::string& path);
};

#endif // GAME_SERIALIZER_HPP
