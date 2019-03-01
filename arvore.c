//
// Created by ulisses on 24/02/19.
//

#include "arvore.h"

Arvore *alocaArv(){
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = NULL;
    return arv;
}

void desalocaArv(Arvore *arv){
    desalocaArvNo(arv->raiz);
}

void desalocaArvNo(No *x){
    if (x != NULL){
        desalocaArvNo(x->esquerda);
        desalocaArvNo(x->direita);
        desalocaNo(x);
    }
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


void construirArv(Arvore *a){
    Arvore *arv = alocaArv();
    arv->raiz = alocaNo();
    arv->raiz->direita = alocaNo();
    arv->raiz->esquerda = alocaNo();

    printf("//\n");
    scanf("%d:", &arv->raiz->chave);
    scanf("\n%d", &arv->raiz->esquerda->chave);
    scanf("\n%d", &arv->raiz->direita->chave);


}

void imprimiArv(Arvore *a){

    Arvore *arv;
    printf(">%d\n", a->raiz->chave);
    for(arv=a->raiz->esquerda; arv != NULL; arv = arv->raiz->direita){
        imprimiArv(arv);
    }

}

int numeroNo(Arvore *a){

    return contaNo(a->raiz) ;

}

int contaNo(No *x){

    if (x != NULL){
        int num = 1;
        num =+ contaNo(x->esquerda);
        num =+ contaNo(x->direita);
    }

}
