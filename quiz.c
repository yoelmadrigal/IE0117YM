#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Guardar memoria dinámica
void allocateMatrix  (int ***matrix, int filas, int columnas) {
        *matrix = malloc(size * sizeof(int *));
        for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
                	*(*(matrix + i) + j) = malloc(filas * sizeof(int));
	}
}
//CAMBIAR!!!!

//Generar matriz inicial
void fillMatrix(int **matrix, int filas, int columnas) {
        srand(time(NULL));
        for (int i= 0; i < filas; i++)
                for (int j = 0; j < columnas; j++)
                        *(*(matrix + i) + j) = rand() % 9;
}

//Imprimir la matriz generada 	CAMBIAR!!!!!	
void printMatrix(int **matrix, int size) {
        printf("Matrix (%dx%d): \n", size, size);
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        printf("%d ", *(*(matrix + i) + j));
                }
                printf("\n");
        }
}


//Cambiar el tamaño de la matriz
void changeMatrix(int **matrix, int filas, int columnas, int filas2, int columnas2) {
	printf("Indique la cantidad nueva de filas: ");
	scanf("%d", &filas2);
	printf("Indique la cantidad nueva de columnas: ");
	scanf("%d", &columnas2);
	srand(time(NULL));
	if (filas2 < filas) {
		for (i = filas2; i < filas; i++) {
			free(matrix[i]);
		}
	}
	if (columnas2 < columnas ) {
		for (j = columnas2; j < columnas; j++) {
			free(matrix[][j]);
		}
	}
	if (filas2 > filas || columnas2 > columnas) {
		realloc
		for (int i = filas + 1; i < filas2; i++) {
			for (int j = columnas + 1 < columnas2; j++) {
				*(*(matriz + i) + j) = rand() % 9
			}
		}
	}
}

// Liberar la memoria dinámica usada
void freeMatrix(int **matrix, int size) {
        for (int i = 0; i < size; i++)
                free(matrix[i]);
        free(matrix);
}



int main() {
        int size, largestLine ;
        int **matrix = NULL;

        fillMatrix(matrix, size);
        return 0;
}


