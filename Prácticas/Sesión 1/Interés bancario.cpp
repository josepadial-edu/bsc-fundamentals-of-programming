/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha:
	Sesi�n 1 Ejercicio 5
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double capital, interes, total;
	
	//Asignamos valores a las variables
	cout << "Introduzca el capital: ";
	cin >> capital;
	
	cout << "\nIntroduzca el interes: ";
	cin >> interes;
	
	//Realizamos las operaciones
	total = capital + capital*interes/100;
	
	cout << "\nEl capital pasado un a�o sera: " << total;
}

/*Se podr�a tanto asignar el valor del capital pasado un a�o a una nueva variable o a la misma, dependiendo de la situaci�n.
  Si el valor del capital no se utiliza en otra parte del c�digo ser�a indiferente la opci�n a elegir. Pero un programas de 
  c�digo m�s extenso es normal que se utilice la misma variable varias veces o que no queramos perder el valor inicial, con lo
  cual necesitamos una variable nueva.*/
