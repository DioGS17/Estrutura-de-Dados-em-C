#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

void startFIFO(FILA *f){
    f->start = NULL;
    f->end = NULL;
}

void restartFIFO(FILA *f){
    ELEMENTO *clear;
    ELEMENTO *elem = f->start;

    while(elem != NULL){
        clear = elem;
        elem = elem->prox;
        free(clear);
    }
    f->start;
}

void insertElem(FILA *f, int elem){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    i->elem = elem;
    i->prox = NULL;
    
    if(f->start == NULL){
        f->start = i;
    }else{
        f->end->prox = i;
    }
    f->end = i;
}

int delElem(FILA *f){
    if (f->start == NULL){
        return 0;
    }
    ELEMENTO *i = f->start;
    f->start = f->start->prox;
    free(i);
    return 1;
}

int lenFIFO(FILA *f){
    int tam = 0;
    ELEMENTO *i = f->start;

    while(i != NULL){
        tam++;
        i = i->prox;
    }

    return tam;
}

void printFIFO(FILA *f){
    ELEMENTO *i = f->start;

    printf("\nFILA: ");
    while(i != NULL){
        printf("%d ", i->elem);
        i = i->prox;
    }

}