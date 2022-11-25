/*
 * List.h
 *
 *  Created on: 1 nov. 2022
 *      Author: FCERVANTES
 */

#include <stddef.h>

#ifndef LIST_H_
#define LIST_H_

typedef void * Type;

typedef struct strList *List;

typedef struct strNode *Node;

List listCreate(size_t);

unsigned int listSize(List);

void listAdd(List, Type);

Type listGet(List, int);

int listSearch(List, Type);

Type listRemove(List, int);

#endif /* LIST_H_ */























