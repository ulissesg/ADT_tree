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

void desalocaArvNo(No *no);

//No *busca(Arvore *a, No *r, int *chave);

void construirArv(Arvore *a);

void imprimiArv(Arvore *a);

int numeroNo(Arvore *a);

int contaNo(No *no);

#endif //ARVORE_ARVORE_H
