/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 14 Ejercicio 24
 
Defina la clase TablaRectangularEnteros usando
una matriz de doble corchete como dato miembro privado.
int matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];
Se pretende que pueda almacenar un conjunto de filas de enteros, todas ellas con el
mismo número de columnas. Defina métodos para:
a) Obtener el número de filas y columnas utilizadas, así como el dato que haya en
una fila y columna.
b) Devolver una fila completa como un objeto de la clase SecuenciaEnteros. El
código de esta clase puede descargarse desde la siguiente dirección:
http://decsai.ugr.es/~carlos/FP/SecuenciaEnteros.cpp
c) Añadir una fila entera. La fila será un objeto de la clase SecuenciaEnteros.
d) Comprobar si es igual a otra matriz.
e) Obtener la traspuesta.
f ) Comprobar si es simétrica (sólo tiene sentido cuando sea cuadrada, es decir,
con el mismo número de filas que de columnas). Hágalo primero calculando la
traspuesta de la matriz y viendo si es igual a su simétrica, usando los métodos
anteriores.
Hágalo también comprobando directamente si cada componente es igual a su
simétrica y parando el recorrido en cuanto encuentre una componente que no lo
verifique.
g) Multiplicar dos tablas.
Construya un programa principal que lea el número de filas y columnas de una tabla,
los datos de ésta, e indique si es simétrica o no. A continuación, calcule la traspuesta
y multiplique la tabla por su traspuesta. Imprima el resultado en pantalla.
*/

#include <iostream>
using namespace std;

class SecuenciaEnteros{
private:
   static const int TAMANIO = 50;
   long vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      long intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
   SecuenciaEnteros()
      :total_utilizados(0) {
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Aniade(long nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, long nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   long Elemento(int indice){
      return vector_privado[indice];
   }
   
   string ToString(){
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++){
         cadena.append(to_string(vector_privado[i]));
         cadena.append(" ");
         //cadena = cadena + to_string(vector_privado[i])  <- Evitarlo. Muy ineficiente para tamaños grandes;
      }
      
      return cadena;
   }

   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, long buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }
   
   int PrimeraOcurrencia (long buscado){
      return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
   }
   

   /////////////////////////////////////////////////////////////
   // Búsquedas
   
   // Precond: 0 <= izda <= dcha < total_utilizados
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      long minimo;

      minimo = vector_privado[izda];
      posicion_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (vector_privado[i] < minimo){
            minimo = vector_privado[i];
            posicion_minimo = i;
         }

