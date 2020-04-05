/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 8 Ejercicio 10
		
	Retome la solución del ejercicio 23 (población) de la Relación de Problemas II. Reescríbalo
	usando las funciones LeeIntRango del ejercicio 4 para leer los valores
	de las tasas y LeeIntMayorIgualQue del ejercicio 5 para leer el número de años
	que sea positivo. Defina también sendas funciones para calcular los dos valores que
	se piden en el ejercicio, a saber, el número de habitantes después de tres años y
	el número de años que pasarán hasta doblar la población inicial. Intente diseñar las
	funciones para que sean lo más generales posible.
*/


#include <iostream>  
using namespace std; 

int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}

int LeeIntMayorIgualQue(int minimo, string mensaje){
   int a_leer;

   do{
      cout << mensaje;
      cin >> a_leer;
   }while (minimo > a_leer);

   return a_leer;
}


int main(){
   const int LIMITE_SUPERIOR_TASA = 1000;
   long long poblacion_actual, poblacion_futura;
   int tasa_natalidad, tasa_mortalidad, tasa_migracion, tasa_global,
       numero_anios, anio;
   double IV_tasa_global;
   
   cout << "Cálculo de la población futura.\n";
   
	do{
      cout << "\nIntroduzca la población actual: ";
      cin  >> poblacion_actual;
   }while (poblacion_actual < 0);
   
   tasa_natalidad = LeeIntRango(0, LIMITE_SUPERIOR_TASA,"\nIntroduzca la tasa de natalidad: ");
	tasa_mortalidad = LeeIntRango(0, LIMITE_SUPERIOR_TASA, "\nIntroduzca la tasa de mortalidad: ");
	tasa_migracion = LeeIntRango(-LIMITE_SUPERIOR_TASA, LIMITE_SUPERIOR_TASA, "\nIntroduzca la tasa de migración: ");
	numero_anios = LeeIntMayorIgualQue(0, "\nIntroduzca el número de años: ");
   
   tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
   IV_tasa_global = 1 + tasa_global / 1000.0;
   poblacion_futura = poblacion_actual;
   anio = 1;
   
   while (anio <= numero_anios){
       poblacion_futura = poblacion_futura * IV_tasa_global;
       anio++;
   }

   cout << "\n\nPoblación futura pasados " << numero_anios << " años: "
        << poblacion_futura;
   
   long long poblacion_objetivo = 2 * poblacion_actual;

   poblacion_futura = poblacion_actual;
   numero_anios = 0;
   
   while (poblacion_futura < poblacion_objetivo){
      poblacion_futura = poblacion_futura * IV_tasa_global;
      numero_anios++;
   }

   cout << "\n\nPasarán " << numero_anios << " años hasta llegar,"
        << "como mínimo, al doble de la población actual"
        << "\nLa población a la que se llegará es: "
        << poblacion_futura << " habitantes";
}
