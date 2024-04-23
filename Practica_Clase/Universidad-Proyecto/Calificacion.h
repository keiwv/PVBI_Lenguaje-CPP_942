#pragma once
#include"Materia.h"
class Calificacion
{
protected:
	int valor;
	//asociacion con una materia
	Materia *materia;
public:
	Calificacion(int valor = 0, Materia* materia = nullptr);
	//getters
	int GetValor()const { return valor; }
	Materia* GetMateria()const { return materia; }
	string ToString();
};

