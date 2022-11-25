#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int * newInt(int valor){
    int *new = malloc(sizeof(int));
    *new = valor;
    return new;
}

int main(){
    Stack s1=stack_create();
    printf("s1=  %p\n",s1);
    stack_push(s1, newInt(10));
    int *dato;
    dato = stack_top(s1);
    printf("Top s1: %d\n",*dato);


    return 0;
}


