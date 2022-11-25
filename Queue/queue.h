#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <stddef.h>

typedef enum{false, true} bool;

typedef void * Type;

typedef struct strQueue *Queue;

Queue queueCreate(size_t);

unsigned int queueSize(Queue);

bool queueEmpty(Queue);

void queueDestroy(Queue);

void enqueue(Queue, Type);

Type queuePeek(Queue);

Type dequeue(Queue);

#endif //QUEUE_QUEUE_H
