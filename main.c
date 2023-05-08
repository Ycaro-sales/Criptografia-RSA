#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "core/gerador_de_chaves.h"
#include "core/encriptar.h"
#include "core/desencriptar.h"

int main() {
  while(true){
    int escolha=0;

    printf("\nDIGITE UM DOS NÚMEROS:\n1 - Gerar chave pública\n2 - Encriptar\n3 - Desencriptar\n");

    scanf("%d", &escolha);

    switch (escolha) {
      default:
        printf("Número inválido, tente novamente!\n");
		escolha = 0;
        continue;
      case 1:
        chavePublica();
		printf("Chave pública gerada com sucesso!\n");
		printf("\nVocê pode encontrar a chave pública no arquivo 'chave_publica.txt'\n");
		printf("\nVocê deseja fazer outra operação? (1 - Sim | 2 - Não)\n");
		scanf("%d", &escolha);
		if(escolha == 1){
			continue;
		} else {
			break;
		}
      case 2:
        encriptar();
		printf("\nEncriptação realizada com sucesso!\n");
		printf("\nVocê deseja fazer outra operação? (1 - Sim | 2 - Não)\n");
		scanf("%d", &escolha);
		if(escolha == 1){
			continue;
		} else {
			break;
		}
      case 3:
        desencriptar();
		printf("\nDesencriptação realizada com sucesso!\n");
		printf("\nVocê deseja fazer outra operação? (1 - Sim | 2 - Não)\n");
		scanf("%d", &escolha);
		if(escolha == 1){
			continue;
		} else {
			break;
		}
        break;
    }
    break;
  }
  
  return 0;
}
