#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

typedef struct aux{
    int num;
    struct aux *prox;
    struct aux *ante;
} ELEMENTO;

typedef struct listaD{
    ELEMENTO *start;
} ListaD;

// Inicia a lista
void startList(ListaD *list);

// Retorna o tamanho da lista
int lenList(ListaD *list);

// Printa os elementos da lista
void printList(ListaD *list);

// Busca um elemento
int searchElem(ListaD *list, int code);

// Função auxiliar para a inserção ou remoção de um elemento. Deixa a lista em ordem
ELEMENTO *srchElemNPred(ListaD *list, int code, ELEMENTO **pred);

// Insere um elemento e deixa a lista em ordem
int insertElem(ListaD *list, int num);

// Deleta um elemento
int delElem(ListaD *list, int code);

// Reinicia a lista
void restartList(ListaD *list);

// Funções extras

// Insere um elemento e deixa a lista em ordem (Lista duplamente ligada)
int insertElemDL(ListaD *list, int num);

// Função auxiliar para a inserção ou remoção de um elemento. Não deixa a lista em ordem
ELEMENTO *srchElemNPredALT(ListaD *list, int code, ELEMENTO **pred);

// Insere um elemento, mas não deixa a lista em ordem
int insertElemDLalt(ListaD *list, int num);

#endif