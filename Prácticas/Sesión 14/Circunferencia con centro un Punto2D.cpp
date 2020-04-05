/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 14 Ejercicio 15
 
 Descripción:
Recupere la solución del ejercicio 2 de esta
relación de problemas (Circunferencia)
Cámbielo para representar el centro de la circunferencia con un objeto de la clase
Punto2D. 
*/

#include <cmath>  // NAN
#include <iostream>
using namespace std;

const double PI = 3.1415927;

struct CoordenadasPunto2D{
   double abscisa;
   double ordenada;
};


class SegmentoDirigido{
private:
   double x_1 = NAN,
          y_1 = NAN,
          x_2 = NAN,
          y_2 = NAN;

   bool SonCorrectos(double origen_abscisa, double origen_ordenada,
                     double final_abscisa,  double final_ordenada){

      return !(origen_abscisa == final_abscisa
               &&
               origen_ordenada == final_ordenada);
   }

public:
   SegmentoDirigido(double origen_abscisa, double origen_ordenada,
                    double final_abscisa, double final_ordenada){

      SetCoordenadas(origen_abscisa, origen_ordenada,
                     final_abscisa, final_ordenada);
   }

   void SetCoordenadas(double origen_abscisa, double origen_ordenada,
                       double final_abscisa,  double final_ordenada){
      if (SonCorrectos(origen_abscisa, origen_ordenada,
                       final_abscisa, final_ordenada)){
         x_1 = origen_abscisa;
         y_1 = origen_ordenada;
         x_2 = final_abscisa;
         y_2 = final_ordenada;
      }
   }

   double OrigenAbscisa(){
      return x_1;
   }

   double OrigenOrdenada(){
      return y_1;
   }

   double FinalAbscisa(){
      return x_2;
   }

   double FinalOrdenada(){
      return y_2;
   }

   double Longitud(){
      double diferencia_abscisas, diferencia_ordenadas;

      diferencia_abscisas = x_2 - x_1;
      diferencia_ordenadas = y_2 - y_1;

      return sqrt(diferencia_abscisas * diferencia_abscisas
                  +
                  diferencia_ordenadas * diferencia_ordenadas);
   }

   void TrasladaHorizontal(double unidades){
      x_1 = x_1 + unidades;
      x_2 = x_2 + unidades;
   }

   void TrasladaVertical(double unidades){
      y_1 = y_1 + unidades;
      y_2 = y_2 + unidades;
   }

   void Traslada(double und_horizontal, double und_vertical){
      TrasladaHorizontal(und_horizontal);
      TrasladaVertical(und_vertical);
   }
};


class Circunferencia{
private:
   CoordenadasPunto2D centro = {NAN, NAN};
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
   
   Circunferencia(CoordenadasPunto2D centro_circunferencia,
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

   bool Contiene(CoordenadasPunto2D un_punto){
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
      SegmentoDirigido segmento_radio(centro.abscisa, centro.ordenada,
                                      centro.abscisa + radio, centro.ordenada);

      return segmento_radio;
   }
};


int main(){
   CoordenadasPunto2D centro_circunf, punto;
   double radio;
   double longitud, area;
   bool esta_dentro;

   cout << "Circunferencia\n\n";
   cout << "Introduzca las coordenadas del centro y la longitud del radio:\n";   
   cin >> centro_circunf.abscisa;
   cin >> centro_circunf.ordenada;
   cin >> radio;
   
   cout << "\nIntroduzca las coordenadas de otro punto:\n";
   cin >> punto.abscisa;
   cin >> punto.ordenada;
      
   Circunferencia circunf(centro_circunf, radio);

   SegmentoDirigido segmento_radio(circunf.SegmentoRadio());

   longitud    = circunf.Longitud();
   area        = circunf.Area();
   esta_dentro = circunf.Contiene(punto);

   cout << "\n\nLongitud: " << longitud;
   cout << "\nÁrea:       " << area;
   cout << "\nLongitud Radio " << radio << " = " << segmento_radio.Longitud();
   
   if (esta_dentro)
      cout << "\nEl punto está dentro";
   else
      cout << "\nEl punto no está dentro";
}

