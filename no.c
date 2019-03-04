//
// Created by ulisses on 24/02/19.
//

#include "no.h"

No *alocaNo(){
    No *no = (No*)malloc(sizeof(No));
    no->chave = NULL;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void desalocaNo(No *no){
    No *x = no;
    free(x->chave);
    free(x->esquerda);
    free(x->direita);
    free(no);
}