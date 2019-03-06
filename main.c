#include <stdio.h>
#include <stdlib.h>

// arquivos no.h

typedef struct no No;

struct no{
    int *chave;
    No *direita;
    No *esquerda;
};

No *alocaNo();
void desalocaNo(No *no);
No* insereNo(int num);

// arquivos no.c

No *alocaNo(){
    No *no = (No*)malloc(sizeof(No));
    no->chave = NULL;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void desalocaNo(No *no){
    No *x = no;
//    free(x->chave);
//    free(x->esquerda);
//    free(x->direita);
    free(no);
}

No* insereNo(int num){
    No *x = alocaNo();
    x->chave = num;
    return x;
}

// arquivos noLista.h

typedef struct nolista noLista;

struct nolista {
    No * dado;
    noLista *proximo;
    noLista *anterior;
};

noLista * alocaNolista();

void desalocaNolista(noLista * no);

//arquivos noLista.cpp

noLista * alocaNolista(){
    noLista * x =(noLista*)malloc(sizeof(noLista));
    x->dado = alocaNo();
    x->anterior = NULL;
    x->proximo = NULL;
    return x;
}

void desalocaNolista(noLista * no){
    noLista * x = no;
    free(x->proximo);
    free(x->anterior);
    desalocaNo(x->dado);
    free(no);
}

//arquivos lista.h

typedef struct lista Lista;

struct lista{
    noLista * cabeca;
    noLista * ultimo;

};

Lista * criaLista ();

Lista * insereNoLista(Lista *l, No *no);

void retiraNoLista(Lista *x);

void desalocaLista(Lista*x);

No* consultaInicioLista(Lista *x);

int listavazia(Lista *x);

//arquivos lista.cpp

Lista * criaLista (){
    Lista * list =(Lista*)malloc(sizeof(Lista));
    return list;
}

Lista * insereNoLista(Lista *l, No *no){
    if (listavazia(l) == 0){
        noLista * x = alocaNolista();
        x->dado = no;
        l->cabeca = no;
        l->ultimo = no;
    }else{
        noLista * novoNo = alocaNolista();
        novoNo->dado =no;
        l->ultimo->anterior->proximo =novoNo; //  talvez seja: l->ultimo->anterior->proximo
        novoNo->anterior = l->ultimo->anterior;
        l->ultimo =novoNo;
        novoNo->proximo = l->ultimo;
    }


    return l;
}

void retiraNoLista(Lista * l){
    noLista * x = l->cabeca;
    l->cabeca->proximo->anterior = l->cabeca; //talvez seja: l->cabeca->proximo->proximo->anterior
    l->cabeca = l->cabeca->proximo;
    desalocaNolista(x);
}

void desalocaLista(Lista*x){
    desalocaNolista(x->cabeca);
    desalocaNolista(x->ultimo);
    free(x);
}

No* consultaInicioLista(Lista *x) {
    return x->cabeca->dado;
}

int listavazia(Lista *x){
    if (x->cabeca == NULL){
        return 0;
    }
    else return 1;
}

// arquivos fila.h

typedef struct fila Fila;

struct fila{
    Lista * filaNo;
};

Fila * alocafila();

void desalocafila(Fila *x);

Fila * insereNoFila(Fila *x, No *no);

void retiraNoFila(Fila *x);

No * consultaInicioFila(Fila *x);

int filaVazia(Fila *x);

// arquivos fila.cpp

Fila * alocafila(){
    Fila * x =(Fila*)malloc(sizeof(Fila));
    x->filaNo = criaLista();
    return x;
}

void desalocafila(Fila *x){
    while(x->filaNo->ultimo != x->filaNo->cabeca){
        retiraNoLista(x->filaNo);
    }

    desalocaLista(x->filaNo);
}

Fila * insereNoFila(Fila *x, No *no){
    return insereNoLista(x->filaNo, no);
}

void retiraNoFila(Fila *x){
    retiraNoLista(x->filaNo);
}

No *consultaInicioFila(Fila *x){
    return x->filaNo->cabeca;
}

int filaVazia(Fila *x){
    return listavazia(x->filaNo);
}

// arquivos arvore.h

struct arvore {
    No *raiz;
};

typedef struct arvore Arvore;

Arvore *alocaArv();

void desalocaArv(Arvore *arv);

void desalocaArvNo(No *no);

//No *busca(Arvore *a, No *r, int *chave);

void construirArv(Arvore *a);

void imprimiArv(Arvore *a);

int numeroNo(Arvore *a);

int contaNo(No *no);

//arquivos arvore.c

Arvore *alocaArv(){
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
    arv->raiz = NULL;
    return arv;
}

void desalocaArv(Arvore *arv){
    desalocaArvNo(arv->raiz);
}

void desalocaArvNo(No *x){
    if (x != NULL){
        desalocaArvNo(x->esquerda);
        desalocaArvNo(x->direita);
        desalocaNo(x);
    }
}

//No *busca(Arvore *a, No *raiz, int *chave) {
//
//    if (a->raiz->direita != NULL && a->raiz->esquerda != NULL) {
//
//        if (a->raiz->chave == chave) {
//
//            return a->raiz;
//
//        } else if (a->raiz->esquerda->chave != chave) {
//
//            busca(a, a->raiz->esquerda, chave);
//
//        } else {
//
//            busca(a, a->raiz->direita, chave);
//
//        }
//    }
//}


void construirArv(Arvore *a){

//    int num1;
//    int num2;
//    int num3;

    a->raiz = alocaNo();
    a->raiz->direita = alocaNo();
    a->raiz->esquerda = alocaNo();

    printf("//\n");

    scanf("%d:", &a->raiz->chave);
//    a->raiz = insereNo(num1);

    scanf("\n%d", &a->raiz->direita->chave);
//    a->raiz->esquerda = insereNo(num2);

    scanf("\n%d", &a->raiz->esquerda->chave);
//    a->raiz->direita = insereNo(num3);

}

void imprimiArv(Arvore *a){
    Fila *aux =  alocafila();
    insereNoFila(aux, a->raiz);
    while(filaVazia(aux) == 1){
        No *noAux = consultaInicioFila(aux);
        insereNoFila(aux, noAux->esquerda);
        insereNoFila(aux, noAux->direita);
        retiraNoFila(aux);
        printf(">%d\n", noAux->chave);
    }

}

int numeroNo(Arvore *a){

    return contaNo(a->raiz) ;

}

int contaNo(No *x){
    int num =1;
    if (x != NULL){
        num ++;
        contaNo(x->esquerda);
        num ++;
        contaNo(x->direita);
    }
    return num;
}



// main

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

    return 0;
}