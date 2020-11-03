#include "Langford.h"

//Precondicion: -
//Postcondicion: Devuelve true si los valores de n se repiten dos veces en el array.
bool ElementosLangfordValidos(int secuencia[], int n);

//Precondicion:-
//Postcondicion: Valida si la posicion de los numeros corresponde a una secuencia Langford.
bool PatronLangfordValido(int secuenciaNumeros[], int n);

int ContarApariciones(int elementos[], int elementoBuscado, int n);

// O(N)
int ContarApariciones(int elementos[], int elementoBuscado, int tope) {
	int repeticiones = 0;
	for (int i = 0; i < tope; i++) {
		if (elementos[i] == elementoBuscado) {
			repeticiones++;
		}
	}

	return repeticiones;
}

// O(N*N)
bool ElementosLangfordValidos(int secuencia[], int n) {
	bool elementosLangforValidos = true;
	for (int elemento = 1; elemento <= n && elementosLangforValidos; ++elemento) {
		elementosLangforValidos = ContarApariciones(secuencia, elemento, 2 * n) == 2;
	}

	return elementosLangforValidos;
}

bool ExisteSecuenciaLangford(int n) {
	int modulo4 = n % 4;
	return modulo4 == 0 || modulo4 == 3;
}

// Diseno de Codigo
// - Claro y Simple
// - - - Legibilidad: Escribir codigo Regular, Seguir las convenciones de nombramiento
// - - - Nombramientos (variables como de funciones) tienen que tener sentido
// - - - Simetria
// - - - Las funciones deben cumplir 3 cosas: - Deben hacer una sola cosa, - La deben hacer bien, - Eso se debe hacer en un solo lugar
// - INVARIANTES en un algoritmo
// Claramente es repetitivo que ambas funciones busquen los valores en el Array completo
// Uno para validar los duplicados y el otro para ver si estan en posicion correcta
// Cual seria la forma mas adecuada para ahorrarse esa busqueda duplicada?
// Clara y simple:  O((N*N) + (N*N))== O(2*(N*N))
// Optimizada prematuramente: O(N)
bool EsSecuenciaLangford(int secuenciaNumeros[], int n) {
	bool esSecuenciaLangford = false;
	if (ExisteSecuenciaLangford(n)) {
		esSecuenciaLangford = ElementosLangfordValidos(secuenciaNumeros, n) && PatronLangfordValido(secuenciaNumeros, n);
	}

	return esSecuenciaLangford;
}

bool PatronLangfordValido(int secuenciaNumeros[], int n) {
	int Valor1 = -1;
	bool DistanciaN = true;
	int TOPE = 2 * n;
	int i;
	do {
		for (i = 0; i < TOPE; i++) {

			if (secuenciaNumeros[i] == n) {
				if (Valor1 != -1 && secuenciaNumeros[Valor1] == secuenciaNumeros[Valor1 + n]) {
					DistanciaN = false;
				}
				else {
					Valor1 = i;
				}

			}
		}
		Valor1 = -1;
		n--;
	} while (DistanciaN && n > 0);

	return DistanciaN;
}

