#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

typedef struct aux{
    int elem;
    struct aux* ante;
    struct aux* prox;
} ELEMENTO;

typedef struct {
    ELEMENTO *head;
} DEQUE;

// Inicializa o deque
void startDEQUE(DEQUE *d);

// Reinicializa o deque
void restartDEQUE(DEQUE *d);

// Retorna o tamanho do deque
int lenDEQUE(DEQUE *d);

// Mostra os elementos do deque
void printDEQUE(DEQUE *d);

// Insere um elemento no começo
void insertElemBEGIN(DEQUE *d, int n);

// Insere um elemento no final
void insertElemEND(DEQUE *d, int n);

// Deleta o primeiro elemento
int delElemBEGIN(DEQUE *d);

// Deleta o último elemento
int delElemEND(DEQUE *d);

// Funções extras

// Intercarla os elementos de dois deques e retorna um terceiro deque
DEQUE intercala(DEQUE *d1, DEQUE *d2);

#endif