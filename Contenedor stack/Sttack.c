#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strNode{
    Type data;
    struct strNode *prior;
};

typedef struct strNode * Node;

struct strStack{
    Node top;
    unsigned int size;
};

Stack stack_create(){
    Stack NewStack = malloc(sizeof(struct strStack));
    NewStack->top = NULL;
    NewStack->size = 0;
    return NewStack;
}

int stack_size(Stack s){
    if(s!=NULL){
        if (s->size>=0){
            return s->size;
        }
    }
}

Bool stack_isEmpty(Stack s){
    if(s->top!=NULL){
        return FALSE;
    }
    else{
        return TRUE;
    }
}

Node newNode(Type data){
    Node NewNode = malloc(sizeof(struct strNode));
    NewNode->data = data;
    NewNode->prior = NULL;
    return NewNode;
}

void stack_push(Stack s, Type data){
    if (s!=NULL){ //Existe el stack?
        Node NewNode = newNode(data); //Crea el nuevo nodo e inicializr
        if(stack_isEmpty(s)){
            s->top = NewNode;
        }
        else{
            //Agregar el nodo al tope
            NewNode->prior = s->top;
            //tope ahora apunta al nuevo nodo
            s->top = NewNode;
        }
        s->size+=1;
    }
}

//Permite conocer el elemento que se encuentra en el tope de la pila
Type stack_top(Stack s){
    if(s!=NULL){
        if (stack_isEmpty(s)){
            return NULL;
        }
        else{
            return s->top->data;
        }
    }
    return NULL;
}

Type stack_pop(Stack s){
    if(s!=NULL){ //Existe el stack?
        if (stack_isEmpty(s)){
            return NULL;
        }
        else{
            //Apunta a quien sera el nuevo tope
            Node temp = s->top->prior;
            //Apuntar al dato que se va a retornar
            Type data = s -> top ->data;
            //Elimina el tope actual
            free(s->top);
            //mover top al nodo que es el nuevo tope
            s->top = s->top->prior;
            s->size-=1;
            return data;
        }
    }
    return NULL;
}

void stack_destroy(Stack s){
    Type temp;
    while(!stack_isEmpty(s)){
        temp = stack_pop(s);
        free(temp);
    }
    free(s);
}