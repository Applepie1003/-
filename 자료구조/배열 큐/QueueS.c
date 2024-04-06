#include "QueueS.h"
#include <stdio.h>
#include <stdlib.h>

QueueType *createQueue() {
    QueueType *Q;
    Q = (QueueType*) malloc(sizeof(QueueType));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

int isQueueFull(QueueType* Q) {
    if (Q->rear == Q_SIZE-1) return 1;
    else return 0;
}

int isQueueEmpty(QueueType* Q) {
    if (Q->rear == Q->front) return 1;
    else return 0;
}

void enQueue(QueueType* Q, element item) {
    if (isQueueFull(Q)) {
        return;
    } else {
        Q->rear++;
        Q->queue[Q->rear] = item;
    }
}

element deQueue(QueueType* Q) {
    if (isQueueEmpty(Q)) return -1;
    else {
        Q->front++;
        return Q->queue[Q->front];
    }
}

element peekQ(QueueType* Q) {
    if (isQueueEmpty(Q)) return -1;
    else return Q->queue[Q->rear];
}

void printQ(QueueType* Q) {
    printf("Queue = [");
    int i = Q->front + 1;
    for (; i <= Q->rear; i++) {
        printf("%c", Q->queue[i]);
    }
    printf("] ");
}