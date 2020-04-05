/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 28/09/2016
	Sesión 2 Ejercicio 13
*/


#include <iostream>
using namespace std;

int main()
{
   int numero_3dig;	// Dato de entrada: un entero de tres dígitos
   int numero_2dig;
   int digito_centenas, digito_decenas, digito_unidades;

   // Entrada
   cout << "Introduce un entero de tres dígitos: ";
   cin >> numero_3dig;

   // Cálculos
   digito_centenas = numero_3dig / 100;
   numero_2dig     = numero_3dig % 100;    // Las dos cifras menos significativas
   
   digito_decenas  = numero_2dig / 10;
   digito_unidades = numero_2dig % 10;

   // Salida
   cout << digito_centenas << "   " << digito_decenas << "   "  << digito_unidades << "\n";
}
