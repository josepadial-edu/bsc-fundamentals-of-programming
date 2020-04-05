/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 11 Ejercicio 3
 
 Descripción:
 
 [k mayores que otro valor, eficiente]. Modifique la solución del ejercicio 2 usando un
 algoritmo mÃ¡s eficiente. Observe que no hace falta ordenar todo el vector, sino Ãºnicamente
 considerar los datos que son mayores que la referencia.
 Aplique el siguiente algoritmo:
    Recorrer los componentes del vector original
        Si es mayor que la referencia, insertar dicho
        valor de forma ordenada en el vector "mayores_que"
 
        El vector "mayores_que" siempre tendrÃ¡,
        como mucho,k componentes
*/

#include<iostream>
using namespace std;

void OrdenarVector(double* vector, int tamanio){
	double aux; // Variable auxiliar para ordenar un vector
	for(int i = 0; i < tamanio - 1; i++){
		for(int j = i+1; j < tamanio; j++){
			if(vector[i] > vector[j]){
				aux = vector[j];
				vector[j] = vector[i];
				vector[i] = aux;
			}
		}
	}
}

void ImprimeVector(double* vector, int tamanio){
	for(int i = 0; i < tamanio; i++)
		cout << vector[i] << " ";
}

int CopiarVectorConReferencia(double* origen, double* destino, int tamanio_origen, double referencia){
	int tamanio_nuevo = 0;
	for(int i = 0; i < tamanio_origen; i++){
		if(origen[i] >= referencia)
			destino[tamanio_nuevo++] = origen[i];
	}
	OrdenarVector(destino, tamanio_nuevo);
	
	return tamanio_nuevo;
}

int main(){
	const int MAX = 6; // Para un tamanio fijo del vector
   double original[MAX] = {5.2, 2.5, 7.3, 4.2, 3.1, 4.9}; // Vector original
   double nuevo[MAX]; // Vector donde se guardaran los datos a partir de la referencia
   double referencia; // Numero a partir del cual ordenare el vector
   int tamanio_nuevo = 0; // Tamanio utilizado del nuevo vector
   
   cout << "\nIntroduzca el valor de referencia: ";
   cin >> referencia;
   
   tamanio_nuevo = CopiarVectorConReferencia(original, nuevo, MAX, referencia);
   
   cout << "\nEl vector original es: ";
   ImprimeVector(original, MAX);
   
   if(tamanio_nuevo == 0)
   	cout << "\nNo hay valores mayores al de referencia en el vector";
   else{
   	cout << "\nEl vector con los valores mayores a la referencia ordenado es: ";
   	ImprimeVector(nuevo, tamanio_nuevo);
   }
   
   cout << endl;
	system ("pause");
}  
