#pragma once


class Stack
{
    struct nodo
    {
        int dato = 0;
        struct nodo *prev = nullptr;
    };
    struct nodo *tope = nullptr;

public:
    ~Stack();
    void push(int dato);
    int pop();
    bool IsEmpty(){ return (tope == nullptr);};
};

void Stack::push(int dato)
{
    struct nodo *nuevo = new struct nodo;
    nuevo->dato = dato;
    tope->prev = tope;
    tope = nuevo;
}

int Stack::pop()
{
    if (tope != nullptr)
    {

        struct nodo *aux = tope;
        tope = tope->prev;
        int val = aux->dato;
        delete aux;
        return val;
    }
    return 0;
}

Stack::~Stack()
{
    struct nodo *aux;
    while (tope != nullptr)
    {
        aux = tope;
        tope = tope->prev;
        delete aux;
    }
}