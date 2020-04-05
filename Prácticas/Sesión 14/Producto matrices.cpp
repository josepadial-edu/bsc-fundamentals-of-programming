/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 14 Ejercicio 28
 
 Descripción:
 
Lea los datos de una matriz de reales tal y como se indica en el
ejercicio 27 de esta relación de problemas.
Si la matriz que se ha introducido es n  m, por ejemplo, ahora se procederá a leer
los datos de una segunda matriz m  k. Por lo tanto, en primer lugar se lee el entero
k y a continuación los valores de esta segunda matriz.
Multiplique ambas matrices y muestre el resultado en pantalla.
*/

#include <iostream>
using namespace std;

int main(){
   const int MAX_FIL = 10, MAX_COL = 10;
   double matriz[MAX_FIL][MAX_COL];
   int util_filas, util_columnas;

   cin >> util_filas;
   cin >> util_columnas;

   for (int i=0; i<util_filas; i++)
      for (int j=0; j<util_columnas; j++)
         cin >> matriz[i][j];  

   ///////////////////////////////////////////////////////////////////////////
   // Multiplicación
   
   const int MAX_FIL_DCHA = MAX_COL, MAX_COL_DCHA = 30;
   double matriz_dcha[MAX_FIL_DCHA][MAX_COL_DCHA];
   double matriz_producto[MAX_FIL][MAX_COL_DCHA];

   int util_filas_dcha, util_columnas_dcha;
   int util_filas_producto, util_columnas_producto;

   util_filas_dcha = util_columnas;
   cin >> util_columnas_dcha;
      
   for (int i=0; i<util_filas_dcha; i++)
      for (int j=0; j<util_columnas_dcha; j++)
         cin >> matriz_dcha[i][j];
   
   util_filas_producto = util_filas;
   util_columnas_producto = util_columnas_dcha;
   
   for (int i=0; i<util_filas_producto; i++)
      for (int j=0; j<util_columnas_producto; j++){
         matriz_producto[i][j] = 0;
         
         for (int k=0; k<util_columnas_producto; k++)
            matriz_producto[i][j] = matriz_producto[i][j] +
                                    matriz[i][k] * matriz_dcha[k][j];
   }
   
   cout << "\n\n";
   cout << "Matriz producto:\n";
   
   for (int i=0; i<util_filas_producto; i++){
      cout << "\n";
      
      for (int j=0; j<util_columnas_producto; j++)
         cout << matriz_producto[i][j] << '\t';
   }  
  
   
   cout << "\n\n";
}
