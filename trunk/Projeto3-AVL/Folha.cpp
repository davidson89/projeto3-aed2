/* 
 * File:   Folha.cpp
 * Author: davidson
 * 
 * Created on 31 de Outubro de 2012, 22:22
 */

#include <stddef.h>

#include "Folha.h"

Folha::Folha(int valor) {
    this->valor = valor;
    this->fatorCarga = 0;
    this->folhaDir = NULL;
    this->folhaEsq = NULL;
}


Folha::Folha(const Folha& orig) {
}


Folha::~Folha() {
}

