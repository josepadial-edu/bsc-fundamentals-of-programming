/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 7 Ejercicio 47
	
	Entrada: Valor T
	Computos: Calcula el factorial de T
	Salida: Valor del factorial de T
*/

#include<iostream>
using namespace std;

int main(){
	//Vamos a declarar las variables
	int numero_T, factorial=1, suma=0;
	int i;
	
	//Vamos a realizar la entrada de datos
	cout << "Introduzca un numero entero: ";
	cin >> numero_T;

	//Realizamos los cálculos
	for(i=1; i<=numero_T; ++i){
		factorial *= i;
		suma += factorial;
	}
	
	if(numero_T==0)
		suma=1;
	
	//Salida de datos
	cout << "El valor de la suma de factoriales es: " << suma;
}
