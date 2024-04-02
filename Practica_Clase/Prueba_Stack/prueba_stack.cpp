#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include "student.h"
#include <list>

using namespace std;

void stackTest();
void stackTest2();
void stackTest3();
/* void QueueTest2();
void PQueueTest();*/
void pQueueTest2();
void vectorTest();
void listTest();

int main()
{
    listTest();
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

void vectorTest()
{
    // Un vector es un contenedor secuencial en el que los elementos
    // estan almacenados de forma contigua en la memoria, de forma
    // similar a un arreglo. El vector puede ser utilizado en sustitucion{
    // de un arreglo, con la diferencia de que el vector tiene tamanio
    // dinamico.
    vector<int> v(5); // vector de 5 elementos
    for (int i = 0; i < 5; i++)
    {
        // Los elementos del vector se pueden acceder por posicion
        // utilizando el operador []
        v[i] = rand() % 100;
    }
    cout << "Elementos del vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    v.resize(10); // se modifica el tamanio del vector
    cout << "Elementos del vector: ";
    // El vector es un contenedor que puede ser iterado con un for basado
    // en rango.
    for (int n : v)
    {
        cout << n << " ";
    }
    cout << endl;
    // Si se necesita un espacio extra, se puede agregar un elemento nuevo
    // con push_back()
    v.push_back(rand() % 100);
    cout << "Nuevo tamanio del vector: " << v.size() << endl;
    cout << "Nuevo vector: ";
    // Los contenedores secuenciales pueden ser recorridos por medio
    // de un iterador.
    // Un iterador es un objeto que "apunta" a uno de los elementos
    // del contenedor. El iterador puede ser recorrido al siguiente
    // elemento en la secuencia almacenada en el contenedor.
    // LOs contenedores que soportan el uso de iteradores tienen el
    // metodo begin(), que devuelve un iterador al inicio de la secuencia,
    // y end() que devuelve un iterador que marca el final de la secuencia,
    //(una posicion posterior al ultimo elemento).
    vector<int>::iterator it;
    // Obtenemos el iterador al inicio del vector con el metodo begin()
    it = v.begin();
    // Mientras el iterador no este en el fin de la secuencia, seguimos
    // iterando
    while (it != v.end())
    {
        // Para acceder al elemento que apunta el iterador
        // utilizamos el operador de contenido (usado en apuntadores)
        cout << (*it) << " ";
        // Para recorrer el iterador, utilizamos el operador de
        // incremento
        it++;
    }
    cout << endl;
    // Le podemos asignar valores por medio de un conjunto definido con llaves:
    v = {2, 3, 4, 5, 8, 10, 20, 99};
    cout << "Nuevo tamanio del vector: " << v.size() << endl;
    cout << "Elementos del vector: " << endl;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    // Se pueden agregar o eliminar elementos en posiciones intermedias del vector. Para
    // determinar la posicion del elemento a eliminar, o la posicion de insercion, se utilza iterador.
    int x;
    cout << "Dame un valor para insertarlo en el vector: ";
    cin >> x;
    it = v.begin();
    while (it != v.end() && (*it) < x)
    {
        it++;
    }
    v.insert(it, x);
    cout << "Vector factorizado: ";
    for (int n : v)
    {
        cout << n << " ";
    }
    cout << endl;
    cout << "Dame un valor a eliminar: ";
    cin >> x;
    it = v.begin();
    while (it != v.end() && (*it) != x)
    {
        it++;
    }

    if (it != v.end())
    {
        v.erase(it);
        cout << "Vector actualizado: ";
        for (int n : v)
        {
            cout << n << " ";
        }
    }
    else
    {
        cout << "El valor " << x << " no ha sido encontrado.";
    }
}

ostream &operator<<(ostream &out, list<int> l)
{
    out << "[";
    for (auto it = l.begin(); it != l.end(); it++)
    {
        out << (*it) << " ";
    }
    out << "]";
    return out;
}

void listTest()
{
    list<int> lista = {2, 3, 42, 3, 5, 2, 13, 32};
    lista.push_back(45);
    lista.push_front(20);
    cout << "Numero de elementos en la lista: " << lista.size() << endl;
    cout << "Lista: " << lista << endl;
}