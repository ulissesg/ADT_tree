#include "arvore.h"

int main() {
    int num;

    Arvore *arv = alocaArv();
    construirArv(arv, 8);
    construirArv(arv, 7);
    imprimiArv(arv);

    num = numeroNo(arv);

    printf("\nnumero de nos: %d", num);
    desalocaArv(arv);
    return 0;
}