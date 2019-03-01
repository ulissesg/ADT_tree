#include "arvore.h"
#include "fila.h"

int main() {
//    int num;

//    Arvore *arv = alocaArv();
//    construirArv(arv);
//    imprimiArv(arv);

//    num = numeroNo(arv);

//    printf("\nnumero de nos: %d", num);
//   desalocaArv(arv);

criafila();
enfileira(6);
enfileira(10);

printf("%d", desenfileira());
int cont =0;

while (cont < 2){
    printf(">%d\n", fila[cont]);
    cont++;
}

    return 0;
}