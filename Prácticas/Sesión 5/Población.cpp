/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 19/10/2016
	Sesi�n 5 Ejercicio 23
*/

/*
Los estudios poblacionales utilizan los conceptos de tasa de natalidad, 
mortalidad, etc. 
Al igual que un porcentaje representa una raz�n del total por cada cien 
(tanto por ciento), la tasa es una raz�n del total por cada mil 
(tanto por mil). 
As� pues una tasa de natalidad de 32, por ejemplo, significa que hay 
32 nacimientos por cada 1000 habitantes.

Escriba un programa que calcule la estimaci�n de la poblaci�n de un 
territorio despu�s de tres a�os. Para ello, el programa debe leer 
la poblaci�n inicial, la tasa de natalidad, la de mortalidad y 
la tasa de migraci�n. �sta �ltima es la diferencia entre los que se
van y los que vienen, por lo que puede ser o bien positiva o bien negativa.

Suponga que todos los datos son enteros.

Tenga en cuenta que una vez calculada la poblaci�n que habr� el
siguiente a�o, las tasas se vuelven a aplicar sobre la poblaci�n
as� obtenida, y as� sucesivamente, tantos a�os como estemos interesados.

Ejemplo de entrada: 1375570814 32 12 7  -- Salida correcta: 1490027497
Ejemplo de entrada: 30000 41 30 9  -- Salida correcta: 31836
*/

#include <iostream>  
#include <cmath>

using namespace std; 

int main(){                   
   
   //Vamos a declarar las variables
   long long poblacion_actual, poblacion_futura, poblacion_doble, poblacion_conseguir;
   int tasa_natalidad, tasa_mortalidad, tasa_migracion, tasa_global, anios, contador=0;
   double indice_variacion_tasa_global;
   
   //Vamos a realizar la entrada de datos
   cout << "C�lculo de la poblaci�n futura.";
   do{
   	cout << "\n\nIntroduzca la poblaci�n actual: ";
   	cin  >> poblacion_actual;
   }while(poblacion_actual < 0);
   do{
	   cout << "\nIntroduzca la tasa de natalidad: ";
	   cin  >> tasa_natalidad;
	}while(0>tasa_natalidad && 1000<tasa_natalidad);
	do{
	   cout << "\nIntroduzca la tasa de mortalidad: ";
	   cin  >> tasa_mortalidad;
	}while(0>tasa_mortalidad && 1000<tasa_mortalidad);
	do{
	   cout << "\nIntroduzca la tasa de migraci�n: ";
	   cin  >> tasa_migracion;
	}while(0>tasa_migracion && 1000<tasa_migracion);
	
	cout << "\nIntroduzca el numero de a�os: ";
	cin >> anios;
 
	//Vamos a realizar los computos
	tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
   indice_variacion_tasa_global = 1 + tasa_global / 1000.0;
   poblacion_futura = poblacion_actual * pow(indice_variacion_tasa_global, anios);
	
   poblacion_doble = poblacion_actual;
   poblacion_conseguir = poblacion_actual*2;
	while(poblacion_doble < poblacion_conseguir){
		tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
   	indice_variacion_tasa_global = 1 + tasa_global / 1000.0;
  		poblacion_doble = poblacion_doble * pow(indice_variacion_tasa_global, contador);
  		
  		contador++;
	}
   
	//Vamos a realiar la salida de datos                                          
   cout << "\nPoblaci�n futura, pasados " << anios << " a�os: " << poblacion_futura;
   cout << "\nDeben de pasar " << contador << " para que la poblaci�n supere o iguale al doble";
   cout << "\nPoblaci�n futura, pasados " << contador << " a�os: " << poblacion_doble;
}
