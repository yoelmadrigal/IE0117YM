#include <stdio.h>

int encontrarMaximo (int arr[], int n) {
	int maximo = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] > maximo) {   //------> CAMBIO: Símbolo ´<´ reemplazado con ´>´
			maximo = arr[i];
		}
	}

	return maximo;
}

int main () {
	int numeros[] = {10, 20, 5, 40, 30};
	int n = sizeof(numeros) / sizeof(numeros[0]);
	int maximo = encontrarMaximo(numeros, n);
	printf("El número más grande es: %d\n", maximo);
	return 0;
}
