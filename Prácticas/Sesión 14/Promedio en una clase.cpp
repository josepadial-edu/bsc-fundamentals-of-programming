/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 14 Ejercicio 21
 
Recupere la solución del ejercicio 30
(matriz promedio) de la Relación de Problemas IV. Se quiere hacer lo mismo pero
sobre una clase TablaCuadradaReales, por lo que debe implementar el siguiente
método:
TablaCuadradaReales Promedio(){
En la dirección que aparece abajo se encuentra el código principal de la clase, así
como de la clase SecuenciaReales y el programa principal. Complete el código
implementando el método Promedio y la llamada desde el main.
*/

#include <iostream>
using namespace std;

class TablaCuadradaReales{
private:
   static const int MAX_FIL = 50, MAX_COL = 30;
   double matriz[MAX_FIL][MAX_COL];
   int util_filas_matriz;
   double suma;
public:
   TablaCuadradaReales(int util_filas){
      util_filas_matriz = util_filas;
   }
   int GetUtilFilasMatriz(){
      return util_filas_matriz;
   }
   double GetSuma(){
      return suma;
   }
   void ModificaUtil(int valor){
      util_filas_matriz = valor;
   }
   void ModificaSuma(double valor_suma){
      suma = valor_suma;
   }
   void Aniade(){
      for (int i=0; i<util_filas_matriz; i++)
         for (int j=0; j<util_filas_matriz; j++)
           cin >> matriz[i][j];
   }
   double ConsultaPos(int n, int m){
      return matriz[n][m];
   }
   void ModificaPos(int n, int m, double valor_a_modificar){
      matriz[n][m] = valor_a_modificar;
   }
   TablaCuadradaReales Promedio(){
      TablaCuadradaReales promedio(0);
      int util_filas_mat = this -> util_filas_matriz;
      for (int i = 0; i < util_filas_mat; i++){
         promedio.ModificaPos(i,i, matriz[i][i]);
         promedio.ModificaSuma(0);
         
         for (int j = util_filas_mat - 1 ; j > i; j--){
            promedio.ModificaSuma(promedio.GetSuma() + matriz[i][j]);
            promedio.ModificaPos(i,j, (promedio.GetSuma() / (util_filas_mat - j)));
            promedio.ModificaPos(j,i, promedio.ConsultaPos(i,j));
         }
      }

      promedio.ModificaUtil(util_filas_mat);
      return promedio;
   }
};

int main(){
   
   int util_filas_matriz;

   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas > 0

   cin >> util_filas_matriz;
   TablaCuadradaReales matriz_promedio(util_filas_matriz);
   matriz_promedio.Aniade();

   ///////////////////////////////////////////////////////////////////////////
   // Promedio

   /*
      Algoritmo Matriz Promedio vs 2 (más rápida)

      Recorrer todas las filas -i- de la matriz original
         Asignar el mismo elemento de la diagonal principal

         Recorrer las columnas -j- desde la última hasta i
            Ir acumulando en una variable suma
            el sumatorio de los m[i][j]
            Asignar media correspondiente a la componente ij y a la ji
   */
   
   /*
   Con una matriz tan pequeña como la siguiente no se aprovecha la
   eficiencia de este algoritmo. De hecho, obsérvese que sólo se aprovecha
   con una componente, la 01 -> (7+9)/3
   */
   /*
   9  7   4  5         9    (7+9)/3      (4+5)/2    5/1
   2  18  2  12        =    18           (2+12)/2   12/1
   7  9   1  5         =    =            1          5/1
   0  1   2  3         =    =            =          3
   */

   matriz_promedio = matriz_promedio.Promedio();
 
   cout << "\n\n";
   cout << "Matriz promedio:\n";
   
   for (int i = 0; i < matriz_promedio.GetUtilFilasMatriz(); i++){
      cout << "\n";
      
      for (int j = 0; j < matriz_promedio.GetUtilFilasMatriz(); j++)
         cout << matriz_promedio.ConsultaPos(i,j) << '\t';
   }  
   
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
