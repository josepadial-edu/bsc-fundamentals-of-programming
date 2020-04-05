/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 19/10/2016
	Sesión 5 Ejercicio 23
*/

/*
Los estudios poblacionales utilizan los conceptos de tasa de natalidad, 
mortalidad, etc. 
Al igual que un porcentaje representa una razón del total por cada cien 
(tanto por ciento), la tasa es una razón del total por cada mil 
(tanto por mil). 
Así pues una tasa de natalidad de 32, por ejemplo, significa que hay 
32 nacimientos por cada 1000 habitantes.

Escriba un programa que calcule la estimación de la población de un 
territorio después de tres años. Para ello, el programa debe leer 
la población inicial, la tasa de natalidad, la de mortalidad y 
la tasa de migración. Ésta última es la diferencia entre los que se
van y los que vienen, por lo que puede ser o bien positiva o bien negativa.

Suponga que todos los datos son enteros.

Tenga en cuenta que una vez calculada la población que habrá el
siguiente año, las tasas se vuelven a aplicar sobre la población
así obtenida, y así sucesivamente, tantos años como estemos interesados.

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
   cout << "Cálculo de la población futura.";
   do{
   	cout << "\n\nIntroduzca la población actual: ";
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
	   cout << "\nIntroduzca la tasa de migración: ";
	   cin  >> tasa_migracion;
	}while(0>tasa_migracion && 1000<tasa_migracion);
	
	cout << "\nIntroduzca el numero de años: ";
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
   cout << "\nPoblación futura, pasados " << anios << " años: " << poblacion_futura;
   cout << "\nDeben de pasar " << contador << " para que la población supere o iguale al doble";
   cout << "\nPoblación futura, pasados " << contador << " años: " << poblacion_doble;
}
