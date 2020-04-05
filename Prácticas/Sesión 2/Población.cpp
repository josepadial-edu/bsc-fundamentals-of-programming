/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 28/09/2016
	Sesi�n 2 Ejercicio 12
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	long int poblacion_inicial, tasa_natalidad, tasa_mortalidad, tasa_migracion;
	long int poblacion_futuro;
	long int NACIMIENTOS_POR_ANIO, MUERTES_POR_ANIO, MIGRACIONES_POR_ANIO;
	
	//Vamos a recibir los datos
	cout << "Introduzca la poblaci�n inicial: ";
	cin >> poblacion_inicial;
	
	cout << "Introduzca la tasa de natalidad: ";
	cin >> tasa_natalidad;
	
	cout << "Introduzca la tasa de mortalidad: ";
	cin >> tasa_mortalidad;
	
	cout << "Introduzca la tasa de migraci�n: ";
	cin >> tasa_migracion;
	
	//Realizamos los c�lculos
	
	poblacion_futuro = poblacion_inicial;
	
	for(int i=0; i<3; ++i){
		NACIMIENTOS_POR_ANIO = poblacion_futuro/1000 * tasa_natalidad;
		MUERTES_POR_ANIO = poblacion_futuro/1000 * tasa_mortalidad;
		MIGRACIONES_POR_ANIO = poblacion_futuro/1000 * tasa_migracion;
		
		poblacion_futuro = poblacion_futuro + (NACIMIENTOS_POR_ANIO - MUERTES_POR_ANIO + MIGRACIONES_POR_ANIO);
	}
	
	//Vamos a devolver los datos
	cout << "\nLa poblaci�n pasado tres a�os ser�: " << poblacion_futuro;
}
