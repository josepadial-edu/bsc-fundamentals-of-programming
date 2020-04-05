/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 11 Ejercicio 3
 
 Descripción:
 
Se quiere calcular la moda de un vector de caracteres, es decir, el carácter
que más veces se repite. Por ejemplo, si el vector fuese
{'l','o','s',' ','d','o','s',' ','c','o','f','r','e','s'}
los caracteres que más se repiten son 'o' y 's' con un total de 3 apariciones. La
moda sería cualquiera de ellos, por ejemplo, el primero encontrado 'o'.
Para almacenar de forma conjunta el carácter y la frecuencia usaremos el siguiente
	struct:
	struct FrecuenciaCaracter{
		char caracter;
		int frecuencia;
	}
El campo caracter contendrá el carácter en cuestión ('o') y en el campo
frecuencia el conteo de la moda (3).
Construya un programa que lea caracteres con cin.get() (repase lo visto al inicio
de esta relación de problemas) hasta que el usuario introduzca el carácter #. Almacene
todos los valores en un vector de caracteres. A continuación, calcule la moda y
muéstrela en pantalla junto con su frecuencia.
Para calcular la moda, se recomienda que use un vector auxiliar en el que almacene
los caracteres que ya se han procesado en algún momento anterior.
*/

#include <iostream>

using namespace std;

// Estructura de una frecuancia de caracteres
struct FrecuenciaDeCaracteres{
	char caracter;
	int frecuencia;

	FrecuenciaDeCaracteres(){
		caracter = 0;
		frecuencia = 0;
	}
};

int main(){
   const int MAX = ('Z' - 'A') * 2; // Tanto para mayus como minus
	string texto;
   
   FrecuenciaDeCaracteres caracteres[MAX];
   int pos = 0;
   
   char letras_usadas[MAX];
   int indice_usadas = 0;
   bool buscar = false;

	getline(cin, texto, '#'); // Guardo el texto
	
	for(int i = 0; i < MAX; i++){
		letras_usadas[i] = 0;
	}
    
	for(int i = 0; i < texto.size(); i++){
      buscar = false;
		if((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z')){
			for(int j = 0; j < indice_usadas; j++){
				if(caracteres[j].caracter == texto[i])
					buscar = true;
			}
			if(buscar == true){
				for(int z = 0; z < indice_usadas; z++){
					if(caracteres[z].caracter == texto[i]){
						pos = z;
					}		
				}
				if(pos >= 0)
					caracteres[pos].frecuencia++;
			}
			else{
				letras_usadas[indice_usadas] = texto[i];
				caracteres[indice_usadas].caracter = texto[i];
				caracteres[indice_usadas].frecuencia++;
				indice_usadas++;
			}
		}
	}

	int actual;
	int mayor = caracteres[0].frecuencia;
	int pos_mayor = 0;
    
	for(int i = 0; i < indice_usadas - 1; i++){
		actual = caracteres[i].frecuencia;
		for(int j = i+1; j < indice_usadas; j++){
			if(actual >= caracteres[j].frecuencia && actual >= mayor){
				mayor = actual;
				pos_mayor = i;
			}	
		}
	}
	
	cout << "La letra que mas aparece es la ---> " << caracteres[pos_mayor].caracter << endl;
	cout << "Su frecuencia de aparicion es ------> " << caracteres[pos_mayor].frecuencia << endl;
	return 0;
}

