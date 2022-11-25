#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strNode{
    Type data;
    struct strNode *next;
};

typedef struct strNode *Node;

struct strQueue{
    Node first;
    Node last;
    size_t size_data;
    unsigned int size;
};

// Funcion para crear una nueva instancia de queue
Queue queueCreate(size_t bytes){
    Queue new = malloc(sizeof(struct strQueue));
    new->first = NULL;
    new->last = NULL;
    new->size_data = bytes;
    new->size = 0;
    return new;
}

unsigned int queueSize(Queue q){
    if(q!=NULL)
        return q->size;
    return 0;
}

bool queueEmpty(Queue q){
    if(q!=NULL) {
        if (q->size>0) return false;
    }
    return true;
}

Node newNode(Type d, size_t bytes){
    Node new = malloc(sizeof(struct strNode));
    new->data = malloc(bytes);
    memcpy(new->data, d, bytes);
    new->next = NULL;
    return new;
}

void enqueue(Queue q, Type d){
    if(q!=NULL){
        Node new = newNode(d, q->size_data);
        if(queueEmpty(q)){
            q->first = new;
            q->last = new;
        }else{
            q->last->next = new;
            q->last = new;
        }
        q->size++;
    }
}

Type queuePeek(Queue q){
    Type data = NULL;
    if(q!=NULL){
        if(!queueEmpty(q)){
            data = malloc(q->size_data);
            memcpy(data, q->first->data, q->size_data);
        }
    }
    return data;
}

Type dequeue(Queue q){
    Type data = NULL;
    if(q!=NULL){
        if(!queueEmpty(q)){
            data=q->first->data;
            Node temp = q->first;
            q->first = temp->next;
            free(temp);
            q->size--;
        }
    }
    return data;
}

void queueDestroy(Queue q){
    if(q!=NULL){
        while(!queueEmpty(q)){
            free(dequeue(q));
        }
        free(q);
    }
}