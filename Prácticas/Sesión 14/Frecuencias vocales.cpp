#include <iostream>

using namespace std;

typedef char Matriz;

struct FrecuenciaDeCaracteres{
    char caracter;
    int frecuencia;
    FrecuenciaDeCaracteres(char letra): caracter(letra), frecuencia(0){}
};

int main(){
	//Constantes
	const char TERMINADOR = '#';
	const int MAX_VOCALES = 5;
    // Variables  
    char texto[100];
    int util_utilizados = 0;
    
    FrecuenciaDeCaracteres vocales[MAX_VOCALES] = {'a','e','i','o','u'};
    
    // Para leer la cadena
    do{
        cin.get(texto[util_utilizados]);
    }while(texto[util_utilizados++]!= TERMINADOR);
    cin.ignore(256,'\n');
    //////////////////////
    
    // Obtener frecuencias
    int contador = 0;
    do{
        if(texto[contador] == 'a')
        	vocales[0].frecuencia++;
        if(texto[contador] == 'e')
        	vocales[1].frecuencia++;
		if(texto[contador] == 'i')
			vocales[2].frecuencia++;
		if(texto[contador] == 'o')
			vocales[3].frecuencia++;
		if(texto[contador] == 'u')
			vocales[4].frecuencia++;    
    }while(texto[contador++] != TERMINADOR);
    //////////////////////
    
    // Obtener la frecuencia mas alta
    int mayor = vocales[0].frecuencia;
	
	for(int i = 1; i < MAX_VOCALES; i++){
		if(mayor < vocales[i].frecuencia){
			mayor = vocales[i].frecuencia;
		}
	}
    //////////////////////
    
    // Vuelco los resultados en una matriz
    Matriz matriz[mayor][5];
    
    for(int i = mayor; i > 0; i--){
		for(int j = 0; j < MAX_VOCALES; j++){
			if(i <= vocales[j].frecuencia)
				matriz[i-1][j] = '*';
			else
				matriz[i-1][j] = ' ';
		}
	}    
    //////////////////////
    
    // Muesro la grafica
    for(int i = mayor; i > 0; i--){
    	cout << i << " ";
		for(int j = 0; j < MAX_VOCALES; j++){
			cout << matriz[i-1][j] << " ";
		}
		cout << endl;
	}
	cout << "  a e i o u" << endl; 
    //////////////////////
    
    return 0;
}
