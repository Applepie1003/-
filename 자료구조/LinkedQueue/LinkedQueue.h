#pragma once

typedef char element;

typedef struct Qnode {
    element data;
    struct Qnode* link;
} Qnode;

typedef struct {
    Qnode *front, *rear;
} LQueuetype;

LQueuetype *createLinkedQueue();
int isLQueueEmpty(LQueuetype* LQ);
void enLQueue(LQueuetype* LQ, element item);
element deLQueue(LQueuetype* LQ);
element peekLQ(LQueuetype* LQ);
void printLQ(LQueuetype* LQ);
