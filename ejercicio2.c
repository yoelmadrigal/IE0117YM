#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Buscar palíndromos palabra por palabra
int palind(char *palabra) {
	int i = 0, j = strlen(palabra) - 1;
	while (i < j) {
		if (palabra[i] != palabra[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}

//Pasar las palabras a letras minúsculas
void limpiar_palabra(char *cambiada, const char *original) {
	int j = 0;
	for (int i = 0; original[i] != '\0'; i++) {
		if(isalnum(original[i]))
			cambiada[j++] = tolower(original[i]);
	}
	cambiada[j] = '\0';
}


int main() {
	FILE *archivo = fopen("input.txt", "r");
	if (!archivo) {
		perror("El archivo no existe o no se puede abrir");
		return 1;
	}

	char palabra[256];
	char limpia[256];
	char larga[256] = "";
	
	while (fscanf(archivo, "%255s", palabra) == 1) {
		limpiar_palabra(limpia, palabra);
		if (palind(limpia) && strlen(limpia) > strlen(larga))
			strcpy(larga, limpia);
	}
	printf("El palíndrimo más largo es: %s\n", larga);
	fclose(archivo);

	return 0;
}
