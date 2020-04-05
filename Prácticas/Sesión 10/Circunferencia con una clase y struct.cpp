/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 16/11/2016
	Sesión 10 Ejercicio 48
	
	Recupere la definición del registro CoordenadasPunto2D del ejercicio 47 de esta
	relación de problemas y la solución al ejercicio 3 (Circunferencia) de la relación de
	problemas I.
	Cree ahora una clase llamada Circunferencia. Para establecer el centro, se usará
	un dato miembro que ha de ser de tipo CoordenadasPunto2D.
	Añada métodos para obtener la longitud de la circunferencia y el área del círculo interior.
	Añada también un método para saber si la circunferencia contiene a un punto cualquiera.
	Recordemos que un punto (x1; y1) está dentro de una circunferencia con centro
	(x0; y0) y radio r si se verifica que:
	(x0 .. x1)2 + (y0 .. y1)2 <= r2
	Observe que el valor de  debe ser constante, y el mismo para todos los objetos de
	la clase Circunferencia.
	Cree un programa principal que lea el centro y el radio de una circunferencia, las
	coordenadas de un punto y muestre en pantalla la longitud de la circunferencia, el
	área del círculo y nos diga si el punto está dentro o no de la circunferencia.
	Ejemplo de entrada: 2.1 3.2 5.8 2.2 4.6
	.... Salida correcta: 36.4425 105.683 El punto está dentro
	Ejemplo de entrada: 2.1 3.2 5.8 2.2 10.36
	.... Salida correcta: 36.4425 105.683 El punto no está dentro
*/

#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.1415927;

class Circunferencia{
	private:
		struct CoordenadasPunto2D{
	   	double abscisa;
	   	double ordenada;
		};
		double radio = 0.0;
		CoordenadasPunto2D cordenada;
	public:
		Circunferencia(double radio_circun, double x_ini, double y_ini){
			radio = radio_circun;
			cordenada.ordenada = x_ini;
			cordenada.abscisa = y_ini;
		}
		double Longitud(){
			return 2 * PI  * radio;
		}
		
		double Area(){
			return PI * radio * radio;
		}
		
		bool PuntoDentroCriecunferencia(double x,double y){
			bool esta = false;
			
			if(sqrt(pow((cordenada.ordenada-x),2)+pow((cordenada.abscisa-y),2)) <= radio)
				esta = true;
				
			return esta;
		}
};

int main(){
	double x0, y0, x1, y1, radio;
	bool dentro;
	double area, longitud;
	
	cout << "Introduzca el centro de la circunferencia" << "\nX: ";
	cin >> x0;
	cout << "\ny: ";
	cin >> y0;
	cout << "\nIntroduzca el radio: ";
	cin >> radio;
	
	Circunferencia circunferencia(radio, x0, y0);
	area = circunferencia.Area();
	longitud = circunferencia.Longitud();
	
	cout << "Introduzca un punto" << "\nX: ";
	cin >> x1;
	cout << "\ny: ";
	cin >> y1;
	
	dentro = circunferencia.PuntoDentroCriecunferencia(x1, y1);
	
	cout << "\n\tArea: " << area << "\n\tLongitud: " << longitud << "\n\tEsta el punto dentro: " << dentro;
}
