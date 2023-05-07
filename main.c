#include <stdio.h>
#include <math.h>
#include <string.h>
#include "core/gerador_de_chaves.c"
#include "core/encriptar.c"
#include "core/desencriptar.c"

int main() {
  while(true){
    int escolha=0;

    printf("DIGITE UM DOS NÚMEROS:\n1 - Gerar chave pública\n2 - Encriptar\n3 - Desencriptar\n");

    scanf("%d", &escolha);

    switch (escolha) {
      default:
        printf("Número inválido, tente novamente!\n");
        continue;
      case 1:
        chavePublica();
        break;
      case 2:
        encriptar();
        break;
      case 3:
        desencriptar();
        break;
    }
    break;
  }
  
  return 0;
}
