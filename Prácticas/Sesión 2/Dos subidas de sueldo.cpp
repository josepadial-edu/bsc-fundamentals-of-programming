/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 28/09/2016
	Sesión 2 Ejercicio 9
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double salario_base, salario_2, salario_3;
	
	//Vamos a recibir los datos
	cout << "Introduzca el salario base: ";
	cin >> salario_base;
	
	//Realizamos los cálculos
	salario_2 = salario_base * 1.02;
	salario_3 = salario_2 * 1.03;
	
	//Vamos a devolver los datos
	cout << "\nEl salario base incrementado un 2%: " << salario_2;
	cout << "\nEl salario base incrementado un 3%: " << salario_3;
}
