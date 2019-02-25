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

    No * no1 = no->esquerda;

    while (no1 != NULL){
        No * no2 = no1->direita;
        desalocaNo(no1);
        no1 = no2;
    }

    free(no);
}