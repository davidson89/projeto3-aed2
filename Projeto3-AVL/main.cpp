/* 
 * File:   main.cpp
 * Author: davidson
 *
 * Created on 31 de Outubro de 2012, 22:18
 */

#include <cstdlib>
#include <iostream>
#include "AVLTree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    AVLTree *arvore = new AVLTree();
    arvore->add(1);
    arvore->printTree(arvore->raiz);
    cout << endl;
    arvore->add(2);
    arvore->printTree(arvore->raiz);
    cout << endl;
    arvore->add(3);
    arvore->printTree(arvore->raiz);
    cout << endl;
    arvore->add(4);
    arvore->printTree(arvore->raiz);
    cout << endl;
    arvore->add(5);
    arvore->printTree(arvore->raiz);
    cout << endl;
    //arvore->add(15);
    //arvore->add(11);
   // arvore->printTree(arvore->raiz);

    return 0;
}

