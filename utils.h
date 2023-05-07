#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef UTILS_H
#define UTILS_H

uint64_t calculaMDC(uint64_t totienteEuler, uint64_t e);
bool descobreRelativamentePrimo(uint64_t totienteEuler, uint64_t p, uint64_t q, uint64_t e);
bool checkPrimo(uint64_t num);
uint64_t exp_mod_rapida(uint64_t base, uint64_t exp, uint64_t mod);

#endif
