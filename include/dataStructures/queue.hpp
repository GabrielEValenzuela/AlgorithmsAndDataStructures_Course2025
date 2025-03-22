#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>

/**
 * @brief Estructura de datos tipo Cola (FIFO - First In, First Out)
 *
 * @tparam TData Tipo de dato almacenado en la cola
 */
template<typename TData>
class Queue
{
private:
    /**
     * @brief Nodo de la cola
     */
    struct Node
    {
        TData data;     ///< Dato almacenado
        Node* next; ///< Puntero al siguiente nodo

        explicit Node(const TData& value)
            : data(value)
            , next(nullptr)
        {
        }
    };

    Node* m_front; ///< Puntero al primer elemento
    Node* m_rear;  ///< Puntero al último elemento
    size_t m_size; ///< Cantidad de elementos en la cola

public:
    /**
     * @brief Constructor por defecto
     */
    Queue()
        : m_front(nullptr)
        , m_rear(nullptr)
        , m_size(0)
    {
    }

    /**
     * @brief Destructor: libera todos los nodos de la cola
     */
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    /**
     * @brief Inserta un elemento al final de la cola
     *
     * @param value Valor a insertar
     */
    void enqueue(const TData& value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            m_front = m_rear = newNode;
        }
        else
        {
            m_rear->next = newNode;
            m_rear = newNode;
        }
        ++m_size;
    }

    /**
     * @brief Elimina el primer elemento de la cola
     *
     * @throws std::underflow_error si la cola está vacía
     */
    void dequeue()
    {
        throw std::underflow_error("Queue is empty");
    }

    /**
     * @brief Devuelve el primer elemento sin eliminarlo
     *
     * @return TData Primer valor en la cola
     * @throws std::underflow_error si la cola está vacía
     */
    TData front() const
    {
        throw std::underflow_error("Queue is empty");
    }

    /**
     * @brief Verifica si la cola está vacía
     *
     * @return true si no hay elementos
     * @return false si hay al menos un elemento
     */
    bool isEmpty() const
    {
        return m_size == 0;
    }

    /**
     * @brief Devuelve la cantidad de elementos en la cola
     *
     * @return size_t tamaño de la cola
     */
    size_t getSize() const
    {
        return m_size;
    }
};

#endif // QUEUE_HPP
