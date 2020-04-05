/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 11 Ejercicio 5
 
 Descripción:
 
Dado un vector de caracteres que contiene un
mensaje cifrado, se pide construir otro vector nuevo con el mensaje descifrado. La
forma de descifrado consiste en coger la primera y última letra de cada palabra. Las
palabras están separadas por uno o más espacios en blanco o el final del vector. Si
la última palabra no tiene espacios en blanco a su derecha, se coge sólo el primer
carácter.
Por ejemplo, si denotamos el inicio y final de la secuencia con un corchete, entonces:
[ Hidrógeno limpia ] se descodificaría como [Hola]
Reserve memoria para trabajar con un máximo de 1000 caracteres.
Para leer el mensaje cifrado debe leer caracteres con cin.get() (repase lo visto al
inicio de esta relación de problemas) hasta que el usuario introduzca el carácter #. A
continuación, el programa mostrará la cadena descodificada.
Ejemplo de entrada: [Hidrógeno limpia ] .... Salida correcta: [Hola]
Ejemplo de entrada: [Hidrógeno limpia] .... Salida correcta: [Hol]
Ejemplo de entrada: [Hidrógeno] .... Salida correcta: [H]
Ejemplo de entrada: [Hidrógeno ] .... Salida correcta: [Ho]
Ejemplo de entrada: [H] .... Salida correcta: [H]
Ejemplo de entrada: [H ] .... Salida correcta: [H]
*/

#include<iostream>
#include<string>
using namespace std;

const char TERMINADOR = '#';

class SecuenciaCaracteres{
	private:
		static const int TAMANIO = 1000;
		char vector_privado[TAMANIO];
		int total_utilizados = 0; 
	public:
		int TotalUtilizados(){
			return total_utilizados;
		}
		int Capacidad(){
			return TAMANIO;
		}
		void Aniade(char caracter){
			if(total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = caracter;
				total_utilizados++;
			}
		}
		void AniadeString(string cadena){
			int tope = cadena.size();
			
			for(int i = 0; i < tope; i++)
				Aniade(cadena[i]);
		}
		char Elemento(int pos){
			return vector_privado[pos];
		}
		void EliminaTodos(){
			total_utilizados = 0;
		}
		string ToString(){
			string cadena = "";
			
			for(int i = 0; i < total_utilizados; i++)
				cadena += vector_privado[i];
				
			return cadena;
		}
		SecuenciaCaracteres Descodifica(){
			SecuenciaCaracteres descodificada;
			int i, siguiente;
			bool empiezo_palabra;
			
			i = 0;
			empiezo_palabra = true;
			
			while(i < total_utilizados){
				siguiente = i+1;
				
				if(vector_privado[i] != ' '){
					if (empiezo_palabra ||(siguiente < total_utilizados && vector_privado[siguiente] == ' '))
						descodificada.Aniade(vector_privado[i]);
						
					empiezo_palabra = false;
				}
				else
					empiezo_palabra = true;
					
				i = siguiente;
			}
			
			return descodificada;
		}
};

int main(){
   int numero_caracteres_introducidos;
   SecuenciaCaracteres secuencia;
   int maximo_numero_caracteres;
   char caracter;
   SecuenciaCaracteres descodificada;
	
	maximo_numero_caracteres = descodificada.Capacidad();
	numero_caracteres_introducidos = 0;
	
	caracter = cin.get();
	while(caracter != TERMINADOR && numero_caracteres_introducidos < maximo_numero_caracteres){
		secuencia.Aniade(caracter);
		numero_caracteres_introducidos++;
		caracter = cin.get();	
	}
	
	descodificada = secuencia.Descodifica();
	
	cout << descodificada.ToString();
}
