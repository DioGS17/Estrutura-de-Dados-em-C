#include <stdio.h>
#include <stdlib.h>

#include "deque.h"

void startDEQUE(DEQUE *d){
    d->head = malloc(sizeof(ELEMENTO));
    d->head->ante = d->head;
    d->head->prox = d->head;
}

void restartDEQUE(DEQUE *d){
    ELEMENTO *clear;
    ELEMENTO *elem = d->head->prox;

    while(elem != d->head){
        clear = elem;
        elem = elem->prox;
        free(clear);
    }
    d->head->prox = d->head;
    d->head->ante = d->head;
}

int lenDEQUE(DEQUE *d){
    int tam = 0;
    ELEMENTO *i = d->head->prox;

    while(i != d->head){
        tam++;
        i = i->prox;
    }
    return tam;
}

void printDEQUE(DEQUE *d){
    ELEMENTO *i = d->head->prox;

    printf("\nDEQUE: ");
    while(i != d->head){
        printf("%d ", i->elem);
        i = i->prox;
    }
}

void insertElemBEGIN(DEQUE *d, int n){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    i->elem = n;
    i->prox = d->head->prox;
    i->ante = d->head;
    d->head->prox = i;
    i->ante->prox = i;
}

void insertElemEND(DEQUE *d, int n){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    i->elem = n;
    i->prox = d->head;
    i->ante = d->head->ante;
    d->head->ante = i;
    i->ante->prox = i;
}

int delElemBEGIN(DEQUE *d){
    if(d->head->prox == d->head){
        return 0;
    }
    ELEMENTO *i = d->head->prox;
    d->head->prox = i->prox;
    i->prox->ante = d->head;
    free(i);
    return 1;
}

int delElemEND(DEQUE *d){
    if(d->head->prox == d->head){
        return 0;
    }
    ELEMENTO *i = d->head->ante;
    d->head->ante = i->ante;
    i->ante->prox = d->head;
    free(i);
    return 1;
}

DEQUE intercala(DEQUE *d1, DEQUE *d2){
    DEQUE deque;
    startDEQUE(&deque);

    ELEMENTO *i1 = d1->head->prox;
    ELEMENTO *i2 = d2->head->prox;
    int aux = 1;
    while(i1 != d1->head || i2 != d2->head){
        if(aux == 1 && i1 != d1->head){
            insertElemEND(&deque, i1->elem);
            if(i2 != d2->head){
                aux = 2;
            }
            i1 = i1->prox;
        }else if (aux == 2 && i2 != d2->head){
            insertElemEND(&deque, i2->elem);
            if(i1 != d1->head){
                aux = 1;
            }
            i2 = i2->prox;
        }
    }

    return deque;
}