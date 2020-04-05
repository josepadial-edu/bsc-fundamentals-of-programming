/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 13 Ejercicio 12
 
 Descripción:
 
Un polígono regular de n caras tiene n lados de
la misma longitud y todos los ángulos interiores son iguales. Su centro geométrico es
el centro de la circunferencia circunscrita (la que lo envuelve). Supondremos que dos
polígonos son distintos si se diferencian o bien en sus centros geométricos, o bien en
el número de lados o bien en la longitud de cualquiera de ellos. Así pues, por ejemplo,
no tendremos en cuenta las distintas posiciones en el plano que se podrían obtener
girando el polígono sobre su centro.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI = 3.1415927;

bool SonIguales(double uno, double otro)
{
	return (abs(uno-otro) <= 1e-5);
}

class Punto2D{
private:
   double abscisa  = 0.0;
   double ordenada = 0.0;
public:
   Punto2D(double abscisaPunto, double ordenadaPunto)
   {
      SetCoordenadas(abscisaPunto, ordenadaPunto);
   }
   
   double Abscisa(){
      return abscisa;
   }
   
   double Ordenada(){
      return ordenada;
   }
   
   void SetCoordenadas(double abscisaPunto, double ordenadaPunto){
      if (! SonIguales(abscisaPunto, ordenadaPunto)){
         abscisa = abscisaPunto;
         ordenada = ordenadaPunto;
      }
   }
   
   bool EsIgual_a (Punto2D otro_punto){
      return (SonIguales(abscisa, otro_punto.abscisa)
              &&
              SonIguales(ordenada, otro_punto.ordenada));
   }
   
   string ToString(){
		return "(" + to_string(abscisa) + " , " + to_string(ordenada) + ")";
	}
};




class PoligonoRegular{
private:
	Punto2D centro;          // Centro de la circunferencia circunscrita que envuelve al polígono.
	int 	  num_lados;       // Número de lados del polígono
	double  longitud;        // Longitud de cada lado
	
	double NuevaLongitudLado (int factor_multiplicativo){
		int nuevo_numero_lados;
		
		nuevo_numero_lados = factor_multiplicativo * num_lados;

		return Radio() * sqrt(2 * (1 - cos(2*PI / nuevo_numero_lados)));
	}
	
	bool EsCorrecto(int num_lados, double longitud){
	  return 0 < num_lados && 0 < longitud; 
   }

public:
   PoligonoRegular (Punto2D centro_poligono,
                    int num_lados_poligono, 
                    double longitud_lado_poligono 
                    )
		:centro (centro_poligono)
	{
      if (EsCorrecto(num_lados_poligono, longitud_lado_poligono))
         num_lados = num_lados_poligono;
         longitud = longitud_lado_poligono;
   }
   
	PoligonoRegular (int num_lados_poligono, double longitud_lado_poligono)
		: PoligonoRegular (Punto2D(0.0,0.0), num_lados_poligono, longitud_lado_poligono)
	{ } 
   
	PoligonoRegular() 
      :PoligonoRegular (3 , 1)
	{ }


	Punto2D Centro(){
		return centro;	
	}

	double Longitud(){
		return longitud;	
	}
	
	int NumLados(){
		return num_lados;	
	}
	
	double Radio(){
		return longitud / (2.0 * sin(PI / num_lados));	
	}

	double Perimetro(){
		return longitud * num_lados;	
	}
	
	double Area(){
		double radio;
      
      radio = Radio();
		return 0.5 * num_lados * radio * radio * sin(2*PI / num_lados);					
	}

	bool EsMayorQue(PoligonoRegular otro){
		return Area() > otro.Area();
	}
	
	PoligonoRegular Multiplica (int factor_multiplicativo){
		PoligonoRegular nuevo (centro,
                             num_lados * factor_multiplicativo, 
                             NuevaLongitudLado(factor_multiplicativo));
		return nuevo;
	}
	
	double Ajuste(){
	   double radio = Radio();
	   
	   return PI * radio * radio - Area();
   }
	
};

int main (){
	PoligonoRegular poligono1;
	PoligonoRegular poligono2 (6, 4);
	
	if (poligono1.EsMayorQue(poligono2))
		cout << "El area de poligono1 es mayor que la de poligono2";
	else 
		cout << "El area de poligono2 es mayor que la de poligono1";		

   PoligonoRegular poligono_doble (poligono1.Multiplica(2));
   
   cout << "\n\nÁrea del polígono con doble número de lados: " 
        << poligono_doble.Area();
	
	while (! SonIguales(0.0 , poligono_doble.Ajuste())) {
		poligono_doble = poligono_doble.Multiplica(2);
	}

	cout << "\n\nEl polígono envolvente tiene " 
	     << poligono_doble.NumLados() << " lados\n\n";
}

