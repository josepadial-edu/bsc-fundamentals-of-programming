/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha:
	Sesi�n 1 Ejercicio 3
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double radio, longcircun, areacircun;
	double pi = 3.1415927; //Como es una variable que su valor no varia la dejo declarada
	
	//Vamos a recibir los datos
	cout << "Introduzca el valor del radio: ";
	cin >> radio;
	
	//Realizamos los c�lculos
	longcircun = 2*pi*radio;
	areacircun = pi*radio*radio;
	
	//Vamos a devolver los datos
	cout << "\nLa longitud de la circunferencia es: " << longcircun;
	cout << "\nEl �rea de la circunferencia es: " << areacircun;
}
