/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 19/10/2016
	Sesión 5 Ejercicio 11
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double salario_hora, satisfaccion, paga_final, salario_inicial;
	int horas, casos;
	int const max_casos = 30;
	int const minimo_casos = 20;
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
	
	paga_final = salario_hora * horas;
   salario_inicial = paga_final;
	
	if(casos > max_casos){
		paga_final = salario_inicial * 1.04;
	
		if(satisfaccion >= minimo_satisfaccion){
			paga_final = salario_inicial * 1.06;
		}
	}
	
	if((casos <= max_casos) && (casos >= minimo_casos)){
		paga_final = salario_inicial * 1.03;
	
		if(satisfaccion >= minimo_satisfaccion){
			paga_final = salario_inicial * 1.05;
		}
	}
	
	if(casos < minimo_casos)
		if(satisfaccion >= minimo_satisfaccion)
			paga_final = salario_inicial * 1.02;
		
	// Vamos a realizar la salida de datos
	
	cout << "\nLa paga seria: " << paga_final;
}
