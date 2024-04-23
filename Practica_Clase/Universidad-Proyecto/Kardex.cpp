#include "Kardex.h"
#include<sstream>
#include<iomanip>
using std::setw;
using std::left;
using std::right;
using std::endl;

void Kardex::RegistrarCalificacion(Calificacion calif)
{
	calificaciones.push_back(calif);
	//actualizamos los creditos y el promedio
	if (calif.GetValor() >= 60)
		creditos += calif.GetMateria()->GetCreditos();
	//Calculamos el promedio
	double sc = 0;
	/*sc = promedio * (calificaciones.size() - 1);
	sc += calif.GetValor();*/
	for (Calificacion& cal : calificaciones)
		sc += cal.GetValor();
	promedio = sc / calificaciones.size();
}

string Kardex::ToString() const
{
	std::ostringstream out;
	/*Necesitamos imprimir informacion del estudiante.
	La asociacion estudiante-kardex debe ser bidireccional.
	No tenemos la clase estudiante, dejamos esta parte
	pendiente
	*/
	//Imprimimos las calificaciones
	//Primero un encabezado
	out << "-------------------------------------------------------------------------------" << endl;
	out << "Clave  ";
	out << setw(50) << "Nombre";
	out << " Valor Creditos" << endl;
	out << "-------------------------------------------------------------------------------" << endl;
	for (Calificacion cal : calificaciones)
		out << cal.ToString() << endl;
	out << "-------------------------------------------------------------------------------" << endl;
	out << "\nPromedio: " << std::setprecision(2) << promedio<<endl;
	out << "Creditos: " << creditos<<endl;
	return out.str();
}
