/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 02/11/2016
	Sesi�n 7 Ejercicio 3
	
	En las transparencias de clase se ha visto la funci�n Max3 que calculaba el m�ximo
	de tres valores enteros.
	Defina ahora la funci�n Max que calcule el m�ximo de dos valores enteros y cambie
	la implementaci�n de Max3 para que llame a la funci�n Max.
	Construya un programa principal que llame a Max3 con tres valores le�dos desde
	teclado.
*/

#include<iostream>
using namespace std;

int Max(int numero1, int numero2){
	int max;
	
	if(numero1 < numero2)
		max = numero2;
	else
		max = numero1;
	
	return max;
}

int Max3(int numero1, int numero2, int numero3){
	int max;
	
	max = Max(numero1, numero2);
	max = Max(max, numero3);
	
	return max;
}

int main(){
	int numero_1, numero_2, numero_3, mayor;
	
	cout << "\nIntroduzca un numero entero: ";
	cin >> numero_1;
	cout << "\nIntroduzca un numero entero: ";
	cin >> numero_2;
	cout << "\nIntroduzca un numero entero: ";
	cin >> numero_3;
	
	mayor = Max3(numero_1, numero_2, numero_3);
	
	cout << "\nEl mayor de los tres enteros es: " << mayor;
	cout << "\n\n";
	system("pause");
}
