/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Examen Febrero 2015
// Pregunta 3
//
// So,ución implementada con la clase TablaRectangularReales que usa la
// representación de secuencia de secuencias
//
// 3 de Febrero de 2015
//
/*********************************************************************/

#include <iostream>
#include <iomanip>

#include <cstdlib>	// para "MyRandom"
#include <ctime>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Generador de números aleatorios. 
// Los objetos de esta clase sirven para generar números aleatorios a demanda 
// con el metodo "Next" entre los valores "min" y "max". 

class MyRandom
{
	
private:
	
	// PRE: minVal <= MaxVal
	
    int minVal;	// Mínimo Valor
    int maxVal;	// Máximo valor

	/***********************************************************************/
	// Inicializa el generador de números aleatorios 
	// Es un método privado que se invoca solo al actuar el constructor.
	
	void InitMyRandom (void)
    {
        time_t t;
        srand ((int) time(&t));     // Inicializa el generador
                                    // con el reloj del sistema
    }
    
public:
	
	/***********************************************************************/	
	// Constructor
	
    MyRandom (int el_minimo, int el_maximo) :
        minVal(el_minimo), maxVal(el_maximo)
    {
        InitMyRandom();

        int no_lo_uso = Next(); // Desecho el primero
    }

	/***********************************************************************/	
	// Calcula y devuelve un número aleatorio en el rango prefijado.
	
    int Next (void) {
    	
        int rango = (maxVal - minVal)+1;
        int v1 = rango * (rand() / (RAND_MAX*1.0));
        int v2 = minVal + (v1 % rango);

        return (v2);
    }

	/***********************************************************************/
	
    int Min (void) 
	{
        return (minVal);
    }

	/***********************************************************************/
	
    int Max (void) 
	{
        return (maxVal);
    }

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
	

/////////////////////////////////////////////////////////////////////////////
// Secuencia de reales 

class SecuenciaReales  
{

private:

	static const int TAMANIO = 50; // Número de casillas disponibles
	double vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaReales (void) 
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	// Devuelve el número de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el número de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// Añade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (double nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	//
	// PRE: 0 <= indice < total_utilizados 

	double Elemento (int indice)
	{
		return vector_privado[indice];
	}

	/***********************************************************************/
	// "Vacía" una secuencia
		
	void EliminaTodos (void) 
	{
		total_utilizados = 0;
	}
	
	/***********************************************************************/
	// Devuelve true si la secuencia está vacía

	bool EstaVacia (void) 
	{
		return (total_utilizados == 0);
	}
	
	/***********************************************************************/	
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Tabla rectangular de reales

class TablaRectangularReales
{


private:

    static const int MAX_FIL = 50; // "filas" disponibles
    static const int MAX_COL = 40;

    SecuenciaReales vector_privado[MAX_FIL];

    // PRE: 0 <= filas_utilizadas < MAX_FIL
    // PRE: 0 <= cols_utilizadas < MAX_COL

    int filas_utilizadas;
    int cols_utilizadas;

public:
	
	/***********************************************************************/
	// Constructor a)
	// Recibe "numero_de_columnas" que indica el número de columnas 
	// que deben tener TODAS las filas.

	TablaRectangularReales (int numero_de_columnas)
		: filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{
	}

	/***********************************************************************/
	// Constructor b)
	// Recibe una secuencia de reales. El número de elementos de la 
	// secencia es el valor que se usa como "col_utilizadas"

	TablaRectangularReales (SecuenciaReales primera_fila)
		: filas_utilizadas(0), 
		  cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// Método de lectura: número máximo de filas

	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}

	/*****************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}

	/*****************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// Método de lectura: número real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/*****************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	//
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	double Elemento (int fila, int columna)
	{
		return ((vector_privado[fila]).Elemento(columna));
	}


	/*****************************************************************/
	// Devuelve una fila completa, como un objeto de la clase
	// "SecuenciaReales"
	// PRE: 0 <= indice_fila < filas_utilizadas

	SecuenciaReales Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}
	
	/***********************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}

	/*****************************************************************/
	// Añade una fila completa. La fila se porporciona en un objeto de 
	// la clase "SecuenciaReales".
	// 
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaReales fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();

		if ((filas_utilizadas < MAX_FIL) &&
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			vector_privado[filas_utilizadas] = fila_nueva;

			filas_utilizadas++;
		}
	}
	
	/***********************************************************************/
	// "Vacía" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
		
	TablaRectangularReales PromedioRelativo (void)
	{
		TablaRectangularReales nueva (cols_utilizadas);

		for (int f=0; f<filas_utilizadas; f++) {

			SecuenciaReales fila (Fila(f));
			SecuenciaReales nueva_fila;
		
			for (int c=0; c<cols_utilizadas; c++) {
				
				if (f==c) // Diagonal
				
					nueva_fila.Aniade(fila.Elemento(f));

				else
				
					if (f>c) { // Triángulo inferior
					
						// El valor a guardar ya ha sido calculado previamente.
						// Accedemos a él usando el método "Elemento"
						
						nueva_fila.Aniade(nueva.Elemento(c,f));
						
						// También podríamos haber escrito:
						//    SecuenciaReales fila_f_de_nueva (nueva.Fila(f));
						//    double valor = fila_f_de_nueva.Elemento(c);
						//    nueva_fila.Aniade (valor);
						
					}
					else { // Triángulo superior

						double suma = 0.0;

						for (int casilla=c; casilla<cols_utilizadas; casilla++)
							suma += fila.Elemento(casilla);
						
						nueva_fila.Aniade(suma/(cols_utilizadas-c));
					}
			}
			
			nueva.Aniade (nueva_fila);
		}

			
		return (nueva);
	}
		
	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

void MuestraTablaRectangularReales (TablaRectangularReales tabla, string msg)
{
	cout << endl << endl;
	cout << msg  << endl;	
	cout << endl << endl;

	for (int f=0; f<tabla.FilasUtilizadas(); f++) {
		  		
		for (int c=0; c<tabla.ColumnasUtilizadas(); c++) 					
			cout << setw(7) << setprecision(2) << tabla.Elemento(f, c);

		cout << endl;
		
	}
	cout << endl << endl;
}
	
/***************************************************************************/
/***************************************************************************/

int main (void) 
{
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 	
	
	// Lee y filtra las dimensiones de la tabla

	int n; // Número de filas y columnas 

	do {
		cout << "Num. filas y columnas: "; 
		cin >> n;
	} while (n <=0);


	// Crear la matriz y rellenarla con números aleatorios

	TablaRectangularReales tabla (n);


	// Iniciar el generador de números aleatorios
	MyRandom generador (1,10); 
	

	// Rellenar la tabla, fila a fila
	
	for (int f=0; f<n; f++) {
	
		SecuenciaReales una_fila;
		
		for (int c=0; c<n; c++) 
			una_fila.Aniade(generador.Next()); 
			
		tabla.Aniade(una_fila);
	}
	
	// Mostrar la matriz creada
	
	MuestraTablaRectangularReales (tabla, "Tabla inicial: ");
	
	
	// Calculo de la tabla promedio
	
	TablaRectangularReales tabla_promediada (tabla.PromedioRelativo());
	
	
	// Mostrar la matriz transformada
	
	MuestraTablaRectangularReales (tabla_promediada, "Tabla resultante: ");
	
	return (0);
} 
