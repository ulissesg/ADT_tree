//
// Created by ulisses on 24/02/19.
//

#include "no.h"

No *alocaNo(){
    No *no = (No*)malloc(sizeof(No));
    no->chave = 0;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void desalocaNo(No *no){

    free(no);
}