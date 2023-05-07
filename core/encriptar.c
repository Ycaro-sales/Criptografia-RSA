#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"

#define MAX 1000000

void encriptar() {
	char mensagem[MAX];
	int mensagemEncriptada;
	uint64_t n, e;
	FILE *arquivoEncriptado = fopen("mensagemEncriptada.txt", "w");

	printf("Digite a mensagem a encriptar: ");
	scanf(" %[^\n]", mensagem);

	printf("Digite a chave publica (N e E): ");
	scanf("%lu%lu", &n, &e);

	for(int i = 0; i < strlen(mensagem); i++) {
		if (mensagem[i] == ' ') {
			mensagemEncriptada = exp_mod_rapida(28, e, n);

			fprintf(arquivoEncriptado, "%d ", mensagemEncriptada);
		} else {
			mensagemEncriptada = exp_mod_rapida((int)mensagem[i] - 63, e,n);
			fprintf(arquivoEncriptado, "%d ", mensagemEncriptada);
		}
	}

	fclose(arquivoEncriptado);
}


