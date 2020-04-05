/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 7 Ejercicio 1
*/

/*
	///////////////MAL////////////////
	int ValorAbsoluto (int entero) {
		if (entero < 0)
			entero = -entero;
		else
		return entero;
	}
	
	///////////////BIEN////////////////
	int ValorAbsoluto (int entero) {
		if (entero < 0)
			entero = entero*-1;
		return entero;
	}
*/

/*
	///////////////MAL////////////////
	void Cuadrado (int entero) {
		return entero*entero;
	}
	
	///////////////BIEN////////////////
	void Cuadrado (int entero) {
		int cuadrado
		cuadrado = entero * entero;
		return cuadrado;
	}
*/

/*
	///////////////MAL////////////////
	void Imprime(double valor) {
		double valor;
		cout << valor;
	}
	
	///////////////BIEN////////////////
	void Imprime(double valor) {
		cout << valor;
	}
*/

/*
	///////////////MAL////////////////
	bool EsPositivo(int valor) {
		if (valor > 0)
			return true;
	}
	
	///////////////BIEN////////////////
	bool EsPositivo(int valor) {
		if (valor > 0)
			return true;
		return false;
	}
*/
