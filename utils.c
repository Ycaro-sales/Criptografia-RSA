#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

uint64_t calculaMDC(uint64_t totienteEuler, uint64_t e) {
  uint64_t resto;
  while (e != 0) {
    resto = totienteEuler % e;
    totienteEuler = e;
    e = resto;
  }
  return totienteEuler;
}

bool descobreRelativamentePrimo(uint64_t totienteEuler, uint64_t p, uint64_t q, uint64_t e){
  if (calculaMDC(totienteEuler, e) == 1 && e != p && e != q) {
    return true;
  } else {
    return false;
  }
}

bool checkPrimo(uint64_t num){
  if (num < 2) {
    return false;
  } else if (num == 2) {
    return true;
  } else if (num % 2 == 0) {
    return false;
  } else {
    for (int i = 3; i * i <= num; i += 2) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }
}

uint64_t exp_mod_rapida(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t resultado = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            resultado = (resultado * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
  return resultado;
}


