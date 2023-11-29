#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

void criarArvore(ARVORE *a){
    a->raiz = NULL;
}

ELEMENTO *insertAUX1(ELEMENTO *raiz, ELEMENTO *elem){
    if(raiz == NULL){
        return elem;
    }
    if(raiz->num > elem->num){
        raiz->left = insertAUX1(raiz->left, elem);
    }else{
        raiz->right = insertAUX1(raiz->right, elem);
    }
    return raiz;
}

void insertAUX2(ARVORE *a, ELEMENTO *novo){
    a->raiz = insertAUX1(a->raiz, novo);
}

void insert(ARVORE *a, int num){
    ELEMENTO *elem = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    elem->num = num;
    elem->left = NULL;
    elem->right = NULL;
    insertAUX2(a, elem);
}

void listElem(ELEMENTO *raiz){
    if(raiz != NULL){
        printf("\n================");
        printf("\nNum: %d", raiz->num);
        if (raiz->left != NULL) printf("\nEsquerda: %d", raiz->left->num);
        else 
            printf("\nEsquerda: NULL");
        if(raiz->right != NULL) printf("\nDireita: %d", raiz->right->num);
        else
            printf("\nDireita: NULL");
        listElem(raiz->left);
        listElem(raiz->right);
    }
}

void listArvore(ARVORE *a){
    listElem(a->raiz);
}

int lenArvore(ELEMENTO *raiz){
    if(raiz == NULL){
        return 0;
    }
    return (lenArvore(raiz->left)+1+lenArvore(raiz->right));
}

ELEMENTO *contem(ELEMENTO *raiz, int num){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->num == num){
        return raiz;
    }
    if(raiz->num > num){
        return contem(raiz->left, num);
    }else{
        return contem(raiz->right, num);
    }
}

void pre_ordem(ELEMENTO *raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d ", raiz->num);
    pre_ordem(raiz->left);
    pre_ordem(raiz->right);
}

void in_ordem(ELEMENTO *raiz){
    if(raiz == NULL){
        return;
    }
    in_ordem(raiz->left);
    printf("%d ", raiz->num);
    in_ordem(raiz->right);
}

void pos_ordem(ELEMENTO *raiz){
    if(raiz == NULL){
        return;
    }
    pos_ordem(raiz->left);
    pos_ordem(raiz->right);
    printf("%d ", raiz->num);
}