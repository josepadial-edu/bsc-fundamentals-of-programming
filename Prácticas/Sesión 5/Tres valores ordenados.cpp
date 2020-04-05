/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 19/10/2016
	Sesión 5 Ejercicio 16
*/

#include<iostream>
using namespace std;

enum class Orden {ascendente, descendente, no_ordenado};

int main(){
	
	// Vamos a declarar las variables
	int entero1, entero2, entero3;
	Orden orden;
	
	cout << "Introduzca un entero: ";
	cin >> entero1;
	
	cout << "Introduzca un entero: ";
	cin >> entero2;
	
	cout << "Introduzca un entero: ";
	cin >> entero3;

	
	// Vamos a hacer los cálculos
	
	if((entero1 < entero2) && (entero2 < entero3)){
		orden = Orden::ascendente;
	}
	
	else if((entero3 < entero2) && (entero2 < entero1)){
		orden = Orden::descendente;
	}
	
	else
		orden = Orden::no_ordenado;
	
	// Vamos a realizar la salida de datos
	
	if (orden == Orden::ascendente)    
      cout << "\nOrdenadod de forma ascendente.";
   else if (orden == Orden::descendente)
      cout << "\nOrdenado de forma descendente.";
   else
      cout << "\nNo está ordenado.";
}
