/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 05/10/2016
	Sesión 3 Ejercicio 24
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	int x, y, z, auxiliar;
	
	//Asignamos valores a las variables
	cout << "Introduzca el valor de z: ";
	cin >> z;
	
	cout << "\nIntroduzca el valor de y: ";
	cin >> y;
	
	cout << "\nIntroduzca el valor de x: ";
	cin >> x;
	
	//Realizamos las operaciones
	auxiliar = x;
	x = z;
	z = y;
	y = auxiliar;
	
	cout << "\nEl valor de z es: " << z;
	cout << "\nEl valor de y es: " << y;
	cout << "\nEl valor de x es: " << x;
}
