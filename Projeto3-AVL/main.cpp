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
    arvore->printTree();
    cout << endl;
    arvore->add(2);
    arvore->printTree();
    cout << endl;
    arvore->add(3);
    arvore->printTree();
    cout << endl;
    arvore->add(4);
    arvore->printTree();
    cout << endl;
    arvore->add(5);
    arvore->printTree();
    cout << endl;
    arvore->busca(5);
    cout << endl;


    return 0;
}

