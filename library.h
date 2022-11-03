#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct node {
    char* data;
    struct node* next;
    struct node* prev;
} node;

typedef struct list {
    node* head;
    node* tail;
    node* current;
} list;

list* create_list();

void add_node(list* l, char* data);

void print_list(list* l);

#endif // LIBRARY_H