/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Examen Febrero 2015
// Pregunta 3
//
// So,uci�n implementada con la clase TablaRectangularReales que usa la
// representaci�n de secuencia de secuencias
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
// Generador de n�meros aleatorios. 
// Los objetos de esta clase sirven para generar n�meros aleatorios a demanda 
// con el metodo "Next" entre los valores "min" y "max". 

class MyRandom
{
	
private:
	
	// PRE: minVal <= MaxVal
	
    int minVal;	// M�nimo Valor
    int maxVal;	// M�ximo valor

	/***********************************************************************/
	// Inicializa el generador de n�meros aleatorios 
	// Es un m�todo privado que se invoca solo al actuar el constructor.
	
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
	// Calcula y devuelve un n�mero aleatorio en el rango prefijado.
	
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

	static const int TAMANIO = 50; // N�mero de casillas disponibles
	double vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaReales (void) 
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// M�todos de lectura (Get) de los datos individuales 

	// Devuelve el n�mero de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el n�mero de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// A�ade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a a�adir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adici�n se realiza si hay espacio para el nuevo elemento. 
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
	// "Vac�a" una secuencia
		
	void EliminaTodos (void) 
	{
		total_utilizados = 0;
	}
	
	/***********************************************************************/
	// Devuelve true si la secuencia est� vac�a

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
	// Recibe "numero_de_columnas" que indica el n�mero de columnas 
	// que deben tener TODAS las filas.

	TablaRectangularReales (int numero_de_columnas)
		: filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{
	}

	/***********************************************************************/
	// Constructor b)
	// Recibe una secuencia de reales. El n�mero de elementos de la 
	// secencia es el valor que se usa como "col_utilizadas"

	TablaRectangularReales (SecuenciaReales primera_fila)
		: filas_utilizadas(0), 
		  cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero m�ximo de filas

	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: devuelve el dato que ocupa la casilla 
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
	// Devuelve true si la tabla est� vac�a

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}

	/*****************************************************************/
	// A�ade una fila completa. La fila se porporciona en un objeto de 
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
	// "Vac�a" una tabla
	
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
				
					if (f>c) { // Tri�ngulo inferior
					
						// El valor a guardar ya ha sido calculado previamente.
						// Accedemos a �l usando el m�todo "Elemento"
						
						nueva_fila.Aniade(nueva.Elemento(c,f));
						
						// Tambi�n podr�amos haber escrito:
						//    SecuenciaReales fila_f_de_nueva (nueva.Fila(f));
						//    double valor = fila_f_de_nueva.Elemento(c);
						//    nueva_fila.Aniade (valor);
						
					}
					else { // Tri�ngulo superior

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
	
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 	
	
	// Lee y filtra las dimensiones de la tabla

	int n; // N�mero de filas y columnas 

	do {
		cout << "Num. filas y columnas: "; 
		cin >> n;
	} while (n <=0);


	// Crear la matriz y rellenarla con n�meros aleatorios

	TablaRectangularReales tabla (n);


	// Iniciar el generador de n�meros aleatorios
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
