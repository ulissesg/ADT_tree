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

//    int num1;
//    int num2;
//    int num3;

    a->raiz = alocaNo();
    a->raiz->direita = alocaNo();
    a->raiz->esquerda = alocaNo();

    printf("//\n");

    scanf("%d:", &a->raiz->chave);

    scanf("\n%d", &a->raiz->direita->chave);

    scanf("\n%d", &a->raiz->esquerda->chave);

}

void imprimiArv(Arvore *a){
    Fila *aux =  alocafila();
    insereNoFila(aux, a->raiz);
    while(filaVazia(aux) == 1){
        No *noAux = consultaInicioFila(aux);
        insereNoFila(aux, noAux->direita);
        insereNoFila(aux, noAux->esquerda);
        retiraNoFila(aux);
        printf(">%d\n", noAux->chave);
    }

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
