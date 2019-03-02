//
// Created by ulisses on 01/03/19.
//

#ifndef UNTITLED3_FILA_H
#define UNTITLED3_FILA_H

#include <stdio.h>

int fila[500], frente, tras, quantos;
void criafila()
{
    frente = quantos = 0;
    tras = (-1);
}
int enfileira(int elemento)
{
    if (quantos > 499)
        return 0;
    quantos++;
    tras++;
    if (tras > 499)
        tras = 0;
    fila[tras] = elemento;
    return 1;
}
int desenfileira()
{
    int aux;
    if (quantos <= 0)
        return (-2);
    aux = fila[frente];
    frente++;
    quantos--;
    if (frente > 499)
        frente = 0;
    return aux;
}
int filavazia()
{
    if (frente <= tras){
        return 0;
    }
    return 1;
}

void imprimeFila(int num[500]){
    for(int cont = frente; cont <= tras; cont ++){
        printf(">%d\n", fila[cont]);
    }
}

#endif //UNTITLED3_FILA_H
