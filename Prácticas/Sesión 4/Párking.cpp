/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 12/10/2016
	Sesión 4 Ejercicio 10
*/

#include<iostream>
using namespace std;

int main(){
	
	// Vamos a declarar las variables
	int hora_inicial, min_inicial, seg_inicial, total_seg_inicial;
	int hora_final, min_final, seg_final, total_seg_final;
	int diferencia;
	double a_pagar;
	
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
	
	if(total_seg_final > total_seg_inicial){
		if((diferencia > 660*60) && (diferencia <= 24*60*60)){
			a_pagar = 31.55;
		}
		
		if((diferencia >= 0) && (diferencia <= 30*60)){
			a_pagar = diferencia/60 * 0.0412;
		}
		
		if((diferencia >= 31*60) && (diferencia <= 90*60)){
			a_pagar = ((diferencia-30*60)/60 * 0.0370) + 30 * 0.0412;
		}
		
		if((diferencia >= 91*60) && (diferencia <= 120*60)){
			a_pagar = ((diferencia-90*60)/60 * 0.0311) + 60 * 0.0370 + 30 * 0.0412;
		}
		
		if((diferencia >= 121*60) && (diferencia <= 660*60)){
			a_pagar = ((diferencia-120*60)/60 * 0.0305) + 30* 0.0311 + 60 * 0.0370 + 30 * 0.0412;
		}
	}
	
	else
		a_pagar = -1;
	
	//Vamos a devolver los datos
	cout << "\nEl total a pagar es: " << a_pagar;
}
