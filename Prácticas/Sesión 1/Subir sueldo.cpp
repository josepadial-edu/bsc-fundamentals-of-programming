/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha:
	Sesi�n 1 Ejercicio 4
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

/*Hemos elegido la opci�n B, porque as� no modificamnos la variable original, por 
	si nos hiciera falta m�s adelante. Y no realizamos c�lculos en la salida de datos.*/
