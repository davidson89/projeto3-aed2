/* 
 * File:   AVLTree.h
 * Author: davidson
 *
 * Created on 31 de Outubro de 2012, 22:34
 */

#ifndef AVLTREE_H
#define	AVLTREE_H
#include "Folha.h"

using namespace std;

class AVLTree {
public:
    AVLTree();
    Folha *raiz;
    void add(int valor);
    void remove(int valor);
    bool busca(int valor);
    void printTree(Folha *folh); 
    AVLTree(const AVLTree& orig);
    virtual ~AVLTree();
private:
    void criaRaiz(int valor);
    Folha* insereRecursivamente(Folha *folha, int valor);
    Folha* rotacionaParaDireita(Folha *folha);
    Folha* rotacionaParaEsquerda(Folha *folha);
    Folha* rotacaoDuplaDireita(Folha *folha);
    Folha* rotacaoDuplaEsquerda(Folha *folha);
    Folha* atualizaFatorCarga(Folha *folha);
    int calculaAltura(Folha *folha);

};

#endif	/* AVLTREE_H */

