#ifndef FOLHA_H
#define	FOLHA_H

class Folha {
public:
    Folha(int valor);
    int valor;
    int fatorCarga;
    Folha *folhaEsq;
    Folha *folhaDir;
};

#endif	/* FOLHA_H */