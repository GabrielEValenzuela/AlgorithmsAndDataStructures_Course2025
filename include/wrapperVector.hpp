//
// Created by gvalenzuela on 3/20/25.
//

#ifndef WRAPPERVECTOR_HPP
#define WRAPPERVECTOR_HPP

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

        TData* newData = new TData[newCapacity]; //Acá cambié la vieja capacidad por la nueva.

        for (size_t i = 0; i < m_size; i++)
        {
            newData[i] = std::move(m_data[i]);
        }

        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity; //faltaba asignar la capacidad del vector por la nueva.
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
     */
    size_t size() const
    {
        return m_size;
    }

    /**
     * @brief: Obtener la capacidad del vector
     */
    size_t capacity() const
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
     */
    void swap(wrapperVector& other)
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
