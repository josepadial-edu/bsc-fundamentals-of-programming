/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 05/10/2016
	Sesión 3 Ejercicio 27
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	char letra;
	int edad, adivine, anio;
	bool es_minuscula, fuera_rango, es_adivine, es_bisiesto;
	
	cout << "\nIntroduzca una letra: ";
   cin >> letra;
   
   es_minuscula = (letra >= 'a') && (letra <= 'z');
   
   cout << "\n" << es_minuscula << "\n";
   
   cout << "\nIntroduzca la edad: ";
   cin >> edad;   
   
   fuera_rango = (edad > 65) || (edad < 18);
   
   cout << "\n" << fuera_rango << "\n";
   
   cout << "\nIntroduzca el numero: ";
   cin >> adivine;   
   
   es_adivine = (1 <= adivine) && (adivine <= 100);
   
   cout << "\n" << es_adivine << "\n";

	cout << "\nIntroduzca un año: ";
	cin >> anio;
	es_bisiesto = ( anio % 4 == 0  &&  anio % 100 != 0 )   ||  anio % 400 == 0 ;
	
	cout << "\n" << es_bisiesto << "\n";

   cout << "\n\n";
}
