#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <queue>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <variant>

#include "engineData.hpp"

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#include <cstdlib>
#define CLEAR_SCREEN "clear"
#endif

#define GREEN  "\033[32m"
#define BLUE   "\033[34m"
#define RED    "\033[31m"
#define WHITE  "\033[37m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

auto constexpr SAVE_FILE {"assets/save.txt"};      //< Nombre del archivo de guardado
auto constexpr CONFIG_FILE {"assets/system.conf"}; //< Nombre del archivo de configuración
auto constexpr CONSOLE_VERSION {"0.1.0"};          //< Versión de la consola

class Refugio;

using VisitanteVariant = std::variant<
    Refugiado,
    Mercader,
    MercaderAgua,
    Saqueador,
    HermanoDeAcero,
    Enclave,
    Mutantes,
    Asaltante,
    Ghoul,
    Caravan
>;

/**
 * @brief: Clase que inicializa el motor del juego
 */
class Engine
{
public:
    Engine() = default;
    
    ~Engine()
    {
        m_runningEvents = false;
        if (m_eventThread.joinable())
        {
            m_eventThread.join();
        }
    }
    /**
     * @brief: Inicializa el motor del juego
     */
    void start();

    /**
     * @brief: Carga la configuración del juego
     * @param: config Referencia a la configuración del juego
     */

    void engineConfig(const EngineData::GameConfig& config);

    /**
     * @brief: Obtiene la configuración del juego actual
     * @return: Referencia a la configuración del juego
     */
    const EngineData::GameConfig& engineConfig() const;

    /**
     * @brief: Carga el refugio del jugador
     * @param: refugio Referencia al refugio del jugador
     */
    void playerShelter(const Refugio& refugio);

    /**
     * @brief: Carga la información del jugador
     * @return: Referencia a la información del jugador
     */
    const Refugio& playerShelter() const;

    /**
     * @brief: Carga la información del jugador
     * @param: player Referencia a la información del jugador
     */
    void playerInfo(const EngineData::PlayerInfo& player);

    /**
     * @brief: Carga la información del jugador
     * @return: Referencia a la información del jugador
     */
    const EngineData::PlayerInfo& playerInfo() const;

private:
    /**
     * @brief: Inicializa los recursos del tablero
     */
    void initResources();

    /**
     * @brief: Inicializa los elementos del tablero
     */
    static void initEntities();

    /**
     * @brief: Consola interactiva
     */
    void interactiveConsole();

    /**
     * @brief: Muestra el banner de bienvenida
     */
    void showBanner();

    /**
     * @brief: Muestra el menu principal
     */
    static void showMenu();

    /**
     * @brief: Limpia la pantalla antes de mostrar el menú
     */
    void clearScreen();

    /**
     * @brief: Carga la información de guardado
     */
    void loadGame();

    /**
     * @brief: Carga la configuración del juego
     */
    void loadConfig();

    /**
     * @brief Genera un nuevo evento
     */
    void newEvent();

    /**
     * @brief Factory de generacion de personajes
     * @param faction La facción a crear
     * @return Un nuevo NPC
     */
    VisitanteVariant newCharacter(EngineData::Faction faction);

    EngineData::PlayerInfo m_player;        //< Información del jugador
    RandomEventGenerator m_randomGenerator; //< Generador de eventos aleatorios
    EngineData::GameConfig m_gameConfig{};    //< Configuración del juego
    std::unique_ptr<Refugio> m_shelter;     //< Refugio del jugador
    std::queue<EngineData::Faction> m_eventQueue;
    std::mutex m_eventMutex;
    std::condition_variable m_eventCv;
    bool m_runningEvents = false;
    std::thread m_eventThread;


    /**
     * @brief: Operaciones que puede realizar el jugador
     */
    enum class Operation : uint8_t
    {
        SHOW_STATUS, //< Muestra el estado actual del refugio
        SHOW_EVENTS, //< Muestra los eventos aleatorios
        CHECK_EVENT, //< Muestra el evento actual
        EXPLORE,     //< Explora el mapa
        FIGHT,       //< Lucha contra un enemigo
        EXIT,        //< Salir del juego
        SAVE,        //< Guardar el juego
        UNKNOWN      //< Operación desconocida
    };

    const std::unordered_map<char, Operation> m_validOperations = {{'i', Operation::SHOW_STATUS},
                                                                   {'e', Operation::SHOW_EVENTS},
                                                                   {'c', Operation::CHECK_EVENT},
                                                                   {'x', Operation::EXPLORE},
                                                                   {'f', Operation::FIGHT},
                                                                   {'s', Operation::SAVE},
                                                                   {'q', Operation::EXIT}};

    const std::vector<std::string> m_names = {
        "Lucas", "Valentina", "Mateo",  "Camila",   "Santiago", "Julieta", "Benjamín", "Martina", "Joaquín", "Catalina",
        "Tomás", "Emma",      "Franco", "Isabella", "Thiago",   "Renata",  "Ignacio",  "Mía",     "Bruno",   "Lola"};

    const std::vector<std::string> m_surnames = {
        "Fernández", "Gómez", "Rodríguez", "López",  "Martínez", "Pérez", "González", "Romero", "Sosa",   "Torres",
        "Álvarez",   "Ruiz",  "Ramírez",   "Flores", "Acosta",   "Ortiz", "Silva",    "Molina", "Castro", "Núñez"};

    const std::vector<std::string> m_groupsEnemys = {
        "El Lince", "Cuchillo", "Sombra", "Rata",  "Machete", "El Tuerto", "Ruger",  "Veneno", "Kilo",    "Toro",
        "Jaque",    "Hueso",    "Chispa", "Ruido", "Filo",    "El Ciego",  "Piedra", "Trapo",  "Garrote", "Ladrido"};

    const std::vector<std::string> m_merchants = {"Don Eric",       "El turco",
                                                  "El Sapo",        "Maese Gutiérrez",
                                                  "Tito Ramires",   "Nina la audaz",
                                                  "El foragido",    "Candelario",
                                                  "Rubén el Viejo", "Salomé",
                                                  "Don Atún",       "Capitán Fierro",
                                                  "Manolo Bidón",   "Paco el Tranquilo",
                                                  "Zulema",         "Yolanda",
                                                  "Valerio",        "Iván de los Precios",
                                                  "Florinda",       "Greta"};
};

#endif // ENGINE_HPP
