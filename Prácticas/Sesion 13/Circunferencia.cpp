/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 13 Ejercicio 2
 
 Descripción:
 
Circunferencia, defina el método SegmentoRadio para que devuelva un objeto
de la clase SegmentoDirigido con el segmento correspondiente al radio de la
circunferencia.
Cree un programa principal que lea el centro (dos datos de tipo double) y la longitud
del radio (un dato de tipo double), construya una circunferencia con estos
datos y a partir de ella, construya el segmento correspondiente al radio. Calcule
ahora la longitud del segmento radio a través del método Longitud de la clase
SegmentoDirigido y muestre el resultado en pantalla (debe coincidir con la longitud
original del radio).
*/

#include <cmath>  // NAN
#include <iostream>
using namespace std;

const double PI = 3.1415927;

struct Punto2D{
	double abscisa;
	double ordenada;
};

class SegmentoDirigido{
	private:
		Punto2D origen;
		Punto2D final;
	public:
		// Constructor SegmentoDirigido con parámetros de tipo double
		SegmentoDirigido(Punto2D punto_origen, Punto2D punto_final)
			:origen (punto_origen), // llamada al constructor de copia del punto
			 final (punto_final) // llamada al constructor de copia del punto
		{
		}
		
		Punto2D Origen(){
			return origen;
		}
		
		Punto2D Final(){
			return final;
		}
		
		double Longitud(){
			double sumando_abscisa = origen.abscisa-final.abscisa;
			double sumando_ordenada = origen.ordenada-final.ordenada;
			return sqrt(sumando_abscisa * sumando_abscisa + sumando_ordenada * sumando_ordenada);
		}
};

class Circunferencia{
private:
	Punto2D centro = {NAN, NAN};
	double radio = NAN;
	
	bool EsCorrectoRadio(double long_radio){
	   return long_radio >= 0;
	}
public:
   // Hemos decidido que, una vez establecidos el centro y el radio
   // en el constructor, luego ya no pueden modificarse, por lo que
   // no proporcionamos ningún método del tipo SetRadio o SetCentro
   
   // Si los valores pasados en el constructor no son correctos
   // los datos miembro se quedarán con NAN, indicativo de que
   // ha habido un error.
   
	Circunferencia(Punto2D centro_circunferencia, 
                  double longitud_radio)
   {
      if (EsCorrectoRadio(longitud_radio)){
         centro = centro_circunferencia;
         radio  = longitud_radio;
      }
	}
	
	double Longitud(){
		return 2*PI*radio;
	}
	
	double Area(){
		return PI*radio*radio;
	}
	
	bool Contiene(Punto2D un_punto){
		double diferencia_abscisas, diferencia_ordenadas;
		bool contiene;

		diferencia_abscisas = centro.abscisa - un_punto.abscisa;
		diferencia_ordenadas = centro.ordenada - un_punto.ordenada;

		contiene = diferencia_abscisas*diferencia_abscisas 
                 + 
                 diferencia_ordenadas*diferencia_ordenadas 
                 <= 
                 radio * radio; 
              
      return contiene;
	}

	SegmentoDirigido SegmentoRadio(){
		Punto2D extremo = {centro.abscisa + radio, centro.ordenada + radio}; 
		SegmentoDirigido longitud(centro, extremo); 

		return longitud;
	}
};


int main(){
	Punto2D centro_circunf;
	double radio;
	double longitud, area;
	bool esta_dentro;

   cout << "Circunferencia\n\n";
   cout << "Introduzca las coordenadas del centro y la longitud del radio:\n";   
   cin >> centro_circunf.abscisa;
   cin >> centro_circunf.ordenada;
   cin >> radio;
      
	Circunferencia circunf(centro_circunf, radio);
	
	longitud    = circunf.Longitud();
	area        = circunf.Area();

   cout << "\n\nLongitud: " << longitud;
   cout << "\nÁrea:       " << area;

   cout << "\nLa longitud del segmento es " << circunf.SegmentoRadio().Longitud();
}

