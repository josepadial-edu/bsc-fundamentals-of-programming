/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 13 Ejercicio 4
 
 Descripción:
 
Recupere
la solución del ejercicio 5 (Descodifica) de la relación de problemas IV. Implemente
el método de descodificación como un método de la clase SecuenciaCaracteres.
El método no modificará la secuencia de caracteres sobre la que se aplica, sino que
construirá y devolverá una nueva secuencia.
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
