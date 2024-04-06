#pragma once
#define Q_SIZE 4

typedef char element;

typedef struct {
    element queue[Q_SIZE]; // 큐의 배열
    int front, rear; //  배열 숫자
} QueueType;

QueueType* createQueue();
int isQueueFull(QueueType* Q);
int isQueueEmpty(QueueType* Q);
void enQueue(QueueType* Q, element item);
element deQueue(QueueType* Q);
element peekQ(QueueType* Q);
void printQ(QueueType* Q);