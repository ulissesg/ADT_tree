//
// Created by ulisses on 01/03/19.
//
#include "lista.h"

No * alocaLista (){
    return alocaNo();
}

void desalocaNoLista(No *x){
    if(x != NULL){
        desalocaNo(x.)
    }
}

void desalocaLista(struct Lista * l){
    desalocaNoLista(l->cabeca);
}

