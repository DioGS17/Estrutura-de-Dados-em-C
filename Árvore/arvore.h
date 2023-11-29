#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct aux{
    int num;
    struct aux *left;
    struct aux *right;
} ELEMENTO;


typedef struct{
    ELEMENTO *raiz;
} ARVORE;

void criarArvore(ARVORE *a);
ELEMENTO *insertAUX1(ELEMENTO *raiz, ELEMENTO *elem);
void insertAUX2(ARVORE *a, ELEMENTO *novo);
void insert(ARVORE *a, int num);
void listElem(ELEMENTO *raiz);
void listArvore(ARVORE *a);
int lenArvore(ELEMENTO *raiz);
ELEMENTO *contem(ELEMENTO *raiz, int num);
void pre_ordem(ELEMENTO *raiz);
void in_ordem(ELEMENTO *raiz);
void pos_ordem(ELEMENTO *raiz);

#endif