#include <stdio.h>

#include "arvoreAVL.h"

void main(){
    AAVL a;
    plantarAAVL(&a);
    
    insertAAVL(&a, 1);
    insertAAVL(&a, 2);
    insertAAVL(&a, 3);
    insertAAVL(&a, 4);
    insertAAVL(&a, 5);
    insertAAVL(&a, 6);
    insertAAVL(&a, 7);
    insertAAVL(&a, 15);
    insertAAVL(&a, 14);
    insertAAVL(&a, 13);
    insertAAVL(&a, 12);
    insertAAVL(&a, 11);
    insertAAVL(&a, 10);
    insertAAVL(&a, 9);
    insertAAVL(&a, 8);

    listArvore(&a);

    liberarArvore(a.raiz);
}