/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 7 Ejercicio 48
		
	Recupere la solución del ejercicio 10 (función gaussiana) de la relación de problemas
	I. Se pide crear un menú principal para que el usuario pueda elegir las siguientes
	opciones:
	Introducir parámetros de la función (esperanza y desviación)
	Salir del programa
	Si el usuario elige la opción de salir, el programa terminará; si elige la opción de introducir
	los parámetros, el programa leerá los dos parámetros (esperanza y desviación).
	La media puede ser un valor cualquiera, pero la desviación ha de ser un número positivo.
	A continuación, el programa presentará un menú con las siguientes opciones:
	Introducir rango de valores de abscisas
	Volver al menú anterior (el menú principal)
	Si el usuario elige volver al menú anterior, el programa debe presentar el primer menú
	(el de la introducción de los parámetros) Si el usuario elige introducir los valores de
	abscisas, el programa le pedirá un valor minimo, un valor maximo (ha de ser mayor
	que minimo) y un incremento y mostrará el valor de la función gaussiana en todos
	los valores de x (la abscisa) entre minimo y maximo a saltos de incremento,
	es decir, minimo, minimo + incremento, minimo + 2*incremento,    , hasta
	llegar, como mucho, a maximo. Después de mostrar los valores de la función, el
	programa volverá al menú de introducción del rango de valores de abscisas.
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double esperanza, desviacion_tipica, x_max, x_min, incremento, valor_X;
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
		
		do{
			cout << "Introduzca la desviación típica: ";
			cin >> desviacion_tipica;
		}while(desviacion_tipica < 0);
		
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
				valor_X = (1/(desviacion_tipica*sqrt(2*pi)))*exp(-0.5*pow((i-esperanza)/desviacion_tipica,2));
				cout << "\nEl valor que toma la función en x= " << i << ": " << valor_X;
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
