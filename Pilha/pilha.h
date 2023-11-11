#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct aux{
    int num;
    struct aux *prox;
} ELEMENTO;

typedef struct{
    ELEMENTO *top;
} PILHA;

// Inicia a pilha
void startLIFO(PILHA *p); 

// Reinicia a pilha
void restartLIFO(PILHA *p);

// Inserir um elemento
void insertElem(PILHA *p, int num);  

// Deletar o primeiro elemento
// Retorna 0 se a pilha estiver vazia (topo == NULL)
// Retorna 1 se deletar o elemento
int delElem(PILHA *p);

// Deletar um elemento pela posição
// Retorna 0 se a pilha estiver vazia (topo == NULL)
// Retorna 1 se deletar o elemento
int delElemPOS(PILHA *p, int pos);

// Retornar o tamanho da pilha
int lenLIFO(PILHA *p);

// Mostra os elementos da pilha
void printLIFO(PILHA *p);

#endif