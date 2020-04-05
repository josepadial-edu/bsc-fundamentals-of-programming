/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 14 Ejercicio 23
 
Se quiere trabajar con una imagen
que se representará como una tabla de datos en el que todas las filas tienen el
mismo número de columnas y los datos son de tipo int. Esta clase se llamará
ImagenBlancoNegro y contendrá valores enteros que representan un nivel de gris
(0 sería negro y 255 blanco).
Para implementar esta clase se recomienda que se use como dato miembro privado
una matriz de enteros. La clase proporcionará, como mínimo, el siguiente constructor
y métodos:
// Constructor en el que se fija el número de filas
// y columnas que contendrá la imagen.
// Inicializa todas las componentes a 0.
ImagenBlancoNegro(int numero_filas, int numero_columnas)
// Devuelve el valor de la casilla (fil, col)
int Pixel(int fil, int col)
// Modifica la casilla (fil,col)
void Modifica(int fil, int col, int nuevo)
Se supone que todos los valores deben ser positivos aunque por problemas de captación
y registro algunos de ellos son negativos. Es preciso corregir estos valores
erróneos y se propone sustituirlos por el valor promedio (la media aritmética truncada
a entero) de sus ocho vecinos más cercanos espacialmente (arriba, abajo, izquierda,
derecha y las cuatro esquinas adyacentes). Este es el método conocido como Mean
Filter for Smoothing .
Debe considerar que entre estos vecinos pudiera haber valores negativos, y en este
caso no intervendrán en el cálculo del valor promedio:
Si hubiera un sólo valor negativo en la vecindad, se sumarán los valores de
los 7 vecinos válidos y la suma se dividirá entre 7. Si hubiera dos valores
negativos en la vecindad, se sumarán los valores de los 6 vecinos válidos y
la suma se dividirá entre 6. . . . Si no hubiera ningún valor válido, se sustituirá
por un cero.
Implemente un método para que dada una imagen, devuelva otra imagen corregida.
La imagen original no se modifica.
Para la implementación debe considerar:
a) El algoritmo debe ser simple y claro.
b) Para simplificar el problema, las casillas de los bordes no se modifican, aunque
sí se usan para efectuar las correcciones oportunas. En definitiva, la primera y
la última fila así como la primera y la última columna son iguales entre la matriz
original y la corregida (por lo que podrían quedar valores negativos en estas
posiciones).
Cree un programa principal de prueba que lea el tamaño de la imagen (filas y columnas)
y los datos correspondientes. El programa debe construir la imagen suavizada e
imprimir el resultado en pantalla.
Ejemplo de entrada:
5 6
-1 -1 -1 1 9 1
-2 -1 -1 8 -1 1
-1 -1 -1 1 3 1
-1 -1 -1 4 4 4
1 5 5 5 5 1
􀀀􀀀 Salida correcta:
-1 -1 -1 1 9 1
-2 0 3 8 3 1
-1 0 4 1 3 1
-1 3 4 4 4 4
1 5 5 5 5 1
*/

#include <iostream>
using namespace std;

class ImagenBlancoNegro{
private:
	static const int CAPACIDAD = 100;
	int num_filas = 0;
	int num_columnas = 0;
	int matriz[CAPACIDAD][CAPACIDAD];
	int matriz_nueva[CAPACIDAD][CAPACIDAD];
public:
	ImagenBlancoNegro(int numero_filas, int numero_columnas){
		num_filas = numero_filas;
		num_columnas = numero_columnas;

		for(int i = 0; i < num_filas; i++)
			for(int j = 0; j < num_columnas; j++)
				cin >> matriz[i][j];

		for(int i = 0; i < num_filas; i++)
			for(int j = 0; j < num_columnas; j++)
				matriz_nueva[i][j] = matriz[i][j];
	}
	int Pixel(int fil, int col){
		return matriz_nueva[fil][col];
	}
	void Modifica(int fil, int col, int nuevo){
		matriz[fil][col] = nuevo;
	}
	void Suaviza(int  fil, int col){
		int media = 0;
		int contador = 0;

		if(matriz[fil][col] < 0){
			for(int i = fil - 1; i <= fil + 1; i++){
				for(int j = col - 1; j <= col + 1; j++){
					if(matriz[i][j] > 0){
						media += matriz[i][j];
						contador++;
					}
				}
			}
			if(contador == 0){
				matriz_nueva[fil][col] = 0;
			}
			else{
				media = media/contador;
				matriz_nueva[fil][col] = media;
			}
		}
	}
};

int main(){
	string texto;
	int fil, col;

	cin >> fil;
	cin >> col;

	ImagenBlancoNegro suaviza(fil, col);
	for(int i = 1; i < fil; i++)
			for(int j = 1; j < col; j++)
				suaviza.Suaviza(i, j);

	for(int i = 0; i < fil; i++){
		cout << "\n";
		for(int j = 0; j < col; j++){
			cout << suaviza.Pixel(i, j) << "\t";
		}
	}
}
