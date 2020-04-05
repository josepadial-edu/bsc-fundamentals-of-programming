////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////


/*
En este ejercicio no hay que construir ninguna funci�n o
clase. Todo se programar� en el main . Defina dos matrices de reales original
y suavizada de tama�o 50 x 30 . Lea desde teclado los valores de la matriz
original , obligando a que sea sim�trica. Para ello, lea el n�mero de filas n y a
continuaci�n introduzca los n � n datos de la matriz.
Construya la matriz suavizada acorde a las siguientes indicaciones:
a) La tabla resultante ser� sim�trica.
b) Los valores de la diagonal principal de la tabla resultante ser�n iguales a los de
la tabla original.
c) Los valores del tri�ngulo superior de la tabla resultante se calculan de la si-
guiente manera: si (i,j) es una posici�n en el tri�ngulo superior de la tabla re-
sultante, su valor es el valor medio de los valores que ocupan las posiciones de
las columnas j,j + 1,...,n - 1 en la fila i de la tabla original.
*/

#include <iostream>
using namespace std;

int main(){
   const int MAX_FIL = 50, MAX_COL = 30;
   double matriz[MAX_FIL][MAX_COL];
   double suavizada[MAX_FIL][MAX_COL];
   int util_filas_matriz, util_filas_suavizada;
   double suma, media;


   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas > 0

   cin >> util_filas_matriz;

   for (int i=0; i<util_filas_matriz; i++)
      for (int j=0; j<util_filas_matriz; j++)
         cin >> matriz[i][j];

   ///////////////////////////////////////////////////////////////////////////
   // Suavizada Promedio
   /*
      Algoritmo Suavizada Promedio vs 1
      
      Recorrer todas las filas -i- de la matriz original
         Asignar el mismo elemento de la diagonal principal
         
         Recorrer las columnas -j- a partir de i+1
            Calcular la media de los elementos que hay
            en las columnas posteriores a j
            Asignar el resultado a la componente ij y a la ji
   */
   
   /*
   9  7   4  5         9    (7+4+5)/3    (4+5)/2    5/1
   2  18  2  12        =    18           (2+12)/2   12/1
   7  9   1  5         =    =            1          5/1
   0  1   2  3         =    =            =          3
   */
   

   for (int i=0; i<util_filas_matriz; i++){
      suavizada[i][i] = matriz[i][i];
      
      for (int j=i+1; j<util_filas_matriz; j++){
         suma = 0;
         
         for (int k=j; k<util_filas_matriz; k++)
            suma = suma + matriz[i][k];

         suavizada[i][j] = suma / (util_filas_matriz - j);
         suavizada[j][i] = suavizada[i][j];
      }
   }

   

   /*
      Algoritmo Suavizada Promedio vs 2 (m�s r�pida)

      Recorrer todas las filas -i- de la matriz original
         Asignar el mismo elemento de la diagonal principal

         Recorrer las columnas -j- desde la �ltima hasta i
            Ir acumulando en una variable suma
            el sumatorio de los m[i][j]
            Asignar media correspondiente a la componente ij y a la ji
   */
   
   /*
   Con una matriz tan peque�a como la siguiente no se aprovecha la
   eficiencia de este algoritmo. De hecho, obs�rvese que s�lo se aprovecha
   con una componente, la 01 -> (7+9)/3
   */
   /*
   9  7   4  5         9    (7+9)/3      (4+5)/2    5/1
   2  18  2  12        =    18           (2+12)/2   12/1
   7  9   1  5         =    =            1          5/1
   0  1   2  3         =    =            =          3
   */

   for (int i=0; i<util_filas_matriz; i++){
      suavizada[i][i] = matriz[i][i];
      suma = 0;
      
      for (int j=util_filas_matriz - 1 ; j > i; j--){
         suma = suma + matriz[i][j];
         suavizada[i][j] = suma / (util_filas_matriz - j);
         suavizada[j][i] = suavizada[i][j];
      }
   }

   
   util_filas_suavizada = util_filas_matriz;
   
 
   cout << "\n\n";
   cout << "Matriz suavizada:\n";
   
   for (int i=0; i<util_filas_suavizada; i++){
      cout << "\n";
      
      for (int j=0; j<util_filas_suavizada; j++)
         cout << suavizada[i][j] << '\t';
   }  
  
   
   cout << "\n\n";

   // Entrada:
   // 4   9 7 4 5    2 18 2 12    7 9 1 5   0 1 2 3

   // Salida:
   /*
   9       5.33333 4.5     5
   5.33333 18      7       12
   4.5     7       1       5
   5       12      5       3
   */
}
