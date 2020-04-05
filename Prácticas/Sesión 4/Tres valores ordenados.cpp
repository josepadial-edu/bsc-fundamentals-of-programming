/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 12/10/2016
	Sesión 4 Ejercicio 7
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	int entero1, entero2, entero3;
	bool ordenado = false;
	
	cout << "Introduzca un entero: ";
	cin >> entero1;
	
	cout << "Introduzca un entero: ";
	cin >> entero2;
	
	cout << "Introduzca un entero: ";
	cin >> entero3;

	
	// Vamos a hacer los cálculos
	
	if((entero1 < entero2) && (entero2 < entero3)){
		ordenado = true;
	}
	
	if((entero3 < entero2) && (entero2 < entero1)){
		ordenado = true;
	}
	
	// Vamos a realizar la salida de datos
	
	cout << "\nEsta ordenado: " << ordenado;
}
