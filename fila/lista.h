//
// Created by ulisses on 01/03/19.
//

#ifndef UNTITLED3_LISTA_H
#define UNTITLED3_LISTA_H

#include "noLista.h"

typedef struct Lista{
    noLista * cabeca;
    noLista * ultimo;

};

No * alocaLista ();

void desalocaNoLista(No *x);

void desalocaLista(struct Lista * l);

#endif //UNTITLED3_LISTA_H
