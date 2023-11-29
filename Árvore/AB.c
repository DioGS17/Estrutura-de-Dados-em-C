#include <stdio.h>

#include "arvore.h"

void main(){
    ARVORE a;
    criarArvore(&a);

    insert(&a, 24);
    insert(&a, 10);
    insert(&a, 32);
    insert(&a, 5);
    insert(&a, 12);
    insert(&a, 29);
    insert(&a, 35);

    listArvore(&a);
}