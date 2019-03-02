//
// Created by ulisses on 02/03/19.
//

#include "noLista.h"


noLista * alocaNolista(){
    noLista * x =(noLista*)malloc(sizeof(noLista));
//    x->dado = alocaNo();
    x->anterior = NULL;
    x->proximo = NULL;
    return x;
}

void desalocaNolista(noLista * no){
    noLista * x = no;
    free(x->proximo);
    free(x->anterior);
//    desalocaNo(x->dado);
    free(no);
}
