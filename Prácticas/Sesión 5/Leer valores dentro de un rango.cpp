/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 19/10/2016
	Sesión 5 Ejercicio 23
*/

#include <iostream>

using namespace std;

int main(){
	
   // Declarion de variables
   int min, max;
   int nuevo, i = 0;
    
   // Entrada de datos
   do{
   	cout << "Introduce un minimo: ";
      cin >> min;
      cout << "Introduce un maximo: ";
      cin >> max;
   }while(min < 0 || max <= min);
    
   //Realizamos los computos
	// i ---> cuenta las veces que pasamos por el bucle, en este caso seran los fallos
   do{
      i++;
      cout << "Introduce un valor dentro del intervalo [" << min << "," << max << "]: ";
      cin >> nuevo;
   }while((nuevo < min || nuevo > max) && i < 3);
    
   int por_debajo = nuevo - min;
   int por_encima = nuevo - max;
   
	//Salida de datos 
   if (i > 2)
      cout << "Superado ='(" << endl;
   else
      cout << "Enhorabuena: " << por_debajo << " " << por_encima << endl;
}
