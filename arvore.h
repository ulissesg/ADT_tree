//
// Created by ulisses on 24/02/19.
//

#ifndef ARVORE_ARVORE_H
#define ARVORE_ARVORE_H

#include "no.h"

struct arvore {
    No *raiz;
};

typedef struct arvore Arvore;

Arvore *alocaArv();

void desalocaArv(Arvore *arv);

//No *busca(Arvore *a, No *r, int *chave);

void construirArv(Arvore *a, int num);

void imprimiArv(Arvore *a);

#endif //ARVORE_ARVORE_H
