/* Pseudocódigo (ejercicio1)
 *
 * INICIO
 * 	-Función main() {
 * 		Declarar la matriz a utilizar (que sea variable en tamaño nxn)
 * 		Declarar las variables que se guardarán las sumas de ambas diagonales
 *		Cadena que pase por cada coordenada diagonal y que la sume a las variables {}
 *		Imprimir las variables con los resultados obtenidos
 *	}
 * FIN
 * */



#include <stdio.h>
#define DIMEN 5 // Esto define el tamaño de la matriz
#define MEDIDA 2 // Esto define la submatriz que se va a utilizar

int main() {
	int matriz[DIMEN][DIMEN] = {
		{1, 5, 3, 2, 5},
		{6, 7, 11, 19, 10},
		{11, 8, 13, 4, 15},
		{16, 17, 18, 17, 20},
		{6, 22, 23, 30, 2}
	};

	int diagonal1 = 0;
	int diagonal2 = 0;

	for (int i =0; i < MEDIDA; i++) {
		diagonal1 += matriz[i][i];
		diagonal2 += matriz[i][MEDIDA - 1 - i];
	}

	printf("La suma de la diagonal (izquierda a derecha) es: %d\n", diagonal1);
	printf("La suma de la diagonal (derecha a izquierda) es: %d\n", diagonal2);

	return 0;
}
