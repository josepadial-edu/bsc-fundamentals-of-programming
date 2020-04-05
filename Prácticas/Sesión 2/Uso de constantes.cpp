/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 28/09/2016
	Sesión 2 Ejercicio 11
*/

/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 28/09/2016
	Sesión 1 Ejercicio 3
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double radio, longcircun, areacircun;
	const double pi = 3.1415927; //Como es una variable que su valor no varia la dejo declarada
	
	//Vamos a recibir los datos
	cout << "Introduzca el valor del radio: ";
	cin >> radio;
	
	//Realizamos los cálculos
	longcircun = 2*pi*radio;
	areacircun = pi*radio*radio;
	
	//Vamos a devolver los datos
	cout << "\nLa longitud de la circunferencia es: " << longcircun;
	cout << "\nEl área de la circunferencia es: " << areacircun;
}



/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 28/09/2016
	Sesión 2 Ejercicio 9
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double salario_base;
	double salario_2, salario_3
	
	//Vamos a recibir los datos
	cout << "Introduzca el salario base: ";
	cin >> salario_base;
	
	//Realizamos los cálculos
	salario_2 = salario_base * 1.02;
	salario_3 = salario_2 * 1.03;
	
	//Vamos a devolver los datos
	cout << "\nEl salario base incrementado un 2%: " << salario_2;
	cout << "\nEl salario base incrementado un 3%: " << salario_3;
}



/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 28/09/2016
	Sesión 1 Ejercicio 6
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	int hora_inicial, min_inicial, seg_inicial;
	int hora_final, min_final, seg_final;
	int diferencia, total_seg_inicial, total_seg_final;
	
	//Vamos a recibir los datos
	cout << "Introduzca la hora inicial: ";
	cin >> hora_inicial;
	
	cout << "Introduzca los minutos iniciales: ";
	cin >> min_inicial;
	
	cout << "Introduzca los segundos iniciales: ";
	cin >> seg_inicial;
	
		cout << "Introduzca la hora final: ";
	cin >> hora_final;
	
	cout << "Introduzca los minutos finales: ";
	cin >> min_final;
	
	cout << "Introduzca los segundos finales: ";
	cin >> seg_final;
	
	//Realizamos los cálculos
	total_seg_inicial = seg_inicial + min_inicial * 60 + hora_inicial * 60 *60;
	total_seg_final = seg_final + min_final * 60 + hora_final * 60 * 60;
	
	diferencia = total_seg_final - total_seg_inicial;
	
	//Vamos a devolver los datos
	cout << "\nLa diferencia de segundos es: " << diferencia;
}



/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 28/09/2016
	Sesión 2 Ejercicio 10
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double esperanza, desviacion_tipica, valor_abscisa, valor_X;
	const double pi = 3.1416;
	
	//Vamos a recibir los datos
	cout << "Introduzca la esperanza: ";
	cin >> esperanza;
	
	cout << "Introduzca la desviación típica: ";
	cin >> desviacion_tipica;
	
	cout << "Introduzca el valor de abscisa: ";
	cin >> valor_abscisa;
	
	//Realizamos los cálculos
	valor_X = (1/(desviacion_tipica*sqrt(2*pi)))*exp(-0.5*pow((valor_abscisa-esperanza)/desviacion_tipica,2));
	
	//Vamos a devolver los datos
	cout << "\nEl valor que toma la función en x : " << valor_X;
}
