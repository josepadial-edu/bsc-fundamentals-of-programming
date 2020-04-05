/*
 Nombre: Jos� Antonio Padial Molina
 Curso: 1�C
 Sesi�n: 12 Ejercicio 12
 
 Descripci�n:
 
Recupere la soluci�n del ejercicio 4. Defina el m�todo Moda dentro de
la clase SecuenciaCaracteres. Este m�todo debe devolver un dato de tipo
FrecuenciaCaracter (struct) Apl�quelo sobre el texto del Quijote sin espacios
en blanco.Sobre la clase SecuenciaCaracteres, a�ada el m�todo
EliminaOcurrencias para eliminar todas las apariciones de un determinado car�cter
a_borrar. Por ejemplo, despu�s de eliminar el car�cter 'o' de la secuencia
{'S','o','Y',' ','y','o'}, �sta debe quedarse con {'S','Y',' ','y'}.
Un primer algoritmo para resolver este problema ser�a el siguiente (en ejercicios posteriores
se ver�n m�todos m�s eficientes):
Recorrer todas las componentes de la secuencia
Si la componente es igual al car�cter a_borrar, eliminarla
(desplazando hacia la izda las componentes que hay a su dcha)
Queremos implementarlo llamando al m�todo Elimina (que borra un �nico car�cter)
La implementaci�n de este m�todo se ha visto en clase de teor�a.
class SecuenciaCaracteres{
	.........
	void EliminaOcurrenciasERROR(){
		for (int i = 0; i < total_utilizados; i++)
			if (vector_privado[i] == a_borrar)
				Elimina(i);
	}
};
El anterior c�digo tiene un fallo. �Cu�l? Pru�belo con cualquier secuencia que tenga
el car�cter a borrar dos veces consecutivas. Proponga una soluci�n e implem�ntela.
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
		int total_eliminados = 0;
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
		
		void Elimina(int posicion){
			int total_utilizados = texto.size();
			if (posicion >= 0 && posicion < total_utilizados){
				int tope = total_utilizados-1;
				for (int i = posicion ; i < tope ; i++)
					texto[i] = texto[i+1];
					total_utilizados--;
					total_eliminados++;
			}
		}
		
		void EliminaOcurrencias(char caracter_a_borrar){
			for(int i = 0; i < texto.size(); i++){
				if(texto[i] == caracter_a_borrar)
					Elimina(i);
			}
		}
		
		void EliminaBloque(int pos_ini, int pos_fin){
			int i = pos_ini;
			while(i <= pos_fin){
					Elimina(pos_ini);
					i++;
			}
		}
		
		string Imprimir(){
			texto.resize(texto.size()-total_eliminados);
			for(int i=0; i < texto.size(); i++)
				texto[i] = texto[i];
			
			return texto;
		}
		
		int TamanioTexto(){
			return texto.size();
		}
		
		int LeeIntRango(int min, int max, string mensaje) {
		   int a_leer;
		   
		   do{
		      cout << mensaje << endl;
		      cin >> a_leer;
		   }while (min > a_leer || max < a_leer);
		   
		   return a_leer;
		}
		
		int LeeIntMayorIgualQue(int minimo, string mensaje){
		   int a_leer;
		
		   do{
		      cout << mensaje << endl;
		      cin >> a_leer;
		   }while (minimo > a_leer);
		
		   return a_leer;
		}
		
		int GetUsadas(){
			return indice_usadas;
		}
};

int main(){
	SecuenciaCaracteres calcular_moda;
	FrecuenciaDeCaracteres moda;
	int pos_ini, pos_fin;
	
	calcular_moda.LeerTexto();
	calcular_moda.RellenarStruct();
	moda = calcular_moda.Moda();
	
	if(calcular_moda.GetUsadas() == 0){
		cout << "No se ha introducido ningun caracter " << endl;
	}
	else{
		pos_ini = calcular_moda.LeeIntRango(0, calcular_moda.TamanioTexto(), "Introduzca un valor inicial");
		pos_fin = calcular_moda.LeeIntMayorIgualQue(pos_ini, "\nIntroduzca un valor final");
		
		calcular_moda.EliminaBloque(pos_ini, pos_fin);
		
		cout << "La letra que mas aparece es la ---> " << moda.caracter << endl;
		cout << "Su frecuencia de aparicion es ------> " << moda.frecuencia << endl;
		cout << "El texto con el caracter borrado es ------> " << calcular_moda.Imprimir() << endl;
	}
	
	return 0;
}
