#include "Materia.h"
#include<sstream>
#include<iostream>
#include<iomanip>
using std::setw;
using std::right;
using std::left;


Materia::Materia(int clave, string nombre, int creditos, bool obligatoria, Etapa etapa)
{
	this->clave = clave;
	this->nombre = nombre;
	this->creditos = creditos;
	this->obligatoria = obligatoria;
	this->etapa = etapa;
}

string Materia::ToString() const
{
	std::ostringstream out;
	out << setw(6) << clave << " ";
	out<<setw(50)<< left<<nombre << " ";
	out <<setw(8)<< left<<creditos << " ";
	out << setw(4)<<left;
	if (obligatoria)
		out << "Obl ";
	else
		out << "Opt ";
	switch (etapa) {
		case BASICA: out << "Basica\t"; break;
		case DISCIPLINARIA: out << "Disciplinaria\t"; break;
		case TERMINAL: out << "Terminal";
	}
	
	return out.str();
}
