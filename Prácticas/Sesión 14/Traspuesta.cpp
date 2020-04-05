/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 14 Ejercicio 27
 
 Descripción:
 
En este ejercicio, no hay que construir ninguna clase ni función. Es un
ejercicio sobre recorridos de una matriz declarada directamente en el main.
Lea desde teclado dos variables util_filas y util_columnas y lea los datos
de una matriz de reales de tamaño util_filas x util_columnas. Sobre dicha
matriz, se pide lo siguiente:
Calcular la traspuesta
*/

#include <iostream>
using namespace std;

int main(){
   const int MAX_FIL = 10, MAX_COL = 10;
   double matriz[MAX_FIL][MAX_COL];
   double traspuesta[MAX_COL][MAX_FIL];
   int util_filas, util_columnas;

   cin >> util_filas;
   cin >> util_columnas;

   for (int i=0; i<util_filas; i++)
      for (int j=0; j<util_columnas; j++)
         cin >> matriz[i][j];

   ///////////////////////////////////////////////////////////////////////////
   // Traspuesta
   
   int util_fil_traspuesta, util_col_traspuesta;
   
   util_fil_traspuesta = util_columnas;
   util_col_traspuesta = util_filas;
   
   for (int i=0; i<util_fil_traspuesta; i++)
      for (int j=0; j<util_col_traspuesta; j++)
         traspuesta[i][j] = matriz[j][i];
   
   cout << "\n\n";
   cout << "Matriz original:\n";

   for (int i=0; i<util_filas; i++){
      cout << "\n";

      for (int j=0; j<util_columnas; j++)
         cout << matriz[i][j] << '\t';
   }
   
   cout << "\n\n";
   cout << "Matriz traspuesta:\n";   
    
   for (int i=0; i<util_fil_traspuesta; i++){
      cout << "\n";
      
      for (int j=0; j<util_col_traspuesta; j++)
         cout << traspuesta[i][j] << '\t';
   }  

   cout << "\n\n";
}
