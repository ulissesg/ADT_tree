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

    a->raiz = alocaNo();
    a->raiz->direita = alocaNo();
    a->raiz->esquerda = alocaNo();

    printf("//\n");
    scanf("%d:", &a->raiz->chave);
    scanf("\n%d", &a->raiz->esquerda->chave);
    scanf("\n%d", &a->raiz->direita->chave);


}

void imprimiArv(Arvore *a){


}

int numeroNo(Arvore *a){

    return contaNo(a->raiz) ;

}

int contaNo(No *x){
    int num =1;
    if (x != NULL){
        num ++;
        contaNo(x->esquerda);
        num ++;
        contaNo(x->direita);
    }
    return num;
}