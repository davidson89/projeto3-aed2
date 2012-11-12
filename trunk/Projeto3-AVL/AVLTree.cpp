#include <stddef.h>
#include <iostream>
#include "AVLTree.h"

using namespace std;

/**
 *  AVLTree
 * Construtor. Faz o ponteiro para a raiz da árvore apontar para nulo.
 **/
AVLTree::AVLTree() {
    this->raiz = NULL;
}

/**
 * add
 * Verifica se a raiz aponta para NULL. Se a raiz for NULL então ele cria uma nova raiz, senão apenas faz a inserção.
 * @param valor a ser inserido na árvore.
 **/
void AVLTree::add(int valor) {
    if (this->raiz == NULL) {
        criaRaiz(valor);
    } else {
        this->raiz = insereRecursivamente(this->raiz, valor);
    }
}

/**
 * busca
 * Verifica se um valor está na árvore através do método findValue.
 * @param valor a ser procurado na árvore.
 **/
void AVLTree::busca(int valor) {
    findValue(this->raiz, valor);
}

/**
 * findValue
 * Método recursivo que percorre a árvore em busca de um valor, imprimindo o caminho percorrido.
 * @param folha, objeto da classe Folha (raiz da árvore/subárvore).
 * @param valor, valor a ser procurado na árvore.
 **/
void AVLTree::findValue(Folha* folha, int valor) {
    if (folha == NULL) return;
    if (folha->valor > valor) {
        cout << folha->valor << ";";
        findValue(folha->folhaEsq, valor);
    } else if (folha->valor < valor) {
        cout << folha->valor << ";";
        findValue(folha->folhaDir, valor);
    } else {
        cout << folha->valor;
    }
}

/**
 * printTree
 * Imprime a estrutura da árvore. Para realizar a imprissão, esse método invoca o método recursivo printPreOrdem.
 **/
void AVLTree::printTree() {
    printPreOrdem(this->raiz);
}

/**
 * printPreOrdem
 * Imprime a estrutura da árvore recursivamente a partir do nó passado como raiz.
 * @param folha, o objeto raiz da árvore.
 **/
void AVLTree::printPreOrdem(Folha *folha) {
    if (folha != NULL) {
        cout << "(" << folha->valor << ",";
        printPreOrdem(folha->folhaEsq);
        cout << ",";
        printPreOrdem(folha->folhaDir);
        cout << ")";
    } else {
        cout << "()";
    }
}

/**
 * criaRaiz
 * Cria o primeiro nó da árvore (Objeto da classe Folha).
 * @param folha, o objeto raiz da árvore.
 **/
void AVLTree::criaRaiz(int valor) {
    this->raiz = new Folha(valor);
}

/**
 * insereRecursivamente
 * Percorre a árvore recursivamente para encontrar o local certo onde o valor deve ser inserido.
 * @param no raz da árvore.
 * @param valor a ser inserido na árvore.
 * @return raiz da árvore ou subárvore.
 **/
Folha* AVLTree::insereRecursivamente(Folha* folha, int valor) {
    if (folha->valor > valor && folha->folhaEsq == NULL) {
        Folha *newFolha = new Folha(valor);
        folha->folhaEsq = newFolha;
    } else if (folha->valor < valor && folha->folhaDir == NULL) {
        Folha *newFolha = new Folha(valor);
        folha->folhaDir = newFolha;
    } else if (folha->valor > valor) {
        folha->folhaEsq = insereRecursivamente(folha->folhaEsq, valor);
    } else if (folha->valor < valor) {
        folha->folhaDir = insereRecursivamente(folha->folhaDir, valor);
    }
    return atualizaFatorCarga(folha);
}

/**
 * atualizaFatorCarga
 * Método responsável por manter a estrutura da AVL. Ele atualiza o fator de carga do nó e realiza as devidas rotações caso seja necessário.
 * @param raiz da árvore.
 * @return raiz da árvore.
 **/
Folha* AVLTree::atualizaFatorCarga(Folha* folha) {
    folha->fatorCarga = calculaAltura(folha->folhaDir) - calculaAltura(folha->folhaEsq);
    if (folha->fatorCarga == 2) {
        if (folha->folhaDir->fatorCarga > 0) {
            folha = rotacionaParaEsquerda(folha);
        } else {
            folha = rotacaoDuplaEsquerda(folha);
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

/**
 * rotacionaParaDireita
 * Rotaciona a árvore para a direita.
 * @param raiz da árvore.
 * @return raiz da árvore.
 **/
Folha* AVLTree::rotacionaParaDireita(Folha* folha) {
    Folha* folha2 = folha->folhaEsq;
    if (folha2->folhaDir) folha->folhaEsq = folha2->folhaDir;
    else folha->folhaEsq = NULL;
    folha2->folhaDir = folha;
    return folha2;
}

/**
 * rotacionaParaEsquerda
 * Rotaciona a árvore para a esquedar.
 * @param raiz da árvore.
 * @return raiz da árvore.
 **/
Folha* AVLTree::rotacionaParaEsquerda(Folha* folha) {
    Folha* folha2 = folha->folhaDir;
    if (folha2->folhaEsq) folha->folhaDir = folha2->folhaEsq;
    else folha->folhaDir = NULL;
    folha2->folhaEsq = folha;
    return folha2;
}

/**
 * rotacaoDuplaDireita
 * Faz rotação dupla da árvore para a direita.
 * @param raiz da árvore.
 * @return raiz da árvore.
 **/
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

/**
 * rotacaoDuplaEsquerda
 * Faz rotação dupla da árvore para a esquerda.
 * @param raiz da árvore.
 * @return raiz da árvore.
 **/
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

/**
 * calculaAltura
 * Percorre a árvore recursivamente partindo da raiz até chegar ao último nó folha calculando a sua altura.
 * @param raiz da árvore.
 * @return retorna o tamanho da árvore.
 **/
int AVLTree::calculaAltura(Folha* folha) {
    int altura = 0;
    if (folha == NULL) {
        return 0;
    }
    if (folha->folhaDir == NULL && folha->folhaEsq == NULL) {
        altura = 1;
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

/**
 * deletePosOrdem
 * Percorre a árvore recursivamente a partir do nó raiz e apaga todos os objetos da classe Folha.
 * @param no, raiz da árvore.
 **/
void AVLTree::deletePosOrdem(Folha *no) {
    if (no != NULL) {
        deletePosOrdem(no->folhaEsq);
        deletePosOrdem(no->folhaDir);
        delete no;
    }
}

/**
 * Destrutor.
 * Invoca o método deletePosOrdem que desaloca os objetos da classe Folha.
 **/
AVLTree::~AVLTree() {
    deletePosOrdem(this->raiz);
}