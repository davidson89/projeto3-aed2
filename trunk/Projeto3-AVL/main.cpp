/* 
 * File:   main.cpp
 * Author: davidson
 *
 * Created on 31 de Outubro de 2012, 22:18
 */

#include <cstdlib>
#include <iostream>
#include "AVLTree.h"
#include <fstream>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  char *filename =argv[1];
	FILE *arq = fopen(filename, "r");
   
	if (arq == NULL) {
        cout << "Nao foi possivel encontrar o arquivo " << endl;
          return 0;
    }
	 AVLTree *arvore = new AVLTree();
	string line="";
	char comando;
	int valor = 0;
	while(!feof(arq)){
        fscanf(arq, "%s", &comando); 
		fscanf(arq, "%d", &valor); 
		
		if ( comando == 'i')
		{
			cout << "> " << comando <<  " " << valor<< endl;
			arvore->add(valor);
		    arvore->printTree();
			cout << endl;
		}  
		if ( comando == 'b')
		{
			
			cout << "> " << comando <<  " " << valor<< endl;
			arvore->busca(valor);
			cout << endl;
			
		} 
	}

    return 0;
}

