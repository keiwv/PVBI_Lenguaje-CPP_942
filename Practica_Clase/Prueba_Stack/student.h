
#include <iostream>
#include <string>
using namespace std;

class Student 
{
protected:
    int matricula = 0;
    string name;
    int puntuacion = 0;

public:
    Student() {}
    Student(int matricula, string name, int puntacion)
    {
        this->matricula = matricula;
        this->puntuacion = puntacion;
        this->name = name;
    }

    bool operator<(const Student &other) const
    {
        return puntuacion < other.puntuacion;
    }
    
    int getMatricula() const { return matricula; }
    string getName() const { return name; }
    int getPuntuacion() const { return puntuacion; }
};

ostream &operator<<(ostream &out, const Student &e)
{
    out << "Estudiante [" << e.getMatricula() << "," << e.getName();
    out << "," << e.getPuntuacion() << "]";
    return out;
}
