/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 26/10/2016
	Sesi�n 6 Ejercicio 31
	
	Entrada: Dos variables (n, m)
	Computos: Calcular la multiplicaci�n de n*m
	Salida: Suma
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	//Vamos a declarar las variables
	int n = 0, m = 0, suma = 0, TERMINADOR = 1, n_dividido = 0;
	int contador = 0;
	
	//Vamos a realizar la entrada de datos
	cout << "Introzca el primer valor: ";
	cin >> n;
	cout << "Introduzca el segundo valor: ";
	cin >> m;
	
	//Vamos a realizar los c�lculos
	n_dividido = n;
	if(n_dividido%2 != 0)
		suma = suma + m*pow(2,contador);
		
	do{
		n_dividido = n_dividido/2;
		++contador;
		if(n_dividido%2 != 0)
			suma = suma + m*pow(2,contador);
	}while(n_dividido != TERMINADOR);
	
	//Vamos a realizar la salida de datos
	cout << "La multiplicaci�n de n*m vale: " << suma;
}
