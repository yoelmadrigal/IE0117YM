/* Pseudocódigo de la función que encuentra la mayor secuencia de 1s consecutivos en 
 * el ejercicio 3 de la Práctica de Laboratorio #3
 * 
 * Bibliotecas a usar
 * INICIO
 *
 * 	- Función para generar una matriz cuadrada binaria con entradas y tamaño aleatorios {
 * 		 Generar un número aleatorio (1 o 0) para cada entrada de la matriz
 * 	}
 *
 * 	-Función para imprimir la matriz {
 * 		Cadena para imprimir entrada por entrada la matriz
 * 	}
 * 
 * 	- Función para encontrar la secuencia mayor {
 * 		Variable que guarde la secuencia mayor
 * 		- Establecer una coordenada de inicio para las diagonales {
 * 			Dar variables para contar la secuencia
 * 				Recorrer la diagonal e ir contando	
 *		}
 *			Pasar a la siguiente coordenada
 *		}
 * 		return secuencia mayor;
 * 	}
 *
 * 	- Función main() {
 * 		
 * 		Ejecutar función (generar matriz);
 * 		Ejecutar función (imprimir matriz);
 *
 * 		Ejecutar función (encontrar secuencia mayor);
 *		
 *		return 0;
 *	}
 * FIN
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

//Generar la matriz aleatoriamente
void gen_matriz(int matriz[SIZE][SIZE]) {
        srand(time(NULL));
        for (int i= 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                        matriz[i][j] = rand() % 2;
}

//Imprimir la matriz generada
void imp_matriz(int matriz[SIZE][SIZE]) {
        printf("La matriz utilizada es: \n");
        for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++)
                        printf("%d ", matriz[i][j]);
                printf("\n");
        }
}

//Encontrar la secuencia más larga de 1s
int findLargestLine(int matriz[SIZE][SIZE]) {
	int sec_mayor = 0;

	//Fijar punto de inicio de cada diagonal
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {

			//Reiniciar la secuencia
			if (matriz[i][j] == 1) {
				int fila = i;
				int columna = j;
				int sec_actual = 0;
			
				//Recorrer la diagonal a partir del punto de inicio
				while (fila < SIZE && columna < SIZE && matriz[fila][columna] == 1) {
					//Contar los 1s seguidos 
					sec_actual++;
					fila++;
					columna++;
				}
				if (sec_actual > sec_mayor)
					sec_mayor = sec_actual;
			}
		}
	}

	return sec_mayor;
}

//Función principal
int main() {
	int matrix[SIZE][SIZE];

	gen_matriz(matrix);
	imp_matriz(matrix);

	int largestLine = findLargestLine(matrix);
	printf("El tamaño de la secuencia de 1s más grande es: %d\n", largestLine);

	return 0;
}
