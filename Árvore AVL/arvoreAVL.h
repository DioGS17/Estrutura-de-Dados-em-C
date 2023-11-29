#ifndef ARVOREAVL_H_INCLUDE
#define ARVORE_H_INCLUDE

typedef struct aux{
    int num;
    int h;
    struct aux *left;
    struct aux *right;
} RAIZ;

typedef struct{
    RAIZ *raiz;
} AAVL;

// Inicia a árvore AVL
void plantarAAVL(AAVL *a);

// Reinicia a árvore AVL
void liberarArvore(RAIZ *raiz);

// Retorna a altura da árvore AVL
int altura(RAIZ *raiz);

// Funções auxiliares para inserção de um elemento na árvore AVL
int max(int n1, int n2);
RAIZ *spinR(RAIZ *raiz);
RAIZ *spinL(RAIZ *raiz);
RAIZ *spinRL(RAIZ *raiz);
RAIZ *spinLR(RAIZ *raiz);
RAIZ *insertAUX(RAIZ *r, RAIZ *ramo);

// Insere um elemento na árvore AVL
void insertAAVL(AAVL *a, int num);

// Lista os elementos da AVL
void listElem(RAIZ *ramo);
void listArvore(AAVL *a);

#endif