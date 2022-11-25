//
// Created by eduar on 10/20/2022.
//
#include "queue.h"
#include <stdio.h>

int main() {
    Queue q1 = queueCreate(sizeof(char));
    printf("q1 : %p \n", q1);
    printf("size q1 : %d \n", queueSize(q1));
    return 0;
}