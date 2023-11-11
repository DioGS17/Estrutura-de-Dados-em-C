#include <stdio.h>
#include <stdlib.h>

#include "ListaD.h"

void startList(ListaD *list){
    list->start = NULL; 
}

int lenList(ListaD *list){
    int tam = 0;
    ELEMENTO *i = list->start;
    while (i != NULL){
        tam++;
        i = i->prox;
    }
    return tam;
}

void printList(ListaD *list){
    ELEMENTO *i = list->start;
    printf("\nLIST:");
    while (i != NULL){
        printf(" %d", i->num);
        i = i->prox;
    }
}

int searchElem(ListaD *list, int code){
    ELEMENTO *i = list->start;
    while (i != NULL && i->num < code){
        i = i->prox;
    }
    if(i != NULL && i->num == code){
        return 1;
    }
    return 0;
}

ELEMENTO *srchElemNPred(ListaD *list, int code, ELEMENTO **pred){
    *pred = NULL;
    ELEMENTO *i = list->start;
    while (i != NULL && i->num < code){
        *pred = i;
        i = i->prox;
    }
    if(i != NULL && i->num == code){
        return i;
    }
    return NULL;
}

int insertElem(ListaD *list, int num){
    int code = num;
    ELEMENTO *pred;
    ELEMENTO *i;
    i = srchElemNPred(list, code, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(ELEMENTO));
    i->num = num;
    if(pred == NULL){
        i->prox = list->start;
        list->start = i;
    }else{
        i->prox = pred->prox;
        pred->prox = i;
    }
    return 1;
}

void restartList(ListaD *list){
    ELEMENTO *clear;
    ELEMENTO *x = list->start;
    while (x != NULL){
        ELEMENTO *clear = x;
        x = x->prox;
        free(clear);
    }
    list->start = NULL;
     
}

int delElem(ListaD *list, int code){
    ELEMENTO *pred;
    ELEMENTO *i;
    i = srchElemNPred(list, code, &pred);
    if (i == NULL){
        return 0;
    }else if (pred == NULL){
        list->start = i->prox;
    }else{
        pred->prox = i->prox;
    }
    free(i);
    return 1;
}

int insertElemDL(ListaD *list, int num){
    int code = num;
    ELEMENTO *pred;
    ELEMENTO *i;
    i = srchElemNPred(list, code, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(ELEMENTO));
    i->num = num;
    if(pred == NULL){
        i->prox = list->start;
        i->ante = NULL;
        list->start = i;
    }else if (pred->prox == NULL){
        i->prox = pred->prox;
        i->ante = pred;
        pred->prox = i;
    }else{
        i->prox = pred->prox;
        i->ante = pred;
        pred->prox->ante = i;
        pred->prox = i;
    }
    return 1;
}

ELEMENTO *srchElemNPredALT(ListaD *list, int code, ELEMENTO **pred){
    *pred = NULL;
    ELEMENTO *i = list->start;
    while (i != NULL){
        *pred = i;
        i = i->prox;
    }
    if(i != NULL && i->num == code){
        return i;
    }
    return NULL;
}

int insertElemDLalt(ListaD *list, int num){
    int code = num;
    ELEMENTO *pred;
    ELEMENTO *i;
    i = srchElemNPredALT(list, code, &pred);
    if(i != NULL){
        return 0;
    }
    i = malloc(sizeof(ELEMENTO));
    i->num = num;
    if(pred == NULL){
        i->prox = list->start;
        i->ante = NULL;
        list->start = i;
    }else if(pred->prox == NULL){
        i->prox = pred->prox;
        i->ante = pred;
        pred->prox = i;
    }
    return 1;
}