#include <stdio.h>
#include "ListaD.h"

void main(){
    ListaD list;
    startList(&list);

    int tam = lenList(&list);
    printf("\nTamanho da lista: %d", tam);

    printf("\n================================");
    insertElem(&list, 20);
    insertElem(&list, 5);
    insertElem(&list, 0);
    insertElem(&list, 145);
    insertElem(&list, 2139);
    tam = lenList(&list);
    printf("\nTamanho da lista: %d", tam);

    printList(&list);

    restartList(&list);
}