/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 7 Ejercicio 46
	
	Entrada: Valor T
	Computos: Calcula el factorial de T
	Salida: Valor del factorial de T
*/

#include <iostream>
using namespace std;

int LeerIntRango(){
    const int MIN = 1, MAX = 20;
    int x;
    do{
        cout << "Introduce un numero entre [" << MIN << "," << MAX << "]: ";
        cin >> x;
    }while(x < MIN || x > MAX);
    return x;
}

long Factorial(int x){
    long factorial = 1;
    for(int i = 2; i <= x; i++)
        factorial *= i;
    return factorial;
}

// Este seria el metodo de resolucion del ejercicio 46 de la sesion 7
/*
long SumaFactoriales(int x){
    long suma = 0;
    long factorial = 1;
    for (int i = 1; i <= x; i++) {
        factorial = 1;
        for (int j = 1; j <= i; j++)
            factorial *= j;
        suma += factorial;
    }
    return suma;
}
*/
long SumaFactoriales(int x){
    long suma = 0;
    for(int i = 1; i <= x; i++)
        suma += Factorial(i);
    return suma;
}

int main(){
    long factorial, suma_factoriales = 0;
    int x = LeerIntRango();
    
    factorial = Factorial(x);
    suma_factoriales = SumaFactoriales(x);
    
    // Salida
    cout << "Factorial: " << factorial << endl;
    cout << "Suma de factoriales: " << suma_factoriales << endl;
    
    return (0);
}
