/*
 Nombre: Jos� Antonio Padial Molina
 Curso: 1�C
 Sesi�n: 13 Ejercicio 5
 
 Descripci�n:
 
Recupere la soluci�n del ejercicio 10 de la relaci�n de problemas IV (Moda).
Re-escriba el m�todo Moda de la siguiente forma:
 Use como dato local para guardar los caracteres procesados un objeto de la clase
SecuenciaCaracteres, en vez de un vector cl�sico de corchetes.
 Defina dentro de la clase SecuenciaCaracteres el m�todo
int NumeroOcurrencias(char buscado, int izda, int dcha)
que devuelve el n�mero de ocurrencias de un valor buscado entre las posiciones
izda y dcha de la secuencia. Llame a este m�todo dentro de Moda para calcular
las frecuencias de cada car�cter.
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
};

int main(){
	SecuenciaCaracteres calcular_moda;
	FrecuenciaDeCaracteres moda;
	int dcha, izda, ocurrencias;
	char caracter;
	
	calcular_moda.LeerTexto();
	calcular_moda.RellenarStruct();
	moda = calcular_moda.Moda();
	
	if(calcular_moda.GetUsadas() == 0){
		cout << "No se ha introducido ningun caracter " << endl;
	}
	else{
		cout << "\t\tBUSCAR OCURRENCIAS" << endl;
		cout << "Posici�n inicial a buscar --------> " << endl;
		cin >> izda;
		cout << "Posici�n final a buscar   --------> " << endl;
		cin >> dcha;
		cout << "Caracter a buscar     ------------> " << endl;
		cin >> caracter;
		
		ocurrencias = calcular_moda.NumeroOcurrencias(caracter, izda, dcha);
		cout << "El numero de veces que apacere " << caracter << " es -----> " << ocurrencias << endl;
		
		cout << "La letra que mas aparece es la -----> " << moda.caracter << endl;
		cout << "Su frecuencia de aparicion es  -----> " << moda.frecuencia << endl;
	}
	
	return 0;
}

