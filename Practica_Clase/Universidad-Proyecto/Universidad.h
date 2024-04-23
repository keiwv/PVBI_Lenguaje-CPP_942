#pragma once
#include<string>
#include<map>
#include"Estudiante.h"
#include"Materia.h"
using std::string;
using std::map;
class Universidad
{
protected:
	string nombre;
	map<int, Estudiante*> estudiantes;
	map<int, Materia*> materias;
	int cont_mat = 333000;//Variable de control de matriculas
	int cont_cm = 40000; //Varuiable para claves de materia
public:
	Universidad(string nom = "WABECE") { nombre = nom; }
	string GetNombre() { return nombre; }
	Estudiante *RegistrarEstudiante(string nombre, string carrera);
	Materia* RegistrarMateria(string nombre, int creditos,
		bool obligatoria = true, Materia::Etapa etapa = Materia::BASICA);
	void RegistrarCalificacion(int matricula, int clave, int valor);
	void ReporteEstudiantes()const;
};

