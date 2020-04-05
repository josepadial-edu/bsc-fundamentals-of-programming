/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 8 Ejercicio 7
		
	Retome la solución del ejercicio 48 (Gaussiana) y modifíquela introduciendo funciones dónde crea conveniente. 
	Al menos debe definir la función gaussiana para que calcule el valor de la ordenada, 
	para unos valores concretos de abscisa, esperanza y desviación.
*/

#include<iostream>
#include<cmath>
using namespace std;

double  Gausiana (double esperanza, double desviacion_tipica, double i){	
		double valor_X;
		const double PI = 3.1416;
		
		valor_X = (1/(desviacion_tipica*sqrt(2*PI)))*exp(-0.5*pow((i-esperanza)/desviacion_tipica,2));
		
		return valor_X;
}

double DesviacionTipica(){
	double desviacion_tipica;
	
	do{
		cout << "Introduzca la desviación típica: ";
		cin >> desviacion_tipica;
	}while(desviacion_tipica < 0);
	
	return desviacion_tipica;
}

double CDF(double x, double valor_X){
    double b0 = 0.2316419,
    b1 = 0.319381530,
    b2 = -0.356563782,
    b3 = 1.781477937,
    b4 = -1.821255978,
    b5 = 1.330274429;
    
    double t = 1/(1+b0*x);
    
    return 1 - valor_X * (b1 * pow(t,1) + b2 * pow(t,2) + b3 * pow(t,3) + b4 * pow(t,4) + b5 * pow(t,5));
}

int main(){
	
	// Vamos a declarar las variables
	double esperanza, desviacion_tipica, x_max, x_min, incremento, valor_X, cdf;
	double pi = 3.1416;
	int caso1, caso2;
	
	//Vamos a recibir los datos
	cout << "\n\t///////////// MENU //////////////";
	cout << "\nIntroduzca 1 para introducir la esperanza y la desviación";
	cout << "\nIntroduzca 2 para salir del programa";
	cout << "\nElección: ";
	cin >> caso1;
	
	while(caso1 == 1){
		cout << "Introduzca la esperanza: ";
		cin >> esperanza;
		
		desviacion_tipica = DesviacionTipica();
		
		cout << "\n\t///////////// MENU //////////////";
		cout << "\nIntroduzca 1 para introducir los valores del rango de X";
		cout << "\nIntroduzca 2 para salir al menu anterior";
		cout << "\nElección: ";
		cin >> caso2;
		
		while(caso2 == 1){
			do{
				cout << "Introduzca el valor maximo de X: ";
				cin >> x_max;
				cout << "Introduzca el valor minimo de X: ";
				cin >> x_min;
			}while(x_max < x_min);
			
			cout << "Introduzca el incremento: ";
			cin >> incremento;
			
			//Realizamos los cálculos y la salida de datos a la vez
			for(double i = x_min; i<=x_max; i = i+incremento){	
				valor_X = Gausiana(esperanza, desviacion_tipica, i);
				cout << "\nEl valor que toma la función en x= " << i << ": " << valor_X;
				cdf = CDF(i, valor_X);
            cout << "\tFuncion CDF(" << i << ") = " << cdf;
			}
			
			cout << "\n\t///////////// MENU //////////////";
			cout << "\nIntroduzca 1 para introducir los valores del rango de X";
			cout << "\nIntroduzca 2 para salir al menu anterior";
			cout << "\nElección: ";
			cin >> caso2;
		}
		cout << "\n\t///////////// MENU //////////////";
		cout << "\nIntroduzca 1 para introducir la esperanza y la desviación";
		cout << "\nIntroduzca 2 para salir del programa";
		cout << "\nElección: ";
		cin >> caso1;
	}
	
	cout << "\n\n\tAdios :)";
	
	cout << "\n\n";
	system("pause");
}
