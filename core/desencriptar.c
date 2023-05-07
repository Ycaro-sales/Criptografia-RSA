#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "../utils.h"
#include "gerador_de_chaves.c"

void desencriptar(){
    FILE *mensagemEncriptada;
    FILE *mensagemDesencriptada;
    mensagemEncriptada = fopen("mensagemEncriptada.txt", "r");
    mensagemDesencriptada = fopen("mensagemDesencriptada.txt", "w");
    uint64_t  num, p, q, n;
    int64_t d, phi, e;
  
    printf("\nDigite o P: ");
    scanf("%lu", &p);

    printf("\nDigite o Q: ");
    scanf("%lu", &q);
  
    printf("\nDigite o E: ");
    scanf("%ld", &e);
  
    phi = (p-1)*(q-1);
  
    d = calcular_chave_privada(e, phi);
    n = p * q;

    fscanf(mensagemEncriptada, "%lu", &num);
    
    while(!feof(mensagemEncriptada)){
        
        char caracter;
        int decripted_num = exp_mod_rapida(num, d, n);
        
        if (decripted_num == 28){
            caracter = 32;
        }
        else {
            caracter = decripted_num + 63;
        }
        fprintf(mensagemDesencriptada,"%c", caracter);
        fscanf(mensagemEncriptada, "%llu", &num);
    }
    fclose(mensagemDesencriptada);
    fclose(mensagemEncriptada);
}
