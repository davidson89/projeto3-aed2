#ifndef AVLTREE_H
#define	AVLTREE_H
#include "Folha.h"

class AVLTree {
public:
    AVLTree();
    void add(int valor);
    void busca(int valor);
    void printTree();
    virtual ~AVLTree();
private:
    Folha *raiz;
    void criaRaiz(int valor);
    Folha* insereRecursivamente(Folha *folha, int valor);
    Folha* rotacionaParaDireita(Folha *folha);
    Folha* rotacionaParaEsquerda(Folha *folha);
    Folha* rotacaoDuplaDireita(Folha *folha);
    Folha* rotacaoDuplaEsquerda(Folha *folha);
    Folha* atualizaFatorCarga(Folha *folha);
    void findValue(Folha *folha, int valor);
    void printPreOrdem(Folha *folha);
    int calculaAltura(Folha *folha);
    void deletePosOrdem(Folha *no);
};

#endif	/* AVLTREE_H */