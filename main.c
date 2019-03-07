#include "arvore.h"

int main() {
    int num;

    Arvore *arv = alocaArv();
    construirArv(arv);
    imprimiArv(arv);

    num = numeroNo(arv);

    printf("\nnumero de nos: %d", num);
   desalocaArv(arv);

//criafila();
//enfileira(6);
//enfileira(10);
//enfileira(18);
//
//printf("desenfilera: %d\n", desenfileira());
//printf("quantos:%d\n", quantos);
//imprimeFila(fila);
//Lista *x = criaLista();
//printf("%d", filavazia(x));


//Fila *aux = alocafila();
//No *x = alocaNo();
//No *y = alocaNo();
//No *z = alocaNo();
//
//x->chave = 1;
//y->chave = 2;
//z->chave = 3;
//x->direita = z;
//x->esquerda = y;
//
//
//insereNoFila(aux, x);
//insereNoFila(aux , y);
//insereNoFila(aux, z);
//retiraNoFila(aux);




    return 0;
}