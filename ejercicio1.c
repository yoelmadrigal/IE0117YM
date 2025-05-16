#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Reservar memoria dinámica para la matriz
void allocateMatrix  (int ***matrix, int size) {
	*matrix = malloc(size * sizeof(int *));
	for (int i = 0; i < size; i++) {
		*(*matrix + i) = malloc(size * sizeof(int));
	}
}


//Llenar la matriz aleatoriamente
void fillMatrix(int **matrix, int size) {
        srand(time(NULL));
        for (int i= 0; i < size; i++)
                for (int j = 0; j < size; j++)
                        *(*(matrix + i) + j) = rand() % 2;
}

//Imprimir la matriz generada
void printMatrix(int **matrix, int size) {
        printf("Matrix (%dx%d): \n", size, size);
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        printf("%d ", *(*(matrix + i) + j));
		}
                printf("\n");
        }
}



//Encontrar la secuencia más larga de 1s
void findLargestLine(int **matrix, int size, int *result) {
	int sec_actual = 0;
	*result = 0;

	//Fijar punto de inicio y contar en adelante
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int *coordenada = *(matrix + i) + j;
			if (*coordenada == 1) {
				sec_actual++;
				if (sec_actual > *result)
					*result = sec_actual;
			} else {
				sec_actual = 0;
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

//Función principal
int main() {
	int size, largestLine ;
	int **matrix = NULL;

	printf("Ingrese el tamaño de la matriz; ");
	scanf("%d", &size);

	allocateMatrix(&matrix, size);
	fillMatrix(matrix, size);
	printMatrix(matrix, size);

	findLargestLine(matrix, size, &largestLine);
	printf("La secuencia de 1s más grande es: %d\n", largestLine);
	
	freeMatrix(matrix, size);

	return 0;
}
