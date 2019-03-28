//
// Created by ulisses on 24/02/19.
//

#include "arvore.h"
#include "string.h"
#include "ctype.h"

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


//void construirArv(Arvore *a){
//
////    int num1;
////    int num2;
////    int num3;
//
//    a->raiz = alocaNo();
//    a->raiz->direita = alocaNo();
//    a->raiz->esquerda = alocaNo();
//
//    printf("//\n");
//
//    scanf("%d:", &a->raiz->chave);
//
//    scanf("\n%d", &a->raiz->direita->chave);
//
//    scanf("\n%d", &a->raiz->esquerda->chave);
//
//}

void contruiArvStringNo(No *no, char arvoreString[50], int size, int posicao, No *pai, No *raiz){

    if (posicao < size){
        if (arvoreString[posicao] == '('){
            if (arvoreString[posicao -1] == ')' || arvoreString[posicao -1] == ' '){
                no->direita = alocaNo();
                contruiArvStringNo(no->direita, arvoreString, size, posicao + 1, no, raiz);
            }
            else{
                no->esquerda = alocaNo();
                contruiArvStringNo(no->esquerda, arvoreString, size, posicao + 1, no, raiz);
            }
        }
        else if ((arvoreString[posicao] - '0') <= 9 &&  (arvoreString[posicao] - '0') >= 0) {
            no->chave = (arvoreString[posicao] - '0');
            contruiArvStringNo(no, arvoreString, size, posicao + 1, pai, raiz);
        }
        else if (arvoreString[posicao] == ')'){
            contruiArvStringNo(pai, arvoreString, size, posicao + 1, pai, raiz);
        }
    }
}

Arvore* construiArvString(Arvore *a, char arvoreString[50], int size, int posicao){

    a->raiz = alocaNo();
    a->raiz->chave = arvoreString[1] - '0';
    contruiArvStringNo(a->raiz, arvoreString, size, posicao +2, a->raiz, 0);
}

int verificaExistente(No *x, int num){
    if (x != NULL){
        if (x->chave != num){
            verificaExistente(x->esquerda, num);
            verificaExistente(x->direita, num);
            return 0;
        }
        else{
            return 1;
        }
    }
}

void insereVerificaAux(No *x, int num){
        if (num > x->chave && x->direita == NULL){
            x->direita = alocaNo();
            x->direita->chave = num;
        }
        else if(num < x->chave && x->esquerda == NULL){
            x->esquerda = alocaNo();
            x->esquerda->chave = num;
        }
        else if(num > x->chave){
            insereVerificaAux(x->direita, num);
        }
        else if(num < x->chave){
            insereVerificaAux(x->esquerda, num);
        }

}

void insereVerifica(Arvore *a, int num){
    if (a->raiz == NULL){
        a->raiz = alocaNo();
        a->raiz->chave = num;
    }
    else {
        insereVerificaAux(a->raiz, num);
    }
}

No* buscaNoPai(Arvore *a, int num){
    buscaNoPaiAux(a->raiz, num);
}

No* buscaNoPaiAux(No *no, int num){
    if (no != NULL){
        if (no->direita != NULL && no->direita->chave == num || no->esquerda != NULL && no->esquerda->chave == num){
            return no;
        }
        else if (num < no->chave){
            return buscaNoPaiAux(no->esquerda, num);
        }
        else if (num > no->chave){
            return buscaNoPaiAux(no->direita, num);
        }
    }
    printf("\n numero nao encontrado !\n");
}

No *buscaNo(Arvore *a, int num){
    buscaNoAux(a->raiz, num);
}

No* buscaNoAux(No* no, int num){
    if (no != NULL){
        if (no->chave == num){
            return no;
        }
        else if (no->chave > num){
            return buscaNoAux(no->esquerda, num);
        }
        else if (no->chave < num){
            return buscaNoAux(no->direita, num);
        }
    }
    printf("\n numero nao encontrado !\n");
}

void removeNo(Arvore *a, int num){
    removeNoAux(a->raiz, num);
}

void removeNoAux(No* x, int num){
    No *no = buscaNoAux(x, num);
    No *pai = buscaNoPaiAux(x, num);
    if(no->direita == NULL && no->esquerda == NULL){
        if (pai->esquerda == no){
            pai->esquerda = NULL;
        }
        else if (pai->direita == no){
            pai->direita = NULL;
        }
        desalocaNo(no);
    }
    else if (no->direita == NULL || no->esquerda == NULL){
        if (no->direita != NULL){
            if (pai->direita == no){
                pai->direita = no->direita;
            }
            else if (pai->esquerda == no){
                pai->esquerda = no->direita;
            }
        }
        else if (no->esquerda != NULL){
            if (pai->esquerda == no){
                pai->esquerda = no->esquerda;
            }
            else if (pai->direita == no){
                pai->direita = no->esquerda;
            }
        }
        if (pai->esquerda->chave == num){
            pai->esquerda = NULL;
        }
        else if (pai->direita->chave == num){
            pai->direita = NULL;
        }
        desalocaNo(no);
    }

}

void imprimiArv(Arvore *a){
    Fila *aux =  alocafila();
    insereNoFila(aux, a->raiz);
    while(filaVazia(aux) == 1){
        No *noAux = consultaInicioFila(aux);
        insereNoFila(aux, noAux->direita);
        insereNoFila(aux, noAux->esquerda);
        retiraNoFila(aux);
        printf(">%d\n", noAux->chave);
    }

}

void imprimeArvVisualNo(No* no){

    if (no != NULL) {
        printf("(");
        printf("%d", no->chave);
        imprimeArvVisualNo(no->esquerda);
        imprimeArvVisualNo(no->direita);
        printf(")");

    }
}

void imprimeArvVisual (Arvore *a){

    imprimeArvVisualNo(a->raiz);

}

int numeroNo(Arvore *a){
    return contaNo(a->raiz);

}

int contaNo(No *x){
    int num = 1;
    if (x != NULL){
        if (x->esquerda != NULL) {
            num += contaNo(x->esquerda);
        }

        if (x->direita != NULL) {
            num += contaNo(x->direita);
        }

    }
    return num;
}
