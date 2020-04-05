/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 16/11/2016
	Sesión 9 Ejercicio 23
		
	Se desea implementar una clase Recta para representar una recta en el plano. 
	Una recta viene determinada portres coe?cientesA, B, C,deformaquetodoslospuntos (x,y) que pertenecen a la recta veri?can lo siguiente 
	(ecuación general de la recta):
		Ax + By + C = 0
	c) Datos miembro privados
		Cambie ahora los datos miembro públicos y póngalos privados. Tendrá que añadir
		métodos para asignar y ver los valores de los datos miembro. Añada métodos
		para asignar un valor a cada uno de los tres datos miembro. Modifique el main
		para tener en cuenta estos cambios.
*/

#include<iostream>
using namespace std;

class Recta{
	private:
		double A = 0.0;
		double B = 0.0;
		double C = 0.0;
	public:
		double Pendiente(){
			return -A/B;
		}
		double Ordenada_en(double x){
			return (-C - x*A)/B;
		}
		double Abscisa_en(double y){
			return (-C -y*B)/A;
		}
		double Coef_X(){
			return A;
		}
		double Coef_Y(){
			return B;
		}
		double Coef_indep(){
			return C;
		}
		void SetCoefX(double coef_x){
	   	A = coef_x;
		}
		void SetCoefY(double coef_y){
		   B = coef_y;
		}
		void SetCoefIndep(double coef_indep){
		   C = coef_indep;
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
   
   primera_recta.SetCoefX(coef_x_primera_recta);
   primera_recta.SetCoefY(coef_y_primera_recta);
   primera_recta.SetCoefIndep(coef_indep_primera_recta);
   
   segunda_recta.SetCoefX(coef_x_segunda_recta);
   segunda_recta.SetCoefY(coef_y_segunda_recta);
   segunda_recta.SetCoefIndep(coef_indep_segunda_recta);
      
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
