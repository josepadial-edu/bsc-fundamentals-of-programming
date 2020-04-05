/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha:
	Sesión 1 Ejercicio 4
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double salario_base, salario_final;
	
	//Asignamos valores a las variables
	cout << "Introduzca el salario base: ";
	cin >> salario_base;
	
	//Realizamos las operaciones
	salario_final = salario_base * 1.02;
	
	cout << "\nEl salario base incrementado un 2%: " << salario_final;
}

/*Hemos elegido la opción B, porque así no modificamnos la variable original, por 
	si nos hiciera falta más adelante. Y no realizamos cálculos en la salida de datos.*/
