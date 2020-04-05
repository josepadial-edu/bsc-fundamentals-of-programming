/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 02/11/2016
	Sesi�n 7 Ejercicio 48
		
	Recupere la soluci�n del ejercicio 10 (funci�n gaussiana) de la relaci�n de problemas
	I. Se pide crear un men� principal para que el usuario pueda elegir las siguientes
	opciones:
	Introducir par�metros de la funci�n (esperanza y desviaci�n)
	Salir del programa
	Si el usuario elige la opci�n de salir, el programa terminar�; si elige la opci�n de introducir
	los par�metros, el programa leer� los dos par�metros (esperanza y desviaci�n).
	La media puede ser un valor cualquiera, pero la desviaci�n ha de ser un n�mero positivo.
	A continuaci�n, el programa presentar� un men� con las siguientes opciones:
	Introducir rango de valores de abscisas
	Volver al men� anterior (el men� principal)
	Si el usuario elige volver al men� anterior, el programa debe presentar el primer men�
	(el de la introducci�n de los par�metros) Si el usuario elige introducir los valores de
	abscisas, el programa le pedir� un valor minimo, un valor maximo (ha de ser mayor
	que minimo) y un incremento y mostrar� el valor de la funci�n gaussiana en todos
	los valores de x (la abscisa) entre minimo y maximo a saltos de incremento,
	es decir, minimo, minimo + incremento, minimo + 2*incremento,    , hasta
	llegar, como mucho, a maximo. Despu�s de mostrar los valores de la funci�n, el
	programa volver� al men� de introducci�n del rango de valores de abscisas.
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
	cout << "\nIntroduzca 1 para introducir la esperanza y la desviaci�n";
	cout << "\nIntroduzca 2 para salir del programa";
	cout << "\nElecci�n: ";
	cin >> caso1;
	
	while(caso1 == 1){
		cout << "Introduzca la esperanza: ";
		cin >> esperanza;
		
		do{
			cout << "Introduzca la desviaci�n t�pica: ";
			cin >> desviacion_tipica;
		}while(desviacion_tipica < 0);
		
		cout << "\n\t///////////// MENU //////////////";
		cout << "\nIntroduzca 1 para introducir los valores del rango de X";
		cout << "\nIntroduzca 2 para salir al menu anterior";
		cout << "\nElecci�n: ";
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
			
			//Realizamos los c�lculos y la salida de datos a la vez
			for(double i = x_min; i<=x_max; i = i+incremento){	
				valor_X = (1/(desviacion_tipica*sqrt(2*pi)))*exp(-0.5*pow((i-esperanza)/desviacion_tipica,2));
				cout << "\nEl valor que toma la funci�n en x= " << i << ": " << valor_X;
			}
			
			cout << "\n\t///////////// MENU //////////////";
			cout << "\nIntroduzca 1 para introducir los valores del rango de X";
			cout << "\nIntroduzca 2 para salir al menu anterior";
			cout << "\nElecci�n: ";
			cin >> caso2;
		}
		cout << "\n\t///////////// MENU //////////////";
		cout << "\nIntroduzca 1 para introducir la esperanza y la desviaci�n";
		cout << "\nIntroduzca 2 para salir del programa";
		cout << "\nElecci�n: ";
		cin >> caso1;
	}
	
	cout << "\n\n\tAdios :)";
	
	cout << "\n\n";
	system("pause");
}
