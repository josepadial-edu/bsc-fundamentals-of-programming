/*Nombre: Jos� Antonio Padial Molina
	Curso: 1�C
	Fecha: 05/10/2016
	Sesi�n 3 Ejercicio 28
*/

#include <iostream>
using namespace std;

int main(){

	long grande;	
	int chico, chico1, chico2;
	double real1, real2;
	double real, otro_real;


   cout.precision(15);

	// Apartado a

	chico1 = 1234567;
	chico2 = 1234567;
	chico = chico1 * chico2;

	cout << "Ejemplo de desbordamiento: \n\n";
	cout << "chico1 = "  << chico1 << "\n";
	cout << "chico2 = "  << chico2 << "\n";
	cout << "chico = chico1 * chico2 = " << chico;
	cout << "\n\nDeber�a dar 1524155677489" << "\n\n";


	/* El resultado es imposible de almacenar en un int
		por lo que el n�mero guardado es incorrecto, resultado de desbordamiento
		En la expresi�n chico1 * chico2 s�lo participan int, por lo que el resultado es int 
		El desbordamiento se produce por tanto al evaluar la expresi�n*/


	// Apartado b
	
	chico1 = 1234567;
	chico2 = 1234567;
	grande = chico1 * chico2;

	cout << "\nEjemplo de desbordamiento: \n\n";
	cout << "chico1 = "  << chico1 << "\n";
	cout << "chico2 = "  << chico2 << "\n";
	cout << "grande = chico1 * chico2 = " << grande;
	cout << "\n\nDeber�a dar 1524155677489" << "\n\n";
	
	/* El resultado es imposible de almacenar en un int
		por lo que el n�mero guardado es incorrecto, resultado de desbordamiento
		En la expresi�n chico1 * chico2 s�lo participan int, por lo que el resultado es int 
		El desbordamiento se produce por tanto al evaluar la expresi�n*/


	// Apartado c
	
	real1 = 123.1;
	real2 = 124.2;
	real = real1 * real2;
	
	cout << "Multiplicaci�n entre reales correcta.\nPero siempre asumimos errores de redondeo con los reales. \n\n";
	cout << "real1 = " <<  real1 << "\n";
	cout << "real2 = " <<  real2 << "\n";
	cout << "resultado = real1 * real2 = " <<  real;   //  15289.02
	cout << "\n\nDeber�a dar 15289.02" << "\n\n";
	cout << (real == 15289.02);

	// Correcto.
	

	// Apartado d

	real1 = 123456789.1;
	real2 = 123456789.2;
	real  = real1 * real2;

	cout << "Problema de precisi�n. El resultado tiene m�s de 16 d�gitos. \n\n";
	cout << "real1 = " << real1 << "\n";
	cout << "real2 = " << real2 << "\n";
	cout << "resultado = real1 * real2 = " << real ;  // 15241578787227558.0
	cout << "\n\nDeber�a dar 15241578787227557.72" << "\n\n";
 

	/* Hay un claro problema de precisi�n al tener el resultado m�s de 16 d�gitos.
		Deber�a dar: 15241578787227557.72*/
		

	// Apartado e


	real = 2e34;
	otro_real = real + 1;
	otro_real = otro_real - real;

	cout << "Problema de precisi�n. El resultado tiene m�s de 16 d�gitos. \n\n";
	cout << "real = " << real << "\n";
	cout << "otro_real = real + 1" << "\n";
	cout << "otro_real = otro_real - real = " << otro_real;   // 0.0
	cout << "\n\nDeber�a dar 1" << "\n\n";
 
	/* 
	El resultado no es 1 como cabr�a esperar sino 0, debido al problema 
	de la precisi�n al trabajar en coma flotante.
	*/
	
	// Apartado f

	real = 1e+300;
	otro_real = 1e+200;
	otro_real = otro_real * real;

	cout << "Problema de \"desbordamiento\" en reales --> Infinito. \n\n";
	cout << "otro_real = " << otro_real << "\n";
	cout << "real1 = " << real1 << "\n";
	cout << "resultado = otro_real * real1 = " << real;  // INF
	cout << "\n\nDeber�a dar 1e+500" << "\n\n"; 
	
	/* Infinito. Los reales en coma flotante no se "desbordan" de la misma forma que los int. 
		El resultado es infinito que es un valor espec�fico que se representa en coma flotante.*/

	
	//Apartado g

	float real_chico;
   double real_grande;

   real_grande = 2e+150;
   real_chico = real_grande;
   
	cout << "Problema de \"desbordamiento\" entre reales de distinto tama�o --> Infinito. \n\n";
	cout << "chico (float)  = " << real_chico << "\n";
	cout << "grande (double) = " << real_grande << "\n";
	cout << "chico = grande" <<  "\n";
	cout << "chico se queda con " << real_chico << "\n\n";  

	/* Infinito. Los reales en coma flotante no se "desbordan" de la misma forma que los int. 
		El resultado es infinito que es un valor espec�fico que se representa en coma flotante.*/
}

