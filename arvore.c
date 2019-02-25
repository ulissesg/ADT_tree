//
// Created by ulisses on 24/02/19.
//

#include "arvore.h"

Arvore *alocaArv(){
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = alocaNo();
    return arv;
}

void desalocaArv(Arvore *arv){
    return desalocaNo(arv->raiz);
}

//No *busca(Arvore *a, No *raiz, int *chave) {
//
//    if (a->raiz->direita != NULL && a->raiz->esquerda != NULL) {
//
//        if (a->raiz->chave == chave) {
//
//            return a->raiz;
//
//        } else if (a->raiz->esquerda->chave != chave) {
//
//            busca(a, a->raiz->esquerda, chave);
//
//        } else {
//
//            busca(a, a->raiz->direita, chave);
//
//        }
//    }
//}


void construirArv(Arvore *a, int num){
    Arvore *arv = alocaArv();
    arv->raiz->chave = num;
    arv->raiz->direita = a->raiz->esquerda;
    a->raiz->esquerda = arv;

}

void imprimiArv(Arvore *a){

    Arvore *arv;
    printf(">%d\n", a->raiz->chave);
    for(arv=a->raiz->esquerda; arv != NULL; arv = arv->raiz->direita){
        imprimiArv(arv);
    }

}

int numeroNo(Arvore *a){

    int num = 0;
    Arvore *arv;
    for(arv=a->raiz->esquerda; arv != NULL; arv = arv->raiz->direita){
        num ++;
    }

    return num;

}
