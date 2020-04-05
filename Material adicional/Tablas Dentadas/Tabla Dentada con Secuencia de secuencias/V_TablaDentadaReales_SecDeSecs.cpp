/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//  
// CURSO 2015-2016
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// RELACI�N DE PROBLEMAS V
// EJERCICIO 27
//
/*	 
	Programa que crear una matriz dentada de valores reales leyendo sus 
	valores de la entrada est�ndar y realizar c�lculos con ella.
	En concreto, este programa calcula la suma de los valores de cada grupo.
	
	Todos los valores necesarios (n�mero de secuencias, n�mero de datos de 
	cada secuencia y los valores de cada secuencia) se introducen en una 
	sola l�nea.
	
	.........................................................................
	Representaci�n: Secuencia (vector cl�sico) de secuencias.
	.........................................................................
	
	Por ejemplo, una l�nea de entrada podr�a ser la siguiente:
	
		3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7
	
		--> Se distinguen tres grupos o secuencias de datos (lo indica el
			primer n�mero (int) de la l�nea). 
		-->	Cada grupo empieza por un valor (int) que indica el tama�o de la
			secuencia (en el ejemplo, las secuencias tienen dos, cinco y dos
			elementos, respectivamente). 
		-->	A continuaci�n de este valor se encentran tantos valores (double)
			como indique el valor entero que encabeza cada grupo.
	
		En el ejemplo, la primera secuencia contendr� los valores 3.1 y 0.4, 
		la segunda 1.0, 1.0, 1.0, 1.0 y 1.0 y la tercera 5.2 y 4.7.
	
		El programa escribir� como resultado: 3.5, 5.0 y 9.9
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

/////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////

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
	// Eliminar el dato de la posici�n dada por "indice".
	// Realiza un borrado f�sico (con desplazamiento y sustituci�n).
	//
	// PRE: 0 <= indice < total_utilizados 
	
	void Elimina (int indice) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posici�n a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posici�n del �ltimo 
    
			for (int i = indice ; i < tope ; i++)
				vector_privado[i] = vector_privado[i+1];  
    
			total_utilizados--;    
		}
	}
		
			
	/***********************************************************************/
	// COMPARACI�N
	/***********************************************************************/
				
	/***********************************************************************/
	// Compara dos secuencias
	
	bool EsIgual (SecuenciaReales otra_secuencia) 
	{
		bool son_iguales = true; 
		
		if (total_utilizados != otra_secuencia.total_utilizados)
		
			son_iguales = false;
		
		else {
				
			bool sigo = true;
			int pos = 0;
			
			while (sigo && (pos < total_utilizados)) {
	
				if (vector_privado[pos]!=otra_secuencia.vector_privado[pos]) {
					sigo = false;
					son_iguales = false;
				}
				else
					pos++; 
			} // while (sigo && pos < total_utilizados) 
		}
			
		return (son_iguales);
	}
	
	/***********************************************************************/
	// Devuelve true si la secuencia est� vac�a

	bool EstaVacia (void) 
	{
		return (total_utilizados == 0);
	}
	
	/***********************************************************************/
				
};

///////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////

class TablaDentadaReales {
	
private:
	

private:

	static const int TAMANIO = 100; // N�mero de casillas disponibles
	SecuenciaReales vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas
	
public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	TablaDentadaReales (void) 	
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Devuelve el n�mero de casillas disponibles
	
	int Capacidad (void)
	{
		return (TAMANIO);
	}
	
	/*****************************************************************/
	// Devuelve cu�ntas filas hay en la tabla.

	int FilasUtilizadas (void)
	{
		return (total_utilizados);
	}
			
	/***********************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaReales"
	//
	// PRE: 0 <= indice_fila < filas_utilizadas

	SecuenciaReales Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}
	
	
	/***********************************************************************/
	// A�ade una secuencia a la tabla (al final)
	// Recibe: una_secuencia, la secuencia que se va a a�adir
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adici�n se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (SecuenciaReales una_secuencia)
	{
		if (total_utilizados < TAMANIO) {

			vector_privado[total_utilizados]=una_secuencia;
			
			total_utilizados++;
		}
	}
	
	/*****************************************************************/
	// Inserta una fila completa en una posici�n dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posici�n que ocupar� "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaReales. 
	//
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" ser� la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" ser� la nueva 
	//		 �ltima fila (el resultado ser� equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
	{
		// Comprobar precondiciones
		
		if ((total_utilizados < TAMANIO) && 
			(0<=num_fila) && (num_fila <=total_utilizados)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La �ltima fila se copia en una NUEVA FILA que ocupa la 
			// posici�n "filas_utilizadas", la pen�ltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todav�a) "filas_utilizadas" 
			
			for (int fil=total_utilizados; fil>num_fila; fil--) 
			
				vector_privado[fil] = vector_privado[fil-1]; 
				
					
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			vector_privado[num_fila]= fila_nueva;
						
			total_utilizados++; // Actualizaci�n del tama�o de la tabla.
					
		}
	}
	
