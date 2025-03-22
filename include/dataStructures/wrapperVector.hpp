//
// Created by gvalenzuela on 3/20/25.
//

#ifndef WRAPPERVECTOR_HPP
#define WRAPPERVECTOR_HPP

#include <cstddef>
#include <utility>
#include <algorithm>

auto constexpr INIT_CAPACITY {100}; //< Capacidad inicial del vector

/**
 * @brief: Clase que hace una implementación custom del vector STL usando
 * arrays.
 * @tparam TData: Tipo de dato que se almacenará en el vector. Este tipo de dato
 * es genérico.
 */
template<typename TData>
class wrapperVector
{
private:
    TData* m_data;     //< Puntero a los datos
    size_t m_size;     //< Cantidad de elementos en el vector
    size_t m_capacity; //< Capacidad del vector

    /**
     * @brief: Cuando no haya espacio para mas elementos, debemos aumentar la
     * capacidad del vector.
     */
    void resize()
    {
        auto newCapacity = (m_capacity == 0) ? INIT_CAPACITY : m_capacity * 2;

        auto newData = new TData[m_capacity];

        for (size_t i = 0; i < m_size; i++)
        {
            newData[i] = std::move(m_data[i]);
        }

        delete[] m_data;
        m_data = newData;
    }

public:
    /**
     * @brief: Constructor por defecto
     */
    wrapperVector()
        : m_data {nullptr}
        , m_size {0}
        , m_capacity {0}
    {
    }

    /**
     * @brief: Destructor
     */
    ~wrapperVector()
    {
        delete[] m_data;
    }

    /**
     * @brief: Agregar un elemento al final del vector
     */
    void push_back(const TData& data)
    {
        if (m_size == m_capacity)
        {
            resize();
        }

        m_data[m_size++] = data;
    }

    /**
     * @brief: Agregar un elemento al final del vector. Usamos el operador de
     * mover, para evitar copias.
     */
    void push_back(TData&& data)
    {
        if (m_size == m_capacity)
        {
            resize();
        }

        m_data[m_size++] = std::move(data);
    }

    /**
     * @brief: Obtener el tamaño del vector
     * @note: [[nodiscard]] es un atributo que indica que el valor de retorno de la función no debe ser ignorado.
     */
    [[nodiscard]] size_t size() const
    {
        return m_size;
    }

    /**
     * @brief: Obtener la capacidad del vector
     * @note: [[nodiscard]] es un atributo que indica que el valor de retorno de la función no debe ser ignorado.
     */
    [[nodiscard]] size_t capacity() const
    {
        return m_capacity;
    }

    /**
     * @brief: Obtener un elemento del vector
     */
    TData& operator[](size_t index)
    {
        return m_data[index];
    }

    /**
     * @brief: Obtener un elemento del vector
     */
    const TData& at(size_t index) const
    {
        return m_data[index];
    }

    /**
     * @brief: Realiza un swap de los datos de dos vectores
     * @note: noexcept es una especificación que indica que la función no lanzará excepciones.
     */
    void swap(wrapperVector& other) noexcept
    {
        std::swap(m_data, other.m_data);
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
    }

    /**
     * @brief: Iterador básico (primer elemento)
     */
    TData* begin()
    {
        return m_data;
    }

    /**
     * @brief: Iterador básico (último elemento)
     */
    TData* end()
    {
        return m_data + m_size;
    }
};

#endif // WRAPPERVECTOR_HPP
