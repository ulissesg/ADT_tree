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
    insereVerifica(arv, 8);

    imprimiArv(arv);

    int num;
    num = numeroNo(arv);
    printf("\nnumero de nos: %d", num);

    desalocaArv(arv);

    return 0;
}