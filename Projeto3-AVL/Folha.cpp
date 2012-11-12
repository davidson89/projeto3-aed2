#include <stddef.h>
#include "Folha.h"

Folha::Folha(int valor) {
    this->valor = valor;
    this->fatorCarga = 0;
    this->folhaDir = NULL;
    this->folhaEsq = NULL;
}