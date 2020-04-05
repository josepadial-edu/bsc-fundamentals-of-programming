/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 16/11/2016
	Sesión 9 Ejercicio 23
		
	Se desea implementar una clase Recta para representar una recta en el plano. 
	Una recta viene determinada portres coe?cientesA, B, C,deformaquetodoslospuntos (x,y) que pertenecen a la recta veri?can lo siguiente 
	(ecuación general de la recta):
		Ax + By + C = 0
	f )Política de acceso a los datos miembro
		Suprima ahora el método SetCoeficientes. De esta forma, una vez creado
		el objeto (pasándole los datos apropiados en el constructor) ya no podremos
		modificar los datos miembro. Esto es útil en aquellas situaciones en las que no
		queremos permitir que el estado del objeto cambie, una vez se ha creado.
*/

#include<iostream>
using namespace std;

class Recta{
	private:
		double A = 0.0;
		double B = 0.0;
		double C = 0.0;
	public:
		Recta(double coef_x, double coef_y, double coef_indep){
			A = coef_x;
      	B = coef_y;
      	C = coef_indep;
		}
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
};

int main(){
	double coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta, 
          coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta;
   double pendiente_primera_recta, pendiente_segunda_recta;
   double x, ordenada_de_x, y, abscisa_de_y;
   
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
   
   Recta primera_recta(coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta);
   Recta segunda_recta(coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta);
      
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
