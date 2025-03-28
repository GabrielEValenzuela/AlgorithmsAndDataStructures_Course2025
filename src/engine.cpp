#include "engine.hpp"

void Engine::start(const PlayerInfo& player)
{
    m_player = player;
    m_randomGenerator = RandomEventGenerator();
    initResources();
    initEntities();
    interactiveConsole();
}

void Engine::initResources()
{
    std::cout << GREEN << "Inicializando recursos..." << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Engine::initEntities()
{
    std::cout << GREEN << "Inicializando entidades..." << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Engine::showBanner()
{
    std::cout << GREEN
              << "         :---.  .---..---.   :--:..---..---..:------:.  . :-------.:-----:    .-+=.              "
              << RESET << std::endl;
    std::cout << GREEN
              << "          :@@@-  =@@%.*@@@+   *@@#.:%@@-.@@@-.%@@@@@@%. .  =@@@@@@@:*@@@@@+  =@@@@@*             "
              << RESET << std::endl;
    std::cout << GREEN
              << "           +@@%..@@@=:%@@@@.  *@@#.:%@@-.@@@-.::#@@%::.    .:=@@@::.*@@%::..*@@@+::: .           "
              << RESET << std::endl;
    std::cout << GREEN
              << "           :@@@==@@%.=@@@@@=  *@@#.:%@@-.@@@-   #@@#........ -@@@.  *@@%::.-@@@-               . "
              << RESET << std::endl;
    std::cout << GREEN
              << "           .*@@%%@@=.%@@+@@%. *@@#.:%@@-.@@@-   #@@#.-@@@@@* -@@@.  *@@@@@:=@@@.                 "
              << RESET << std::endl;
    std::cout << GREEN
              << "            .@@@@@%.-@@%.@@@- *@@#.:%@@-.@@@- . #@@#.:+++++- -@@@.  *@@%==.-@@@:                 "
              << RESET << std::endl;
    std::cout << GREEN
              << "             =@@@@-.#@@@@@@@* *@@%.:@@@-.@@@-...#@@#.        -@@@.  *@@%....#@@@-...             "
              << RESET << std::endl;
    std::cout << GREEN
              << "             .%@@%.:@@@:.-@@@:-@@@@@@@@..@@@@@@-#@@#.  .     -@@@.  *@@@@@* .*@@@@@*             "
              << RESET << std::endl;
    std::cout << GREEN
              << "             .=##=.=##+  .*##+..+%@@%=. .######:+##*.   .    :###.  =#####=  ..-#@%=        .    "
              << RESET << std::endl;
    std::cout << GREEN
              << "  .                                                             .      .                          "
              << RESET << std::endl;
    std::cout << GREEN
              << "           .           ..               ..-+%@@@@@@%+-..                       .                  "
              << RESET << std::endl;
    std::cout << GREEN
              << "  .                          .        .=@@@@@@@@@@@@@@@@=.     .           . .      .             "
              << RESET << std::endl;
    std::cout << GREEN
              << "           . .                    ...*@@@@%-:.   ..:-%@@@@*.                                      "
              << RESET << std::endl;
    std::cout << GREEN
              << "                .-*@@@@@@@@@@@@@@@@@@@@@=.       .    .=@@@@@@@@@@@@@@@@@@@@@*-..             .   "
              << RESET << std::endl;
    std::cout << GREEN
              << "                .-%@@@@@@@@@@@@@@@@@@@#.    .-*##*-.  . .#@@@@@@@@@@@@@@@@@@@%-.         ..       "
              << RESET << std::endl;
    std::cout << GREEN
              << "                   ..............:@@@+.   :%@@@@@@@@%:   .+@@@:..............                     "
              << RESET << std::endl;
    std::cout << GREEN
              << "        .          .          . .#@@%. ..=@@@@@@@@@@@@=.  .%@@*.      .              .     .      "
              << RESET << std::endl;
    std::cout << GREEN
              << "   .:+%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+   :@@@@@@@@@@@@@%: . *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+:..   ."
              << RESET << std::endl;
    std::cout << GREEN
              << "  .*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+   :@@@@@@@@@@@@@@: . +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.    "
              << RESET << std::endl;
    std::cout << GREEN
              << "    ..:-+++++++++++++++++++++++++@@@*.  .%@@@@@@@@@@@@%.  .#@@@+++++++++++++++++++++++++-:..      "
              << RESET << std::endl;
    std::cout << GREEN
              << " .                              .+@@@:  ..%@@@@@@@@@@%..  :@@@+                                   "
              << RESET << std::endl;
    std::cout << GREEN
              << "      .          .:=*%@@@@@@@@@@@@@@@%.   .=%@@@@@@%-.   .@@@@@@@@@@@@@@@@%*-..                   "
              << RESET << std::endl;
    std::cout << GREEN
              << "       .        :%@@@@@@@@@@@@@@@@@@@@@-   .            -@@@@@@@@@@@@@@@@@@@@@%:                  "
              << RESET << std::endl;
    std::cout << GREEN
              << "                  .:=*###############@@@@=.          .=@@@@###############*-:.           .        "
              << RESET << std::endl;
    std::cout << GREEN
              << "      .            ..                :#@@@@@#+=--=+#@@@@@#.                  .                    "
              << RESET << std::endl;
    std::cout << GREEN
              << "            .                .         .=%@@@@@@@@@@@@%=.                                         "
              << RESET << std::endl;
    std::cout << GREEN
              << "                  . .               ..    ...-=++=:...                   .                        "
              << RESET << std::endl;
}

void Engine::showMenu()
{
    std::cout << YELLOW << "\tLíder: " << m_player.name << " / Lvl: " << m_player.level << RESET << std::endl;
    std::cout << GREEN << "Menú principal" << RESET << std::endl;
    std::cout << GREEN << "<> [d] Mostrar detalles" << RESET << std::endl;
    std::cout << GREEN << "<> [b] Mostrar tablero" << RESET << std::endl;
    std::cout << GREEN << "<> [x] Salir" << RESET << std::endl;
    std::cout << GREEN << "=================================" << RESET << std::endl;
}

void Engine::clearScreen()
{
    std::system(CLEAR_SCREEN);
}

void Engine::interactiveConsole()
{
    bool keepRunning = true;
    while (keepRunning)
    {
        clearScreen();
        showBanner();
        showMenu();
        std::string input;
        std::cout << GREEN << "> " << RESET;
        std::cin >> input;

        if (validOperations.find(input[0]) != validOperations.end())
        {
            switch (validOperations.at(input[0]))
            {
                case Operation::SHOW_DETAILS:
                    std::cout << "Mostrando detalles..." << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    break;
                case Operation::SHOW_BOARD:
                    std::cout << "Mostrando tablero..." << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    break;
                case Operation::EXIT:
                    std::cout << "Saliendo..." << std::endl;
                    keepRunning = false;
                    break;
                default: std::cout << "Operación desconocida" << std::endl; break;
            }
        }
        else
        {
            std::cout << "Operación desconocida" << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
