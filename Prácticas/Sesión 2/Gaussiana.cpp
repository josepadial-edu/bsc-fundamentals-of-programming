/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 28/09/2016
	Sesión 2 Ejercicio 10
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double esperanza, desviacion_tipica, valor_abscisa, valor_X;
	double pi = 3.1416;
	
	//Vamos a recibir los datos
	cout << "Introduzca la esperanza: ";
	cin >> esperanza;
	
	cout << "Introduzca la desviación típica: ";
	cin >> desviacion_tipica;
	
	cout << "Introduzca el valor de abscisa: ";
	cin >> valor_abscisa;
	
	//Realizamos los cálculos
	valor_X = (1/(desviacion_tipica*sqrt(2*pi)))*exp(-0.5*pow((valor_abscisa-esperanza)/desviacion_tipica,2));
	
	//Vamos a devolver los datos
	cout << "\nEl valor que toma la función en x : " << valor_X;
}
