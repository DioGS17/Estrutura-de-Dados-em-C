#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

void startLIFO(PILHA *p){
    p->top = NULL;
}

void restartLIFO(PILHA *p){
    ELEMENTO *clear;
    ELEMENTO *elem = p->top;

    while(elem != NULL){
        clear = elem;
        elem = elem->prox;
        free(clear);
    }
    p->top = NULL;
}

void insertElem(PILHA *p, int num){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));

    i->num = num;
    i->prox = p->top;
    p->top = i;
}

int delElem(PILHA *p){
    if (p->top == NULL){
        return 0;
    }
    ELEMENTO *i = p->top;
    p->top = p->top->prox;
    free(i);
    return 1;
}

int delElemPOS(PILHA *p, int pos){
    if (p->top == NULL){
        return 0;
    }
    int cont = 0;
    PILHA aux;
    startLIFO(&aux);

    while(cont < pos){
        insertElem(&aux, p->top->elem);
        delElem(p);
        cont++;
    }
    delElem(&aux);
    while (cont-1 != 0){
        insertElem(p, aux.top->elem);
        delElem(&aux);
        cont--;
    }
    restartLIFO(&aux);
    return 1;
}

int lenLIFO(PILHA *p){
    int tam = 0;
    ELEMENTO *i = p->top;

    while(i != NULL){
        tam++;
        i = i->prox;
    }
    return tam;
}

void printLIFO(PILHA *p){
    ELEMENTO *i = p->top;
    printf("\nLIFO:");
    while(i != NULL){
        printf(" %d", i->num);
        i = i->prox;
    }
}