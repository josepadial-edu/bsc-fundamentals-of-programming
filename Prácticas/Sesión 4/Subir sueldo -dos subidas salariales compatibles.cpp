/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 12/10/2016
	Sesión 4 Ejercicio 6
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double salario_hora, satisfaccion, paga_final, paga;
	int horas, casos;
	int const minimo_casos = 30;
	double const minimo_satisfaccion = 4.0;
	
	cout << "Introduzca las horas: ";
	cin >> horas;
	
	cout << "\nIntroduzca el salario por horas: ";
	cin >> salario_hora;
	
	cout << "\nIntroduzca los casos: ";
	cin >> casos;
	
	cout << "\nIntroduzca la satisfacción: ";
	cin >> satisfaccion;
	
	// Vamos a hacer los cálculos
	
	paga = salario_hora * horas;
	
	if(casos > minimo_casos){
		paga_final = paga * 1.04;
	}
	
	if(satisfaccion >= minimo_satisfaccion){
		paga_final = paga * 1.06;
	}
	
	// Vamos a realizar la salida de datos
	
	cout << "\nLa paga seria: " << paga_final;
}
