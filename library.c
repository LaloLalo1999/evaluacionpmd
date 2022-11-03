#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strNode {
    Type data;
    struct strNode * prev;
    struct strNode * next;
};
typedef struct strNode * Node;

struct strList {
    Node first;
    Node last;
    Node current;
    unsigned int size;
    size_t data_size;
};

List createList() {
    List list = (List) malloc(sizeof(struct strList));
    list->first = NULL;
    list->last = NULL;
    list->current = NULL;
    list->size = 0;
    list->data_size = 0;
    return list;
}