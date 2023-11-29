#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct aux{
    int elem;
    struct aux *prox;
} ELEMENTO;

typedef struct{
    ELEMENTO *start;
    ELEMENTO *end;
} FILA;

// Inicia a fila
void startFIFO(FILA *f);

// Reinicia a fila
void restartFIFO(FILA *f);

// Insere um elemento
void insertElem(FILA *f, int elem);

// Deleta o primeiro elemento
int delElem(FILA *f);

// Tamanho da fila
int lenFIFO(FILA *f);

// Mostra os elementos da fila
void printFIFO(FILA *f);

#endif