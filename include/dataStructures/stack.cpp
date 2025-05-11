//
// Created by balta on 13/4/2025.
//
#include "Stack.hpp"
template<typename TData>
Stack<TData>::Stack()
    : m_top(nullptr)
    , m_size(0)
    {}

template<typename TData>
Stack<TData>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

template<typename TData>
void Stack<TData>::push(const TData& value)
{
    auto* nuevo = Node<TData>(value);
    nuevo->next = m_top;
    m_top = nuevo;
}

template<typename TData>
void Stack<TData>::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack is empty");
    }
    auto* aux = m_top;
    m_top = m_top->next;
    delete aux;
}

template<typename TData>
TData& Stack<TData>::top()
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack is empty");
    }
    TData& aux = m_top->data;
    return aux;
}

template<typename TData>
const TData& Stack<TData>::top() const
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack is empty");
    }
    TData& aux = m_top->data;
    return aux;
}

template<typename TData>
bool Stack<TData>::isEmpty() const
{
    return m_top == nullptr;
}

template<typename TData>
size_t Stack<TData>::size() const
{
    return m_size;
}
