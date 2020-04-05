/*
 Nombre: Jos� Antonio Padial Molina
 Curso: 1�C
 Sesi�n: 13 Ejercicio 8
 
 Descripci�n:
 
Sobre la clase SecuenciaCaracteres, defina un
m�todo que inserte otra secuencia a partir de una posici�n.
Implemente este m�todo utilizando el m�todo visto en clase que insertaba un �nico
car�cter:
void Inserta(int pos_insercion, char valor_nuevo)
Tendr� que llamar a este m�todo para insertar, uno a uno, todos los caracteres de la
nueva secuencia.
Construya un programa para que lea los caracteres de la primera secuencia (hasta
el terminador #), los caracteres de la segunda (hasta el terminador #), la posici�n de
inserci�n e imprima el resultado de insertar la segunda dentro de la primera, a partir
de la posici�n indicada.
Observe que este algoritmo es bastante ineficiente ya que el algoritmo se reduce a la
ejecuci�n de un bucle anidado en otro. En el ejercicio 9 se pide una versi�n eficiente.
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
			int pos_copia = pos;
			texto[texto.size()] = ' ';
			texto.resize(texto.size()+1);
			for(int i = 0; i < nueva_cadena.size(); i++){
				InsertaUnValor(pos_copia, nueva_cadena[i]);
				pos_copia++;
			}
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

