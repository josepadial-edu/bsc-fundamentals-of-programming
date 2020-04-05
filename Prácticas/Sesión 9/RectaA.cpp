/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 16/11/2016
	Sesión 9 Ejercicio 23
		
	Se desea implementar una clase Recta para representar una recta en el plano. 
	Una recta viene determinada portres coe?cientesA, B, C,deformaquetodoslospuntos (x,y) que pertenecen a la recta veri?can lo siguiente 
	(ecuación general de la recta):
		Ax + By + C = 0
	a) De?nición de la clase y creación de objetos De?na la clase Recta. En este apartado utilice únicamente datos miembro públicos. 
	Cree un programa principal que haga lo siguiente: 
		• De?na dos objetos de la clase Recta. 
		• Lea seis reales desde teclado. 
		• Le asigne los tres primeros a los coe?cientes de una recta y los otros tres a la segunda recta. 
		• Calcule e imprima la pendiente de cada recta aplicando la fórmula: pendiente = - A / B 
*/

#include <iostream>
using namespace std;

class Recta{
	public:
		double A = 0.0;
		double B = 0.0;
		double C = 0.0; 
};

int main(){
	double coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta, 
          coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta;
   double pendiente_primera_recta, pendiente_segunda_recta;
   
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
   
   primera_recta.A = coef_x_primera_recta;
   primera_recta.B = coef_y_primera_recta;
   primera_recta.C = coef_indep_primera_recta;
   
   segunda_recta.A = coef_x_segunda_recta;
   segunda_recta.B = coef_y_segunda_recta;
   segunda_recta.C = coef_indep_segunda_recta;
      
   pendiente_primera_recta = - primera_recta.A / primera_recta.B;
   pendiente_segunda_recta = - segunda_recta.A / segunda_recta.B;
   
   cout << "\n\nPendiente de la recta 1: " << pendiente_primera_recta;
   cout << "\n\nPendiente de la recta 2: " << pendiente_segunda_recta;
   
   cout << "\n\n";
   system ("pause");
}

