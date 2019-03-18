#include "arvore.h"
#include "arvore.c"
#include "fila/fila.h"
#include "fila/fila.cpp"
#include "fila/lista.h"
#include "fila/lista.cpp"
#include "nos/noLista.h"
#include "nos/noLista.cpp"
#include "nos/no.h"
#include "nos/no.c"


int main() {


    Arvore *arv = alocaArv();
//    construirArv(arv);
    insereVerifica(arv, 8);
    insereVerifica(arv, 3);
    insereVerifica(arv, 5);
    insereVerifica(arv, 2);
    insereVerifica(arv, 4);
    insereVerifica(arv, 1);
    insereVerifica(arv, 22);
    insereVerifica(arv, 9);
    insereVerifica(arv, 10);
    insereVerifica(arv, 11);
    insereVerifica(arv, 56);
    insereVerifica(arv, 96);




    imprimiArv(arv);

    int num;
    num = numeroNo(arv);
    num = (num -1) / 2;
    printf("\nnumero de nos: %d", num);

    desalocaArv(arv);

    return 0;
}