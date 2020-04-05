/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 26/10/2016
	Sesión 6 Ejercicio 28
	
	Entrada: salario_hora, codigo de empleado, segundos, resueto, satisfacción
	Computos: media del empleado con mayor satisfación; los casos introducidos
	Salida: media, casos
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	double salario_hora, satisfaccion;
	double satisfaccion1 = 0, satisfaccion2 = 0, satisfaccion3 = 0;
	double satisfaccion_media1 = 0, satisfaccion_media2 = 0, satisfaccion_media3 = 0;
	int casos1 = 0, casos2 = 0, casos3 = 0;
	int segundos, casos = 0, codigo;
	bool se_resolvio;
	const int TERMINADOR = -1;
	
	// Vamos a hacer los cálculos y las entradas de datos
	cout << "\nIntroduzca el salario por horas: ";
	cin >> salario_hora;
	
	cout << "\nIntroduzca los datos: ";
	cin >> codigo;
	
	if(codigo == TERMINADOR)
		cout << "No hay datos :'(";
	else{
		while(codigo != TERMINADOR){
			cin >> segundos;
			cin >> se_resolvio;
			cin >> satisfaccion;
			++casos;
			
			if(codigo == 1){
				++casos1;
				satisfaccion_media1 = (satisfaccion+satisfaccion_media1)/casos1;
				if(satisfaccion > satisfaccion1)
					satisfaccion1 = satisfaccion;
			}
			else if (codigo == 2){
				++casos2;
				satisfaccion_media2 = (satisfaccion+satisfaccion_media2)/casos2;
				if(satisfaccion > satisfaccion2)
					satisfaccion2 = satisfaccion;
			}
			else if(codigo == 3){
				++casos3;
				satisfaccion_media3 = (satisfaccion+satisfaccion_media3)/casos3;
				if(satisfaccion > satisfaccion3)
					satisfaccion3 = satisfaccion;
			}
			cin >> codigo;
		}
	
		//Vamos a realizar la salida de datos
		cout << "El nuero de casos introducidos son: " << casos;
		
		if(satisfaccion_media1 > satisfaccion_media2 && satisfaccion_media1 > satisfaccion_media3)
			cout << "\nEmpleado numero 1 con grado medio: " << satisfaccion_media1;
		else if(satisfaccion_media2 > satisfaccion_media1 && satisfaccion_media2 > satisfaccion_media3)
			cout << "\nEmpleado numero 2 con grado medio: " << satisfaccion_media2;
		else if(satisfaccion_media3 > satisfaccion_media1 && satisfaccion_media3 > satisfaccion_media2)
			cout << "\nEmpleado numero 3 con grado medio: " << satisfaccion_media3;
	}
}
