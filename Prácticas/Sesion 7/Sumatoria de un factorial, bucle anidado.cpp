/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 02/11/2016
	Sesi�n 7 Ejercicio 46
	
	Entrada: Valor T
	Computos: Calcula el factorial de T
	Salida: Valor del factorial de T
*/

#include <iostream>
using namespace std;

int main(){
    long factorial, suma_factoriales = 0;
    int num;
    
    // Lectura de datos
    do {
        cout << "Introduzca un numero: ";
        cin >> num;
    } while (num < 0);
    
    // Cálculos
    if (num == 0)
        suma_factoriales = 1;
    
    else {
        for (int i = 1; i <= num; i++) {
            factorial = 1;
            
            for (int j = 1; j <= i; j++)
                factorial *= j;
            
            suma_factoriales += factorial;
        }
    }
    
    cout << "Factorial: " << factorial << endl;
    cout << "Suma de factoriales: " << suma_factoriales << endl;
    
    return (0);
}
