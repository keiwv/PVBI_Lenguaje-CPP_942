#pragma once

template <class T>

class Stack
{
    struct nodo
    {
        T dato;
        struct nodo *prev = nullptr;
    };
    struct nodo *tope = nullptr;

public:
    ~Stack();
    void push(T dato);
    T pop();
    bool IsEmpty() { return (tope == nullptr); };
    void Clear();
    T Peek();
};
template <class T>
void Stack<T>::push(T dato)
{
    struct nodo *nuevo = new struct nodo;
    nuevo->dato = dato;
    nuevo->prev = tope; // Set the prev pointer of the new node correctly
    tope = nuevo;       // Update the top of the stack to point to the new node
}
template <class T>
T Stack<T>::pop()
{
    if (tope != nullptr)
    {

        struct nodo *aux = tope;
        tope = tope->prev;
        T val = aux->dato;
        delete aux;
        return val;
    }
    return (T)0;
}
template <class T>
Stack<T>::~Stack()
{
    Clear();
}
template <class T>
void Stack<T>::Clear()
{
    struct nodo *aux;
    while (tope != nullptr)
    {
        aux = tope;
        tope = tope->prev;
        delete aux;
    }
}
template <class T>
T Stack<T>::Peek()
{
    if (tope == NULL)
    {
        return 0;
    }
    return tope->dato;
}