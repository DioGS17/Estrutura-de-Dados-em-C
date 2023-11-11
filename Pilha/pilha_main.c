#include <stdio.h>

#include "pilha.h"

void main(){
    PILHA p;
    startLIFO(&p);

    insertElem(&p, 3);
    insertElem(&p, 1);
    insertElem(&p, 5);
    insertElem(&p, 0);
    int tam = lenLIFO(&p);
    printf("\nTamanho: %d", tam);
    printLIFO(&p);

    delElem(&p);

    tam = lenLIFO(&p);
    printf("\nTamanho: %d", tam);
    printLIFO(&p);

    restartLIFO(&p);
}