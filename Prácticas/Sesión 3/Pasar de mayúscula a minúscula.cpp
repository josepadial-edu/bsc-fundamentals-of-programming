/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 05/10/2016
	Sesi�n 3 Ejercicio 25
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	char caracter, caracter_minus;
	const int DISTANCIA_MAY_MIN = 'a'-'A';
	
	//Asignamos valores a las variables
	cout << "Introduzca el caracter: ";
	cin >> caracter;

	//Realizamos las operaciones
	caracter_minus = caracter + DISTANCIA_MAY_MIN;
	
	cout << "\nEl caracter en mayuscula es: " << caracter_minus;
}
