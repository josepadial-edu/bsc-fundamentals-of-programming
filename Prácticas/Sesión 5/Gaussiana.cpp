/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 19/10/2016
	Sesión 5 Ejercicio 22
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double esperanza, desviacion_tipica, x_max, x_min, incremento, valor_X;
	double pi = 3.1416;
	
	//Vamos a recibir los datos
	cout << "Introduzca la esperanza: ";
	cin >> esperanza;
	
	do{
		cout << "Introduzca la desviación típica: ";
		cin >> desviacion_tipica;
	}while(desviacion_tipica < 0);
	
	do{
		cout << "Introduzca el valor maximo de X: ";
		cin >> x_max;
		cout << "Introduzca el valor minimo de X: ";
		cin >> x_min;
	}while(x_max < x_min);
	
	cout << "Introduzca el incremento: ";
	cin >> incremento;
	
	//Realizamos los cálculos y la salida de datos a la vez
	for(double i = x_min; i<=x_max; i = i+incremento){	
		valor_X = (1/(desviacion_tipica*sqrt(2*pi)))*exp(-0.5*pow((i-esperanza)/desviacion_tipica,2));
		cout << "\nEl valor que toma la función en x= " << i << ": " << valor_X;
	}
}
