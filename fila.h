//
// Created by ulisses on 01/03/19.
//

#ifndef UNTITLED3_FILA_H
#define UNTITLED3_FILA_H

#include <stdlib.h>

int fila[100], frente, tras, quantos;
void criafila()
{
    frente = quantos = 0;
    tras = (-1);
}
int enfileira(int elemento)
{
    if (quantos > 99)
        return 0;
    quantos++;
    tras++;
    if (tras > 99)
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
    if (frente > 99)
        frente = 0;
    return aux;
}
int filavazia()
{
    return quantos == 0;
}

#endif //UNTITLED3_FILA_H
