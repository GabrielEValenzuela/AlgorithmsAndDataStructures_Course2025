#ifndef RANDOM_EVENT_GENERATOR_HPP
#define RANDOM_EVENT_GENERATOR_HPP

#include <random>
#include <string>
#include <vector>

/**
 * @brief Generador de eventos aleatorios
 *
 * Esta clase se encarga de generar eventos aleatorios, como números enteros,
 * números flotantes, y elecciones aleatorias de un vector.
 *
 * @note Utiliza el generador de números aleatorios Mersenne Twister.
 */
class RandomEventGenerator
{
private:
    std::mt19937 m_rng;

public:
    RandomEventGenerator()
        : m_rng(std::random_device {}())
    {
    }

    /**
     * @brief Devuelve un entero aleatorio entre [min, max]
     */
    int getInt(int min, int max)
    {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(m_rng);
    }

    /**
     * @brief Devuelve un número flotante aleatorio entre [min, max]
     */
    float getFloat(float min, float max)
    {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(m_rng);
    }

    /**
     * @brief Devuelve true con una probabilidad dada (0.0 a 1.0)
     */
    bool chance(float probability)
    {
        std::bernoulli_distribution dist(probability);
        return dist(m_rng);
    }

    /**
     * @brief Devuelve un elemento aleatorio desde un vector
     */
    template<typename TData>
    const TData& randomChoice(const std::vector<TData>& options)
    {
        int index = getInt(0, static_cast<int>(options.size() - 1));
        return options[index];
    }
};

#endif // RANDOM_EVENT_GENERATOR_HPP