	/***********************************************************************/
	// Eliminar la secuencia que se encuentra en la posici�n dada por "indice".
	// Realiza un borrado f�sico (con desplazamiento y sustituci�n).
	//
	// PRE: 0 <= indice < total_utilizados 
	
	void Elimina (int indice) 
	{
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posici�n a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posici�n del �ltimo 
    
			for (int i = indice ; i < tope ; i++) {
				vector_privado[i] = vector_privado[i+1];
	    	}
			total_utilizados--;    
		}
	}
			
	/***********************************************************************/
	// "Vac�a" una secuencia
	
	void EliminaTodos (void)
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Devuelve TRUE si la secuencia est� vac�a
	
	bool EstaVacia (void)
	{
		return (total_utilizados==0);
	}
	
	/***********************************************************************/
		
};
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// Mostrar un texto, precedido de un acompa�amiento

void MuestraTablaDentada (TablaDentadaReales tabla, string titulo)
{
	cout << endl;
	cout <<  titulo << endl; 	
	cout << endl;
	cout << "------------------------------------------------------" << endl; 
	
	int num_filas = tabla.FilasUtilizadas();
	
	for (int fila=0; fila<num_filas; fila++) {

		
		SecuenciaReales la_secuencia = tabla.Fila(fila);
		
		int num_datos = la_secuencia.TotalUtilizados();

		cout << "Secuencia " << setw(2) << fila+1; 
		cout << " (" << setw(2) << num_datos << " datos): "; 
			
		for (int num_dato=0; num_dato<num_datos; num_dato++) {
			double dato = la_secuencia.Elemento(num_dato);
			cout << setw(6) << setprecision(2) << dato;
		}
		cout << endl;
	}
	cout << "------------------------------------------------------" << endl; 	
	cout << endl << endl;	
	
}

/***************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 


	// La "TablaDentadaReales" que se va a formar. 
	// Inicialmente, vac�a. 
	
	TablaDentadaReales tabla; 


	// Leer los datos y formar la tabla
		
	cout << endl;
	cout << "Introduzca los valores: ";

	int num_secuencias;		// Primer valor: n�mero de secuencias
	cin >> num_secuencias;
	
	for (int num_sec=0; num_sec<num_secuencias; num_sec++) {

		// Para cada secuencia
		
		SecuenciaReales una_secuencia; // Inicialmente vac�a
		
		int num_datos;		// N�mero de datos que forman la secuencia
		cin >> num_datos;
		
		for (int num_dato=0; num_dato<num_datos; num_dato++) {
			
			// Para cada dato 
			
			double dato;	// Dato "num_dato" de la secuencia "num_sec"
			cin >> dato;
			
			una_secuencia.Aniade(dato); // A�adir dato a "una_secuencia"
		}
		
		tabla.Aniade(una_secuencia); // A�adir secuencia a "tabla"
	}
	

	// Mostrar los datos leidos
	
	MuestraTablaDentada (tabla, "Tabla leida."); 	
	
	
	// Calcular la suma de cada secuencia, guardando los resultados en 
	// una nueva secuencia de reales llamada "sumas"
	
	SecuenciaReales sumas; // Secuencia de sumas
		
	// Para cada secuencia, calcular la suma y a�adirla a "sumas"

	// N�mero de secuencias en "tabla" 
	int num_secuencias_en_tabla = tabla.FilasUtilizadas();
	
	for (int num_sec=0; num_sec<num_secuencias_en_tabla; num_sec++) {

		// Extraer una copia de la secuencia n�mero "num_sec" desde "tabla"
		SecuenciaReales una_secuencia = tabla.Fila(num_sec);
		
		double suma = 0.0; // Iniciar el acumulador 

		// N�mero de elementos de la secuencia actual
		int num_datos = una_secuencia.TotalUtilizados();

		// Sumar los elementos de la secuencia
		for (int num_dato=0; num_dato<num_datos; num_dato++) 
			suma += una_secuencia.Elemento(num_dato);
		
		// A�adir la suma a la secuencia de sumas
		sumas.Aniade(suma);
	}
	
	// Mostrar los valores de la secuencia "sumas"
	
	int num_sumas = sumas.TotalUtilizados();
	
	for (int n=0; n<num_sumas; n++) {
		
		double suma_secuencia_n = sumas.Elemento(n); 
		
		cout << "Suma de secuencia " << setw(2) << n+1; 
		cout << " = " << setw(6)<<setprecision(2) << suma_secuencia_n << endl;
	}		
	cout << endl;
	
	return (0);
}
