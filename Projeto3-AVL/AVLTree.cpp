/* 
 * File:   AVLTree.cpp
 * Author: davidson
 * 
 * Created on 31 de Outubro de 2012, 22:34
 */

#include <stddef.h>

#include "AVLTree.h"
#include "Folha.h"
#include <iostream>

AVLTree::AVLTree() {
    this->raiz = NULL;
}

void AVLTree::add(int valor) {
    if (this->raiz == NULL) {
        criaRaiz(valor);
    } else {
        this->raiz = insereRecursivamente(this->raiz, valor);
    }
}

void AVLTree::printTree(Folha *folha) {
    if (folha != NULL) {
        cout << "{" << folha->valor << ",";
        printTree(folha->folhaEsq);
        cout << ",";
        printTree(folha->folhaDir);
        cout << "}";
    } else {
        cout << "{}";
    }
}

void AVLTree::criaRaiz(int valor) {
    this->raiz = new Folha(valor);
}

Folha* AVLTree::insereRecursivamente(Folha* folha, int valor) {
    if (folha->valor > valor && folha->folhaEsq == NULL) {
        Folha *newFolha = new Folha(valor);
        folha->folhaEsq = newFolha;
    } else if (folha->valor < valor && folha->folhaDir == NULL) {
        Folha *newFolha = new Folha(valor);
        folha->folhaDir = newFolha;
    } else if (folha->valor > valor) {
        insereRecursivamente(folha->folhaEsq, valor);
    } else if (folha->valor < valor) {
        insereRecursivamente(folha->folhaDir, valor);
    }
    return atualizaFatorCarga(folha);
}

Folha* AVLTree::atualizaFatorCarga(Folha* folha) {
    folha->fatorCarga = calculaAltura(folha->folhaDir) - calculaAltura(folha->folhaEsq);

    if (folha->fatorCarga == 2) {
        if (folha->folhaDir->fatorCarga > 0) {
            folha = rotacionaParaEsquerda(folha);
            //verificar como atualizar fatorCarga
        } else {
            folha = rotacaoDuplaEsquerda(folha);
            //verificar como atualizar fatorCarga
        }
    } else if (folha->fatorCarga == -2) {
        if (folha->folhaEsq->fatorCarga < 0) {
            folha = rotacionaParaDireita(folha);
        } else {
            folha = rotacaoDuplaDireita(folha);
        }
    }
    return folha;
}

Folha* AVLTree::rotacionaParaDireita(Folha* folha) {
    Folha* folha2 = folha->folhaEsq;
    if (folha2->folhaDir) folha->folhaEsq = folha2->folhaDir;
    else folha->folhaEsq = NULL;
    folha2->folhaDir = folha;
    return folha2;
}

Folha* AVLTree::rotacionaParaEsquerda(Folha* folha) {
    Folha* folha2 = folha->folhaDir;
    if (folha2->folhaEsq) folha->folhaDir = folha2->folhaEsq;
    else folha->folhaDir = NULL;
    folha2->folhaEsq = folha;
    return folha2;
}

Folha* AVLTree::rotacaoDuplaDireita(Folha* folha) {
    Folha* folha1 = folha->folhaEsq;
    Folha* folha2 = folha1->folhaDir;

    if (folha2->folhaEsq) folha1->folhaDir = folha2->folhaEsq;
    else folha1->folhaDir = NULL;

    if (folha2->folhaDir) folha->folhaEsq = folha2->folhaDir;
    else folha->folhaEsq = NULL;

    folha2->folhaEsq = folha1;
    folha2->folhaDir = folha;

    return folha2;
}

Folha* AVLTree::rotacaoDuplaEsquerda(Folha* folha) {
    Folha* folha3 = folha->folhaDir;
    Folha* folha2 = folha3->folhaEsq;

    if (folha2->folhaEsq) folha->folhaDir = folha2->folhaEsq;
    else folha->folhaDir = NULL;

    if (folha2->folhaDir) folha3->folhaEsq = folha2->folhaDir;
    else folha3->folhaEsq = NULL;

    folha2->folhaEsq = folha;
    folha2->folhaDir = folha3;

    return folha2;
}

int AVLTree::calculaAltura(Folha* folha) {
    int altura = 0;
    if (folha == NULL) {
        return 0;
    }
    if (folha->folhaDir == NULL && folha->folhaEsq == NULL) {
        altura = 0;
    } else if (folha->folhaDir == NULL && folha->folhaEsq != NULL) {
        altura = calculaAltura(folha->folhaEsq) + 1;
    } else if (folha->folhaDir != NULL && folha->folhaEsq == NULL) {
        altura = calculaAltura(folha->folhaDir) + 1;
    } else {
        int alturaDir, alturaEsq;
        alturaDir = calculaAltura(folha->folhaDir) + 1;
        alturaEsq = calculaAltura(folha->folhaEsq) + 1;
        if (alturaDir >= alturaEsq) {
            altura = alturaDir;
        } else {
            altura = alturaEsq;
        }
    }
    return altura;

}

AVLTree::AVLTree(const AVLTree& orig) {
}

AVLTree::~AVLTree() {
}

