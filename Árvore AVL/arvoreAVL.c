#include <stdlib.h>
#include <stdio.h>

#include "arvoreAVL.h"

void plantarAAVL(AAVL *a){
    a->raiz = NULL;
}

void liberarArvore(RAIZ *raiz){
    if(raiz != NULL){
        liberarArvore(raiz->left);
        liberarArvore(raiz->right);
        free(raiz);
    }
}

int altura(RAIZ *raiz){
    if(!raiz) return -1;
    else 
        return raiz->h;
}

int max(int n1, int n2){
    if(n1 > n2) return n1;
    else return n2;
}

RAIZ *spinR(RAIZ *raiz){
    RAIZ *aux;

    aux = raiz->left;
    raiz->left = aux->right;
    aux->right = raiz;

    raiz->h = max(altura(raiz->right), altura(raiz->left)) + 1;
    aux->h = max(altura(aux->left), altura(raiz)) + 1;
    return aux;
}
RAIZ *spinL(RAIZ *raiz){
    RAIZ *aux;

    aux = raiz->right;
    raiz->right = aux->left;
    aux->left = raiz;

    raiz->h = max(altura(raiz->right), altura(raiz->left)) + 1;
    aux->h = max(altura(aux->right), altura(raiz)) + 1;
    return aux;
}

RAIZ *spinRL(RAIZ *raiz){
    raiz->right = spinR(raiz->right);
    return spinL(raiz);
}

RAIZ *spinLR(RAIZ *raiz){
    raiz->left = spinL(raiz->left);
    return spinR(raiz);
}

RAIZ *insertAUX(RAIZ *r, RAIZ *ramo){
    if(r == NULL) return ramo;
    
    if(r->num > ramo->num){
        r->left = insertAUX(r->left, ramo);
        if(altura(r->right) - altura(r->left) == 2 || altura(r->right) - altura(r->left) == -2){
            if(ramo->num < r->left->num){
                r = spinR(r);
            }else{ 
                r = spinLR(r);
            }
        }
    }else{
        if(r->num < ramo->num){
            r->right = insertAUX(r->right, ramo);
            if(altura(r->right) - altura(r->left) == 2 || altura(r->right) - altura(r->left) == -2){
                if(ramo->num > r->right->num){
                    r = spinL(r);
                }else{
                    r = spinRL(r);
                }
            }
        }
    }
    r->h = max(altura(r->left), altura(r->right)) + 1;
    return r;
}

void insertAAVL(AAVL *a, int num){
    RAIZ *r = malloc(sizeof(RAIZ));
    r->num = num;
    r->h = 0;
    r->left = NULL;
    r->right = NULL;
    a->raiz = insertAUX(a->raiz, r);
}

void listElem(RAIZ *raiz){
    if(raiz != NULL){
        printf("\n==============");
        printf("\nElem: %d", raiz->num);
        if(raiz->left != NULL) printf("\nEsquerda: %d", raiz->left->num);
        else
            printf("\nEsquerda: NULL");
        if(raiz->right != NULL) printf("\nDireita: %d", raiz->right->num);
        else
            printf("\nDireita: NULL");
        listElem(raiz->left);
        listElem(raiz->right);
    }
}

void listArvore(AAVL *a){
    listElem(a->raiz);
}