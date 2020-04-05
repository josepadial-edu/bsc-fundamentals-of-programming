/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 26/10/2016
	Sesión 6 Ejercicio 29
	
	Entrada: Seceuencia de temperatura y terminador
	Computos: Calcular subsecuencia de numeros ordenada, de menor a mayor
				 y la longitud
	Salida: Donde empieza la subsecuencia
*/

#include<iostream>
using namespace std;

int main(){
	//Vamos a declarar las variables
	const double TERMINADOR = -1.0;
	double temperatura = 0, temperatura_anterior = 0;
	int contador_posicion = 1, contador_long_ant = 0, contador_longitud = 1, contador_posicion_inicial = 1, posicion = 1;
	
	//Vamos a realizar los computos y las entradas
	cout << "TEMPERATURA\n\n";
   cin >> temperatura;

   while (temperatura != TERMINADOR){
      temperatura_anterior = temperatura;
      cin >> temperatura;
		contador_posicion++;               
      
      if (temperatura_anterior < temperatura){
         contador_longitud++;
      }
      else{
         if(contador_longitud >= contador_long_ant){
         	contador_long_ant = contador_longitud;
         	posicion = contador_posicion_inicial;
         	contador_posicion_inicial = contador_posicion;
			}
			contador_longitud = 1;
      }
   }
   
   //Vamos a realizar la salida de datos
   cout << "Dias consecutivos: " << contador_long_ant << " ,desde la posicion: " << posicion << endl;
}
