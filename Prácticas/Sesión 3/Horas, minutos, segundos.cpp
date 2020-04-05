/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 05/10/2016
	Sesión 3 Ejercicio 23
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	int segundos_enteros, minutos_enteros, horas_enteras;
   int minutos_totales, horas_totales, dias_totales;
   int segundos, minutos, horas;
   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60, HORAS_POR_DIA = 24;
	
	//Vamos a recibir los datos
	cout << "Introduzca las horas: ";
	cin >> horas;
	
	cout << "Introduzca los minutos: ";
	cin >> minutos;
	
	cout << "Introduzca los segundos: ";
	cin >> segundos;
	
	//Realizamos los cálculos
	minutos_totales  = segundos / SEGUNDOS_POR_MINUTO  +  minutos;
   horas_totales    = minutos_totales / MINUTOS_POR_HORA  +  horas;
   dias_totales     = horas_totales / HORAS_POR_DIA; 

	segundos_enteros = segundos % SEGUNDOS_POR_MINUTO;
   minutos_enteros  = minutos_totales % MINUTOS_POR_HORA;
   horas_enteras    = horas_totales % HORAS_POR_DIA;

	//Vamos a devolver los datos
	cout << "\nLdatos dentro de su rango es: " << dias_totales << " dias " << horas_enteras << " horas " <<
																minutos_enteros << " minutos " << segundos_enteros << " segundos ";
}
