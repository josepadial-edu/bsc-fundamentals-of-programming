/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha:
	Sesión 1 Ejercicio 5
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
	
	cout << "\nEl capital pasado un año sera: " << total;
}

/*Se podría tanto asignar el valor del capital pasado un año a una nueva variable o a la misma, dependiendo de la situación.
  Si el valor del capital no se utiliza en otra parte del código sería indiferente la opción a elegir. Pero un programas de 
  código más extenso es normal que se utilice la misma variable varias veces o que no queramos perder el valor inicial, con lo
  cual necesitamos una variable nueva.*/
