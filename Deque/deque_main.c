#include <stdio.h>

#include "deque.h"

void main(){
    DEQUE d1;
    startDEQUE(&d1);

    insertElemEND(&d1, 2);
    insertElemEND(&d1, 5);
    insertElemBEGIN(&d1, 3);
    insertElemBEGIN(&d1, 10);
    insertElemEND(&d1, 23);
    printDEQUE(&d1);
    printf("\nTamanho do deque: %d", lenDEQUE(&d1));

    delElemBEGIN(&d1);
    delElemEND(&d1);
    printDEQUE(&d1);
    printf("\nTamanho do deque: %d", lenDEQUE(&d1));


    restartDEQUE(&d1);
}