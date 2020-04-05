/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 26/10/2016
	Sesión 6 Ejercicio 30
	
	Entrada: Valor entero
	Computos: Separa dígitos del entero
	Salida: Digitos separados
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	//Vamos a declarar las variables
	int numero, numero_copia, num_digitos, potencia, digito;
	bool es_negativo;
	
	//Vamos a hacer la entrada de datos
	cout << "Introduzca un numero entero: ";
	cin >> numero;
	
	//Vamos a hacer los computos
	es_negativo = numero <0;
	numero_copia = abs(numero);
	num_digitos = 1;
	potencia = 1;
	
	while (numero_copia > 9){
      numero_copia = numero_copia / 10;
      num_digitos++;
      potencia = potencia * 10;
   }

   numero_copia = abs(numero);  
   
   if (es_negativo)           
      cout << "- ";
	
	while (potencia >= 1){
	   digito = numero_copia / potencia;
	   cout << digito << " ";
	   numero_copia = numero_copia % potencia;
	   potencia = potencia / 10;
   }
	
	//Vamos a hacer la salida de datos
}
