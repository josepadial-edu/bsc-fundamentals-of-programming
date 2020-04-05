/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 16/11/2016
	Sesión 10 Ejercicio 28
	
	Recupere la solución del ejercicio 10 de esta relación de problemas (población con
	funciones). Re-escríbalo para que los cómputos relacionados con la población estén
	encapsulados en una clase. La lectura de los valores en los rangos adecuados se hará
	con las mismas funciones que ya se definieron en ese ejercicio. Modifique apropiadamente
	el programa principal.
*/

#include <iostream>  
using namespace std; 

const int LIMITE_SUPERIOR_TASA = 1000;

class Poblacion{
	private:
		long long poblacion_act = 0;
		int tasa_nata = 0, tasa_morta = 0, tasa_migra = 0;
	public:
		Poblacion(double poblacion_actual, int tasa_natalidad, int tasa_mortalidad, int tasa_migracion){
			SetCoeficientes(poblacion_actual, tasa_natalidad, tasa_mortalidad, tasa_migracion);
		}
		
		void SetCoeficientes(double poblacion_actual, int tasa_natalidad, int tasa_mortalidad, int tasa_migracion){
			poblacion_act = poblacion_actual;
			tasa_nata = tasa_natalidad; 
			tasa_morta = tasa_mortalidad;
			tasa_migra = tasa_migracion;
		}
};

long long PoblacioActual(){
	long long poblacion_actual;
	
	do{
      cout << "\nIntroduzca la población actual: ";
      cin  >> poblacion_actual;
   }while (poblacion_actual < 0);
   
   return poblacion_actual;
}

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
   long long poblacion_actual, poblacion_futura;
   int tasa_natalidad, tasa_mortalidad, tasa_migracion, tasa_global,
       numero_anios, anio;
   double IV_tasa_global;
   
   cout << "Cálculo de la población futura.\n";
   
	poblacion_actual = PoblacioActual();
   
   tasa_natalidad = LeeIntRango(0, LIMITE_SUPERIOR_TASA,"\nIntroduzca la tasa de natalidad: ");
	tasa_mortalidad = LeeIntRango(0, LIMITE_SUPERIOR_TASA, "\nIntroduzca la tasa de mortalidad: ");
	tasa_migracion = LeeIntRango(-LIMITE_SUPERIOR_TASA, LIMITE_SUPERIOR_TASA, "\nIntroduzca la tasa de migración: ");
	numero_anios = LeeIntMayorIgualQue(0, "\nIntroduzca el número de años: ");
	
	Poblacion poblacion_1(poblacion_actual, tasa_natalidad, tasa_mortalidad, tasa_migracion);
   
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

