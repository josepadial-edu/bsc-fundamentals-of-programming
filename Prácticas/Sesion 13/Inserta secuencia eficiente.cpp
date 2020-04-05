/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 13 Ejercicio 8
 
 Descripción:
 
Implemente el método del ejercicio 8 de una forma eficiente
con un único bucle (sin tener que llamar al método de inserción de un carácter)
*/

#include <iostream>

using namespace std;

// Estructura de una frecuancia de caracteres
struct FrecuenciaDeCaracteres{
	char caracter;
	int frecuencia;

	FrecuenciaDeCaracteres(){
		caracter = 0;
		frecuencia = 0;
	}
};

class SecuenciaCaracteres{
	private:
		static const int MAX = ('Z' - 'A') * 2;
		string texto;
		FrecuenciaDeCaracteres caracteres[MAX];
		char letras_usadas[MAX];
		int indice_usadas = 0;
		char TERMINADOR = '#';
	public:
		SecuenciaCaracteres(){
			texto = "";
			
			for(int i = 0; i < MAX; i++){
				letras_usadas[i] = 0;
			}
		}

		string GetTexto(){
			return texto;
		}

		void LeerTexto(){
			getline(cin, texto, TERMINADOR);
		}
		
		void RellenarStruct(){
			int pos = 0;
		   bool buscar = false;
		    
			for(int i = 0; i < texto.size(); i++){
		      buscar = false;
				if((texto[i] >= 'A' && texto[i] <= 'Z') || (texto[i] >= 'a' && texto[i] <= 'z')){
					for(int j = 0; j < indice_usadas; j++){
						if(caracteres[j].caracter == texto[i])
							buscar = true;
					}
					if(buscar == true){
						for(int z = 0; z < indice_usadas; z++){
							if(caracteres[z].caracter == texto[i]){
								pos = z;
							}		
						}
						if(pos >= 0)
							caracteres[pos].frecuencia++;
					}
					else{
						letras_usadas[indice_usadas] = texto[i];
						caracteres[indice_usadas].caracter = texto[i];
						caracteres[indice_usadas].frecuencia++;
						indice_usadas++;
					}
				}
			}
		}
		
		FrecuenciaDeCaracteres Moda(){
			FrecuenciaDeCaracteres moda;
			int max = 0;
			for(int i = 1; i < indice_usadas; i++)
				if(caracteres[max].frecuencia < caracteres[i].frecuencia)
					max = i;
					
			moda = caracteres[max];
			return moda;
		}
		
		int GetUsadas(){
			return indice_usadas;
		}
		
		int NumeroOcurrencias(char buscado, int izda, int dcha){
			int esta = 0;
			for(int i = izda; i < dcha; i++){
				if(texto[i] == buscado)
					esta++;
			}
			return esta;
		}

		void InsertaUnValor(int pos_insercion, char valor_nuevo){
			for (int i = texto.size() ; i > pos_insercion ; i--)
				texto[i] = texto[i-1];

			texto[pos_insercion] = valor_nuevo;
			texto.resize(texto.size()+1);
		}

		void InsertaCadena(int pos, string nueva_cadena){
			int longitud = texto.size();
			int pos_insercion = 0;
			string nuevo_texto = "";

			if(pos > longitud)
				pos_insercion = longitud;
			else
				pos_insercion = pos;

			nuevo_texto += texto.substr(0,pos);
			nuevo_texto += nueva_cadena;
			nuevo_texto += texto.substr(pos, longitud - pos);
			
			texto = nuevo_texto;
		}
};

int main(){
	SecuenciaCaracteres texto_original;
	SecuenciaCaracteres texto_insertar;
	int posicion_inicial;

	texto_original.LeerTexto();
	texto_original.RellenarStruct();
	texto_insertar.LeerTexto();
	texto_insertar.RellenarStruct();
	
	if((texto_insertar.GetUsadas() == 0) || (texto_original.GetUsadas() == 0)){
		cout << "No se ha introducido bien las cadenas " << endl;
	}
	else{
		cin >> posicion_inicial;
		texto_original.InsertaCadena(posicion_inicial, texto_insertar.GetTexto());

		cout << "\nEl texto modificado es -----> " << texto_original.GetTexto();
	}
	
	return 0;
}

