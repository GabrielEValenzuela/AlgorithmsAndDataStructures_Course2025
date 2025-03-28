#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

/**
 * @brief Nodo de lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct ListNode
{
    TData data;
    ListNode* next;

    explicit ListNode(const TData& value)
        : data(value)
        , next(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class LinkedList
{
private:
    ListNode<TData>* head;

public:
    LinkedList()
        : head(nullptr)
    {
    }

    ~LinkedList()
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
    * @brief Crea una lista nueva de n elementos a partir de una posición dada
    *
    */
    ListNode<TData>* take(size_t startPosition, size_t nElements)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        ListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

/**
 * @brief Nodo de lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct DoublyListNode
{
    TData data;
    DoublyListNode* next;
    DoublyListNode* prev;

    explicit DoublyListNode(const TData& value)
        : data(value)
        , next(nullptr)
        , prev(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class DoublyLinkedList
{
private:
    DoublyListNode<TData>* head;

public:
    DoublyLinkedList()
        : head(nullptr)
    {
    }

    ~DoublyLinkedList()
    {
        while(head != nullptr)
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
        }
    }

    /**
     * @brief Retorna el primer elemento de la lista
     *
     * @return Primer elemento de la lista
     */
    DoublyListNode<TData>* get_head() const
    {
        return head;
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
     * @brief Inserta un nuevo elemento al final de la lista
     *
     * @param value Valor a insertar
     */
    void push_back(const TData& value)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
    * @brief Copia los elementos de otra lista
    *
    * @param other Lista de la cual copiar los elementos
    */
    void copy_list(const DoublyLinkedList& other)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        DoublyListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

#endif // LIST_HPP
