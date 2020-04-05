/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 02/11/2016
	Sesi�n 8 Ejercicio 10
		
	Retome la soluci�n del ejercicio 23 (poblaci�n) de la Relaci�n de Problemas II. Reescr�balo
	usando las funciones LeeIntRango del ejercicio 4 para leer los valores
	de las tasas y LeeIntMayorIgualQue del ejercicio 5 para leer el n�mero de a�os
	que sea positivo. Defina tambi�n sendas funciones para calcular los dos valores que
	se piden en el ejercicio, a saber, el n�mero de habitantes despu�s de tres a�os y
	el n�mero de a�os que pasar�n hasta doblar la poblaci�n inicial. Intente dise�ar las
	funciones para que sean lo m�s generales posible.
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
   
   cout << "C�lculo de la poblaci�n futura.\n";
   
	do{
      cout << "\nIntroduzca la poblaci�n actual: ";
      cin  >> poblacion_actual;
   }while (poblacion_actual < 0);
   
   tasa_natalidad = LeeIntRango(0, LIMITE_SUPERIOR_TASA,"\nIntroduzca la tasa de natalidad: ");
	tasa_mortalidad = LeeIntRango(0, LIMITE_SUPERIOR_TASA, "\nIntroduzca la tasa de mortalidad: ");
	tasa_migracion = LeeIntRango(-LIMITE_SUPERIOR_TASA, LIMITE_SUPERIOR_TASA, "\nIntroduzca la tasa de migraci�n: ");
	numero_anios = LeeIntMayorIgualQue(0, "\nIntroduzca el n�mero de a�os: ");
   
   tasa_global = tasa_natalidad - tasa_mortalidad + tasa_migracion;
   IV_tasa_global = 1 + tasa_global / 1000.0;
   poblacion_futura = poblacion_actual;
   anio = 1;
   
   while (anio <= numero_anios){
       poblacion_futura = poblacion_futura * IV_tasa_global;
       anio++;
   }

   cout << "\n\nPoblaci�n futura pasados " << numero_anios << " a�os: "
        << poblacion_futura;
   
   long long poblacion_objetivo = 2 * poblacion_actual;

   poblacion_futura = poblacion_actual;
   numero_anios = 0;
   
   while (poblacion_futura < poblacion_objetivo){
      poblacion_futura = poblacion_futura * IV_tasa_global;
      numero_anios++;
   }

   cout << "\n\nPasar�n " << numero_anios << " a�os hasta llegar,"
        << "como m�nimo, al doble de la poblaci�n actual"
        << "\nLa poblaci�n a la que se llegar� es: "
        << poblacion_futura << " habitantes";
}
