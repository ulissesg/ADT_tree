#include "arvore.h"

int main() {
    Arvore *arv = alocaArv();
    construirArv(arv, 8);
    construirArv(arv, 7);
    imprimiArv(arv);
    desalocaArv(arv);
    return 0;
}