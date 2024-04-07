#include "cQueueS.h"
#include <stdio.h>
#include <stdlib.h>

QueueType *createCQueue() {
    QueueType * cQ;
    cQ = (QueueType*) malloc(sizeof (QueueType));
    cQ->front = 0;
    cQ->rear = 0;
    return cQ;
}

int isCQueueEmpty(QueueType* cQ) {
    if (cQ->rear == cQ->front) return 1;
    else return 0;
}

int isCQueueFull(QueueType* cQ) {
    if (cQ->front == ((cQ->rear+1) % Q_SIZE)) return 1;
    else return 0;
}

void enCQueue(QueueType* cQ, element item) {
    if (isCQueueFull(cQ)) return;
    else {
        cQ->rear = (cQ->rear+1) % Q_SIZE;
        cQ->data[cQ->rear] = item;
    }
}

element deCQueue(QueueType *cQ) {
    if (isCQueueEmpty(cQ)) return -1;
    else {
        cQ->front = (cQ->front+1) % Q_SIZE;
        return cQ->data[cQ->front];
    }
}

element peekCQ(QueueType* cQ) {
    if (isCQueueEmpty(cQ)) return -1;
    else return cQ->data[(cQ->front+1) % Q_SIZE];
}

void printCQ(QueueType* cQ) {
    int first = (cQ->front+1) % Q_SIZE;
    int last = (cQ->rear+1) % Q_SIZE;
    int i = first;
    printf("cQueue = [");
    while (i != last) {
        printf("%c", cQ->data[i]);
        i = (i+1) % Q_SIZE;
        if (i != last) printf(" ");
    }
    printf("]");
}