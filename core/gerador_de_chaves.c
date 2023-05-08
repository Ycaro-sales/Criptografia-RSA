#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "../utils.h"

int64_t calcular_chave_privada(uint64_t e, uint64_t phi) {
	int64_t d = 0;
	int64_t x1 = 0, x2 = 1, y1 = 1, y2 = 0;
	int64_t q, r, x, y, phi_inicial = phi;
	while (phi != 0) {
		q = e / phi;
		r = e % phi;
		x = x2 - q * x1;
		y = y2 - q * y1;
		e = phi;
		phi = r;
		x2 = x1;
		x1 = x;
		y2 = y1;
		y1 = y;
	}

	d = x2;
	if (d < 0){
		for (int i = 1;d < 0;i++){
			d += phi_inicial*i;
		}
	}

	return d;
}

void chavePublica() {
	FILE *chave_publica;
	uint64_t p, q, n, e, totienteEuler;

	do {
		printf("Digite o 1° numero primo: ");
		scanf("%lu", &p);

		if (!checkPrimo(p)){
			printf("O número digitado não é primo!\n");
		}
	} while(!checkPrimo(p));

	do {
		printf("Digite o 2° numero primo: ");
		scanf("%lu", &q);
		checkPrimo(q);    

		if (!checkPrimo(p)){
			printf("O número digitado não é primo!\n");
		}
	} while(!checkPrimo(q));

	n = p * q;
	totienteEuler = (p-1)*(q-1);

	do {
		printf("\n\nAgora digite um expoente relativamente primo a %lu:", totienteEuler);
		scanf("%ld", &e);

		if (!checkPrimo(e)){
			printf("\nO número digitado não é primo!\n");
		} else if (!descobreRelativamentePrimo(totienteEuler, p, q, e)){
			printf("\nO número digitado não é relativamente primo!\n");
		}
	} while (!checkPrimo(e) || !descobreRelativamentePrimo(totienteEuler, p, q, e));

	chave_publica = fopen("public_key.txt", "w"); 
	fprintf(chave_publica, "Sua chave pública: (%lu, %lu)", n, e);
	fclose(chave_publica);
}

