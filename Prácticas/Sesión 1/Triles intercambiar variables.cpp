/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha:
	Sesión 1 Ejercicio 7
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double caja_izda, caja_dcha, auxiliar;
	
	//Asignamos valores a las variables
	cout << "Introduzca el valor de la caja de la izquierda: ";
	cin >> caja_izda;
	
	cout << "\nIntroduzca el valor de la caja de la derecha: ";
	cin >> caja_dcha;
	
	//Realizamos las operaciones
	auxiliar = caja_dcha;
	caja_dcha = caja_izda;
	caja_izda = auxiliar;
	
	cout << "\nEl valor de la caja de la izquierda sera: " << caja_izda;
	cout << "\nEl valor de la caja de la derecha sera: " << caja_dcha;
}

/*caja_izda = caja_dcha;
  caja_dcha = caja_izda;
  Este código no sería correcto, porque al hacer la primera asignación el valor de ambas variables pasa a ser el mismo, perdiendo el valor
  de caja_izda, con lo cual en la segunda asignación no estamos haciendo nada porque los valores son los mismo. Con lo cual no intercambian
  sus valores con este código, una solución es crear una variable auxiliar.*/
