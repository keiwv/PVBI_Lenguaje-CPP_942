#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include "student.h"

using namespace std;

void stackTest();
void stackTest2();
void stackTest3();
void QueueTest2();
void PQueueTest();
void pQueueTest2();

int main()
{
    pQueueTest2();
    return 0;
}

void stackTest()
{
    stack<int> pila;
    int n;

    while (true)
    {
        cout << "Give me a number (-1 para terminar): ";
        cin >> n;

        if (n == -1)
        {
            break;
        }
        pila.push(n);
    }

    cout << "Cantidad de elementos agregados a la pila: " << pila.size() << endl;
    cout << "Elemento en el tope de la fila: " << pila.top() << endl;
    cout << "Todos los elementos de la pila: ";

    while (!pila.empty())
    {
        cout << " " << pila.top();
        pila.pop();
    }
    cout << endl;
}

void stackTest2()
{
    string frase;
    bool palindromo = true;
    stack<char> pila;

    cout << "Dime una frase: ";
    getline(cin, frase);

    int fraseSize = frase.size();
    for (int i = 0; i < fraseSize; i++)
    {
        if (frase[i] != ' ')
        {
            pila.push(frase[i]);
        }
    }

    for (char c : frase)
    {
        if (c != ' ')
        {
            if (tolower(c) != pila.top())
            {
                palindromo = false;
                break;
            }
            pila.pop();
        }
    }
    if (palindromo)
    {
        cout << "\"" << frase << "\""
             << " es palindromo" << endl;
    }
    else
    {
        cout << "\"" << frase << "\""
             << " no es palindromo" << endl;
    }
}

void stackTest3()
{

    queue<int> cola;
    int n;
    while (true)
    {
        cout << "Give me a number (-1 para terminar): ";
        cin >> n;

        if (n == -1)
        {
            break;
        }
        cola.push(n);
    }

    cout << "Numero de elementos en cola: " << cola.size() << endl;
    cout << "Ultimo elemento de la cola: " << cola.back() << endl;
    cout << "Primer elemento de la cola: " << cola.front() << endl;
    cout << "Elementos de la cola: ";
    while (!cola.empty())
    {
        cout << " " << cola.front();
        cola.pop();
    }
    cout << endl;
}

/*void QueueTest2()
{
    deque<int> cola;
    int n;
    bool alt = true;
    while (true)
    {
        cout << "Give me a number (-1 para terminar): ";
        cin >> n;

        if (n == -1)
        {
            break;
        }
        if (alt)
        {
            cola.push_back(n);
        }
        else
        {
            cola.push_front(n);
        }
        alt = !alt;
    }

    cout << "Cantidad de elementos en la nocla" << cola.size() << endl;
    cout << "Elemento al inicio: " << cola.front() << endl;

    cout << "Elemento al último: " << cola.end() << endl;

    while (!cola.empty())
    {
        cout << " " << cola.front();
        cola.pop();
    }
    cout << endl;
}

void PQueueTest()
{
    priority_queue<int> cola;
    int n;
    while (true)
    {
        cout << "Give me a number (-1 para terminar): ";
        cin >> n;

        if (n == -1)
        {
            break;
        }
        cola.push(n);
    }
    cout << "Cantidad de elementos en la nocla" << cola.size() << endl;
    cout << "Elemento de mayor prioridad: " << cola.top() << endl;
    cout << "Elementos en la cola: " << endl;

    while (!cola.empty())
    {
        cout << " " << cola.top();
        cola.pop();
    }
    cout << endl;
}
    bool operator<(const Student& other) const
    {
        return puntuacion < other.puntuacion;
    }*/
void pQueueTest2()
{
    priority_queue<Student> cola;

    cola.push(Student(322, "nose", 13));
    cola.push({37283, "nose2", 33});

    Student e;
    e = {2382, "hola", 392};
    cola.push(e);
    cola.emplace(323123, "jpse", 382);

    cout << "Cantidad de elementos en cola: " << cola.size() << endl;
    cout << "Estudiante con mayor prioridad: " << cola.top() << endl;
    cout << "Estudiantes en la cola: " << endl;

    while (!cola.empty())
    {
        cout << cola.top() << endl;
        cola.pop();
    }
}