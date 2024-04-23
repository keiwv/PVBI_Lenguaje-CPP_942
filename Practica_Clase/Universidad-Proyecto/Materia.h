#pragma once
#include<string>
using std::string;
class Materia
{
public:
	enum Etapa {
		BASICA,DISCIPLINARIA,TERMINAL
	};
protected:
	int clave;
	string nombre;
	int creditos;
	bool obligatoria;
	Etapa etapa;
public:
	Materia(int clave = 0, string nombre = "",
		int creditos = 0, bool obligatoria = false,
		Etapa etapa = BASICA);
	//Getters
	int GetClave()const { return clave; }
	string GetNombre()const { return nombre; }
	int GetCreditos()const { return creditos; }
	bool GetObligatoria()const { return obligatoria; }
	Etapa GetEtapa()const { return etapa; }
	string ToString()const;
};

