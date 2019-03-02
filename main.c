#include "arvore.h"


int main() {
    int num;

    Arvore *arv = alocaArv();
    construirArv(arv);
    imprimiArv(arv);

    num = numeroNo(arv);

    printf("\nnumero de nos: %d", num);
   desalocaArv(arv);
//
//criafila();
//enfileira(6);
//enfileira(10);
//enfileira(18);
//
//printf("desenfilera: %d\n", desenfileira());
//printf("quantos:%d\n", quantos);
//imprimeFila(fila);

    return 0;
}