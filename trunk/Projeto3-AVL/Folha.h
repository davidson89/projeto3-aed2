/* 
 * File:   Folha.h
 * Author: davidson
 *
 * Created on 31 de Outubro de 2012, 22:22
 */

#ifndef FOLHA_H
#define	FOLHA_H
using namespace std;

class Folha {
public:
    Folha(int valor);
    int valor;
    int fatorCarga;
    Folha *folhaEsq;
    Folha *folhaDir;
    Folha(const Folha& orig);
    virtual ~Folha();
private:

};

#endif	/* FOLHA_H */

