/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 12/10/2016
	Sesi�n 4 Ejercicio 5
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double salario_hora, satisfaccion, paga;
	int horas, casos;
	int const minimo = 30;
	
	cout << "Introduzca las horas: ";
	cin >> horas;
	
	cout << "\nIntroduzca el salario por horas: ";
	cin >> salario_hora;
	
	cout << "\nIntroduzca los casos: ";
	cin >> casos;
	
	cout << "\nIntroduzca la satisfacci�n: ";
	cin >> satisfaccion;
	
	// Vamos a hacer los c�lculos
	
	paga = salario_hora * horas;
	
	if(casos > minimo){
		paga = paga * 1.04;
	}
	
	// Vamos a realizar la salida de datos
	
	cout << "\nLa paga seria: " << paga;
}
