/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 7 Ejercicio 49
	
	Diremos que un número entero positivo es secuenciable si se puede generar como
	suma de números consecutivos (al menos dos). Por ejemplo, 6 = 1+2+3, 15 = 7+8.
	Esta descomposición no tiene por qué ser única. Por ejemplo, 15 = 7+8 = 4+5+6 =
	1+2+3+4+5. Escriba un programa que lea un entero n  1 e imprima todas las
	descomposiciones posibles. En este ejercicio puede mezclar operaciones de E/S y C
	dentro del mismo bucle.
	Como curiosidad, los únicos números con 0 descomposiciones son las potencias de
	2.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int numero;
    bool continuar = true;
    string aux = "";
    string rta = "";
    int suma;
    
    do{
        cout << "Inserte un numero entero positivo: ";
        cin >> numero;
    }while(numero < 0);
    
    for(int i = 1; i < numero; i++){
        suma = 0;
        aux = "";
        continuar = true;
        for(int j = i; j < numero && continuar; j++){
            suma += j;
            aux += to_string(j) + " ";
            if(numero == suma){
                continuar = false;
                rta += aux + "/ ";
            }
        }
    }
    
    cout << rta << endl;
    
    return 0;
}