      return posicion_minimo;
   }
   
   int PosicionMinimo(){
      return PosicionMinimoEntre(0, total_utilizados - 1);
   }
   
   int BusquedaBinaria (long buscado){
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = total_utilizados - 1;
      centro = (izda + dcha) / 2;

      while (izda <= dcha  &&  !encontrado){
         if (vector_privado[centro] == buscado)
            encontrado = true;
         else if (buscado < vector_privado[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;

         centro = (izda + dcha) / 2;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }
   
   
   /////////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes
   
   // Inserta un valor en la posición especificada
   void Inserta(int pos_insercion, long valor_nuevo){
      if (total_utilizados < TAMANIO  &&  pos_insercion >= 0    
         &&  pos_insercion <= total_utilizados){

         for (int i = total_utilizados ; i > pos_insercion ; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[pos_insercion] = valor_nuevo;
         total_utilizados++;
      }
   }
   
   // Elimina una componente, dada por su posición
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
   }
   
   
   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenación
   
   void Ordena_por_Seleccion(){
      int pos_min;

      for (int izda = 0 ; izda < total_utilizados ; izda++){
         pos_min = PosicionMinimoEntre(izda, total_utilizados - 1);
         IntercambiaComponentes_en_Posiciones(izda, pos_min);
      }
   }
   
   void Ordena_por_Insercion(){
      int izda, i;
      long a_desplazar;

      for (izda=1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i=izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
   
   void Ordena_por_Burbuja(){
      int izda, i;

      for (izda = 0; izda < total_utilizados; izda++)
        for (i = total_utilizados-1 ; i > izda ; i--)
          if (vector_privado[i] < vector_privado[i-1])
             IntercambiaComponentes_en_Posiciones(i, i-1);
   }
   
   void Ordena_por_BurbujaMejorado(){
      int izda, i;
      bool cambio;

      cambio= true;

      for (izda=0; izda < total_utilizados && cambio; izda++){
        cambio=false;

        for (i=total_utilizados-1 ; i>izda ; i--)
          if (vector_privado[i] < vector_privado[i-1]){
             IntercambiaComponentes_en_Posiciones(i, i-1);
             cambio=true;
          }
      }
   }
   
   void AniadeVarios(SecuenciaEnteros nuevos){
      int totales_a_aniadir = nuevos.TotalUtilizados();
      
      for (int i = 0; i < totales_a_aniadir; i++)
         Aniade(nuevos.Elemento(i)); // Es importante entender
   }


   // Busca una sub-secuencia
   // Las posiciones deben estar en orden y consecutivas
   int PosicionContiene (SecuenciaEnteros a_buscar){
      int  inicio;
      int  ultima_componente;
      bool encontrado;
      int  posicion_contiene;
      bool va_coincidiendo;
      int  utilizados_a_buscar;

      /*
      Tenemos una secuencia "grande" de tamaño G y otra pequeña de tamaño P

      Recorrer la secuencia "grande" fijando una posición inicial inicio
      La última posición inicial a probar será G-P
         A partir de inicio recorrer en paralelo las
         dos secuencias "grande" y "pequeña"
         Si no coinciden todas las componentes, hay que
         empezar de nuevo a partir de inicio + 1.
      */

      utilizados_a_buscar = a_buscar.TotalUtilizados();

      if (utilizados_a_buscar > 0){
         ultima_componente = total_utilizados - utilizados_a_buscar;
         encontrado = false;

         for (inicio = 0; inicio <= ultima_componente && !encontrado; inicio++){
            va_coincidiendo = true;

            for (int i = 0; i < utilizados_a_buscar && va_coincidiendo; i++)
               va_coincidiendo = vector_privado[inicio + i] == a_buscar.Elemento(i);

            if (va_coincidiendo){
               posicion_contiene = inicio;
               encontrado = true;
            }
         }
      }
      else
         encontrado = false;

      if (encontrado)
         return posicion_contiene;
      else
         return -1;
   /*
   Batería de pruebas:
      Los dos vectores vacíos.
      Alguno de ellos vacío.
      Los dos vectores iguales.  atti / atti
      Que no se encuentre.   atti / tj
      Que se encuentre al principio.  atti / at
      Que se encuentre justo al final. atti / ti
      Que haya un emparejamiento parcial pero no total,
      aunque luego sí se encuentre.  atttij / ti
   */
   }
};

class LectorSecuenciaEnteros{
private:
   long terminador;
public:
   LectorSecuenciaEnteros(long entero_terminador)
      :terminador(entero_terminador)
   {
   }
   SecuenciaEnteros Lee(){
      SecuenciaEnteros a_leer;
      int total_introducidos;  // Esta variable es para contar los introducidos
                               // y que no nos pasemos de la capacidad de la secuencia.
      int capacidad_secuencia;
      long entero;

      total_introducidos = 0;
      capacidad_secuencia = a_leer.Capacidad();
      cin >> entero;

      while (entero != terminador && total_introducidos < capacidad_secuencia){
         a_leer.Aniade(entero);
         total_introducidos++;
         cin >> entero;
      }

      return a_leer;
   }
};


class TablaRectangularEnteros{
private:
	static const int MAXIMO_FILAS = 100;
	static const int MAXIMO_COLUMNAS = 100;
	int matriz_privada[MAXIMO_FILAS][MAXIMO_COLUMNAS];
	int matriz_traspuesta[MAXIMO_FILAS][MAXIMO_COLUMNAS];
	int matriz_multiplicada[MAXIMO_FILAS][MAXIMO_COLUMNAS];
	int num_filas = 0;
	int num_columnas = 0;
public:
	TablaRectangularEnteros(int numero_filas, int numero_columnas){
		num_filas = numero_filas;
		num_columnas = numero_columnas;

		for(int i = 0; i < num_filas; i++)
			for(int j = 0; j < num_columnas; j++)
				cin >> matriz_privada[i][j];
	}
	int FilasUsadas(){
		return num_filas;
	}
	int ColumnasUsadas(){
		return num_columnas;
	}
	int PosPrivada(int fil, int col){
		return matriz_privada[fil][col];
	}
	int PosTraspuesta(int fil, int col){
		return matriz_traspuesta[fil][col];
	}
	int PosMultiplicada(int fil, int col){
		return matriz_multiplicada[fil][col];
	}
	void Modifica(int fil, int col, int nuevo){
		matriz_privada[fil][col] = nuevo;
	}
	SecuenciaEnteros GetFila(int linea){
		SecuenciaEnteros fila;
		for(int i = 0; i < num_columnas; i++){
			fila.Aniade(matriz_privada[linea][i]);
		}

		return fila;
	}
	void AniadeFila(SecuenciaEnteros datos, int fila){
		for(int i = 0; i < num_columnas; i++){
			matriz_privada[fila][i] = datos.Elemento(i);
		}
	}
	bool EsIgual(int matriz[MAXIMO_FILAS][MAXIMO_COLUMNAS]){
		bool igual = true;

		for(int i = 0; i < num_filas; i++)
			for(int j = 0; j < num_columnas; j++)
				if(matriz_privada[i][j] != matriz[i][j])
					return false;
		return igual;
	}
	void Traspuesta(){
	   for (int i=0; i<num_filas; i++)
	      for (int j=0; j<num_columnas; j++)
	         matriz_traspuesta[j][i] = matriz_privada[i][j];
	}
	bool EsSimetrica1(){
		bool es_simetrica = true;
		if(num_filas != num_columnas)
			return false;
		else{
			Traspuesta();
			es_simetrica = EsIgual(matriz_traspuesta);
			return es_simetrica;
		}
	}
	bool EsSimetrica2(){
		bool es_simetrica = true;
		int copia_filas = num_filas;
		int copia_columnas = num_columnas;

		for(int i = 0; i < num_filas; i++){
			copia_columnas = num_columnas;
			copia_filas--;
			for(int j = 0; j < num_columnas; j++){
				if(matriz_privada[i][j] != matriz_privada[copia_filas][copia_columnas])
					return false;
				copia_columnas--;
			}
		}
		return es_simetrica;
	}
	void Multiplica(int matriz1[MAXIMO_FILAS][MAXIMO_COLUMNAS], int fil1, int col1,
                   int matriz2[MAXIMO_FILAS][MAXIMO_COLUMNAS], int fil2, int col2){
		for(int i = 0; i < fil1; ++i)
         for(int j = 0; j < col2; ++j)
            matriz_multiplicada[i][j] = 0;

      for(int i = 0; i < fil1; ++i)
         for(int j = 0; j < col2; ++j)
            for(int z = 0; z < col1; ++z)
               matriz_multiplicada[i][j] += matriz1[i][z] * matriz2[z][j];

	}
};

int main(){
	int fil, col;
	int matriz_ayuda[100][100];
	int matriz_original[100][100];

	cin >> fil;
	cin >> col;

	TablaRectangularEnteros matriz_main(fil, col);

	cout << "\n\t\t¿ES SIMETRICA?" << endl;
	if(matriz_main.EsSimetrica1())
		cout << "Si es simetrica :)" << endl;
	else
		cout << "No es simetrica :'(" << endl;

	cout << "\n\t\tCALCULO DE LA TRASPUESTA" << endl;
	matriz_main.Traspuesta();
	for(int i = 0; i < col; i++){
		cout << "\n";
		for(int j = 0; j < fil; j++){
			cout << matriz_main.PosTraspuesta(i, j) << "\t";
         matriz_ayuda[i][j] = matriz_main.PosTraspuesta(i, j);
		}
	}

	cout << "\n\t\tCALCULO DE LA MULTIPLICACION" << endl;
	for(int i = 0; i < fil; i++){
		for(int j = 0; j < col; j++){
			matriz_original[i][j] = matriz_main.PosPrivada(i, j);
		}
	}
	matriz_main.Multiplica(matriz_original, fil, col, matriz_ayuda, col, fil);
	for(int i = 0; i < fil; i++){
		cout << "\n";
		for(int j = 0; j < col; j++){
			cout << matriz_main.PosMultiplicada(i, j) << "\t";
		}
	}
}
