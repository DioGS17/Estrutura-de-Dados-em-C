#include <stdio.h>

#include "fila.h"

void main(){
    FILA f;
    startFIFO(&f);

    insertElem(&f, 9);
    insertElem(&f, 1);
    insertElem(&f, 7);
    insertElem(&f, 32);
    printFIFO(&f);
    printf("\nTamanho da fila: %d", lenFIFO(&f));

    delElem(&f);
    printFIFO(&f);
    printf("\nTamanho da fila: %d", lenFIFO(&f));


    restartFIFO(&f);
}