//
// Created by ulisses on 24/02/19.
//

#ifndef ARVORE_ARVORE_H
#define ARVORE_ARVORE_H

#include "fila/fila.h"

struct arvore {
    No *raiz;
};

typedef struct arvore Arvore;

Arvore *alocaArv();

void desalocaArv(Arvore *arv);

void desalocaArvNo(No *no);

//No *busca(Arvore *a, No *r, int *chave);

//void construirArv(Arvore *a);

Arvore* construiArvString(Arvore *a, char arvoreString[50], int size, int posicao);

No * contruiArvStringNo(No *no, char arvoreString[50], int size, int posicao, No* pai, int cont);

int verificaExistente(No *x, int num);

void insereVerificaAux(No *x, int num);

void insereVerifica(Arvore *a, int num);

void imprimiArv(Arvore *a);

void imprimeArvVisual (Arvore *a);

void imprimeArvVisualNo(No *no);

int numeroNo(Arvore *a);

int contaNo(No *no);


#endif //ARVORE_ARVORE_H
