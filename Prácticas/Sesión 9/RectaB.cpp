/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 16/11/2016
	Sesión 9 Ejercicio 23
		
	Se desea implementar una clase Recta para representar una recta en el plano. 
	Una recta viene determinada portres coe?cientesA, B, C,deformaquetodoslospuntos (x,y) que pertenecen a la recta veri?can lo siguiente 
	(ecuación general de la recta):
		Ax + By + C = 0
	b) Métodos públicos En vez de calcular la pendiente en el programa principal, 
	vamos a ponerlo como un método de la clase y así lo reutilizaremos todas las veces que necesitemos. 
	Añada un método para el cálculo de la pendiente y modi?que el main para tener en cuenta este cambio. 
	¿Añadimos pendiente como dato miembro de la recta? La respuesta es que no ¿Por qué? Añada también los siguiente métodos: 
		• Obtener la ordenada (y) dado un valor de abscisa x, aplicando la fórmula: (-C -xA) / B 
		• Obtener la abscisa (x) dado un valor de ordenada y, aplicando la fórmula: (-C -yB) / A 
	En la función main lea un valor de abscisa e imprima la ordenada según la recta. 
	A continuación lea un valor de ordenada e imprima la abscisa que le corresponde. Hágalo sólo con la primera recta. 
*/

#include<iostream>
using namespace std;

class Recta{
	public:
		double A = 0.0;
		double B = 0.0;
		double C = 0.0;
		
		double Pendiente(){
			return -A/B;
		}
		double Ordenada_en(double x){
			return (-C - x*A)/B;
		}
		double Abscisa_en(double y){
			return (-C -y*B)/A;
		}
};

int main(){
	double coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta, 
          coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta;
   double pendiente_primera_recta, pendiente_segunda_recta;
   double x, ordenada_de_x, y, abscisa_de_y;
   
	Recta primera_recta;
   Recta segunda_recta;
   
   cout << "Introduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_primera_recta;
   cin >> coef_y_primera_recta;
   cin >> coef_indep_primera_recta;
   cout << "\nIntroduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_segunda_recta;
   cin >> coef_y_segunda_recta;
   cin >> coef_indep_segunda_recta;
   cout << "\nIntroduzca un valor de abscisa\n";
   cin >> x;
   cout << "\nIntroduzca un valor de ordenada\n";
   cin >> y;
   
   primera_recta.A = coef_x_primera_recta;
   primera_recta.B = coef_y_primera_recta;
   primera_recta.C = coef_indep_primera_recta;
   
   segunda_recta.A = coef_x_segunda_recta;
   segunda_recta.B = coef_y_segunda_recta;
   segunda_recta.C = coef_indep_segunda_recta;
      
   pendiente_primera_recta = primera_recta.Pendiente();
   pendiente_segunda_recta = segunda_recta.Pendiente();      
   
   ordenada_de_x = primera_recta.Ordenada_en(x);
   abscisa_de_y  = primera_recta.Abscisa_en(y);
   
   cout << "\n\nPendiente de la recta 1: " << pendiente_primera_recta;
   cout << "\n\nPendiente de la recta 2: " << pendiente_segunda_recta;
   cout << "\n\nOrdenada de la recta 1 en " << x << " = " << ordenada_de_x;
   cout << "\n\nAbscisa  de la recta 1 en " << y << " = " << abscisa_de_y;
   
   cout << "\n\n";
   system ("pause");
}
