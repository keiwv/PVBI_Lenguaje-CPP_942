#include "Calificacion.h"
#include<sstream>
#include<iomanip>
using std::setw;
using std::right;
using std::left;

Calificacion::Calificacion(int valor, Materia* materia)
{
	this->valor = valor;
	this->materia = materia;
}

string Calificacion::ToString()
{
	std::ostringstream out;
	out << setw(6) << materia->GetClave() << " ";
	out << setw(50) << left << materia->GetNombre()<<" ";
	out << setw(5) << right << valor << " ";
	out << setw(5) << right << materia->GetCreditos();
	return out.str();
}
