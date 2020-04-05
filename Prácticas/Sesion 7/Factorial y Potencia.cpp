/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 7 Ejercicio 2
	
	Cómputo del factorial y potencia de un número, con funciones

   Factorial:
      n! = 1 si n=0
      n! = n(n-1)(n-2)...1 si n>=1
   Potencia:

      x^n = x x ... x  (n veces)
*/

#include <iostream>
#include <cmath>
using namespace std;

long long Factorial(int n){
   long long factorial;
	int  multiplicando;

	if (n < 0 || n > 20)
		factorial = -1;
	else{
		factorial = 1;

		for (multiplicando = 2; multiplicando <=n ; multiplicando++)
			factorial = factorial * multiplicando;
	}

	return factorial;
}

double Potencia(double la_base, int el_exponente){
	double potencia;
	int exponente_positivo;

	exponente_positivo = abs(el_exponente);
	potencia = 1;								   					

	for (int i = 1; i <= exponente_positivo; i++)
		potencia = potencia * la_base;


	if (el_exponente < 0)
		potencia = 1/potencia;

	return potencia;
}

int main(){
	//Declaramos las variables de factorial
   long long factorial;
	int n;
	
	//Hacemos la entrada de datos
	cout << "\nIntroduzca un entero positivo: ";
	cin >> n; 
	
	//Realizamos los computos
	factorial = Factorial(n);
	
	//Realizamos la salida de datos
	if (factorial != -1)
		cout << "\nEl factorial de " << n << " es " << factorial;
	else
		cout << "\nNo se puede calcular el factorial de " << n;
		
	////////////////////////////////////////////////////////////////////////////////////////////
	//Declaramos la variables de potencia
	double base;
	int exponente;
	double potencia;

	//Hacemos la entrada de datos
	cout << "\n\nIntroduzca la base: ";
	cin >> base;
	cout << "\nIntroduzca el exponente: ";
	cin >> exponente;

	//Realizamos los computos
	potencia = Potencia(base, exponente);
	
	//Realizamos la salida de datos
	cout << "\n" << base << " elevado a " << exponente << " es igual a " << potencia;
   cout << "\n\n";
	system("pause");
}
