#pragma once
#include"Kardex.h"
#include<string>
using std::string;
class Estudiante
{
protected:
	int matricula;
	string nombre;
	string carrera;
	Kardex kardex;//El kardex del estudiante
public:
	Estudiante(int matricula = 0,
		string nombre = "", string carrera = "");
	//Getters
	int GetMatricula()const { return matricula; }
	string GetNombre()const { return nombre; }
	string GetCarrera()const { return carrera; }
	Kardex GetKardex()const { return kardex; }
	string ToString()const;

};

