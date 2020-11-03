/*
 * Precondicion: @secuenciaNumeros es un array de tamaño igual al doble del parametro @n
 * Postcondicion: Devuelve true si @secuenciaNumeros es un patron de Langford caso contrario devuelve false.
 * Es decir que debe validar las doscondiciones del patron de Langford: los elementos presentes (que sean los determinados por 2N) y la posicion en donde se encuentran
 * Ejemplo 1:
 * Al invocarse con EsSecuenciaLangford([2,1,1,3], 2)
 * No cumple las validaciones respecto de los elementos presentes en @secuenciaNumeros. Para que cumpla esta validacion se esperaria que en lugar del 3 este el 2.
 * Por lo tanto devuelve false.
 *
 * Ejemplo 2:
 * Al invocarse con EsSecuenciaLangford([2,1,1,2], 2)
 * Cumple con las validaciones respecto de los elementos presentes en @secuenciaNumeros (hay dos de cada uno).
 * No cumple con la validacion respecto del orden de la secuencia.
 *
 * Ejemplo 3:
 * Al invocarse con EsSecuenciaLangford([2 3 1 2 1 3], 3)
 * Cumple con todas las validaciones
 *
 */
bool EsSecuenciaLangford(int secuenciaNumeros[], int n);

