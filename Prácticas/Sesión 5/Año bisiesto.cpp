/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 19/10/2016
	Sesi�n 5 Ejercicio 14
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	int anio;
	bool bisiesto = false;
	
	cout << "Introduzca un entero: ";
	cin >> anio;
	
	// Vamos a hacer los c�lculos
	
	if(( anio % 4 == 0  &&  anio % 100 != 0 )   ||  anio % 400 == 0){
		bisiesto = true;
	}
	
	// Vamos a realizar la salida de datos
	
	cout << "\nEs bisiesto: " << bisiesto;
}
