#include "LinkedQueue.h"
#include <stdio.h>
#include <stdlib.h>

LQueuetype *createLinkedQueue() {
    LQueuetype *LQ;
    LQ = (LQueuetype*) malloc(sizeof(LQueuetype));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

int isLQueueEmpty(LQueuetype* LQ) {
    if (LQ->front == NULL) return 1;
    else return 0;
}

void enLQueue(LQueuetype* LQ, element item) {
    Qnode *newnode;
    newnode = (Qnode*) malloc(sizeof (Qnode));
    if (isLQueueEmpty(LQ)) {
        LQ->front = newnode;
    } else {
        LQ->rear->link = newnode;
    }
    LQ->rear = newnode;
    newnode->link = NULL;
    newnode->data = item;
}

element deLQueue(LQueuetype* LQ) {
    Qnode* p = LQ->front;
    element item;
    if (isLQueueEmpty(LQ)) {
        printf("삭제할 도드가 없습니다.");
        return 0;
    } else {
        item = p->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL)
            LQ->rear = NULL;
        free(p);
        return item;
    }
}

element peekLQ(LQueuetype* LQ) {
    if (isLQueueEmpty(LQ)) return 0;
    else return LQ->rear->data;
}

void printLQ(LQueuetype* LQ) {
    Qnode *temp;
    temp = LQ->front;
    printf("Linked Queue = [");
    while (temp != NULL) {
        printf(" %c", temp->data);
        temp = temp->link;
    }
    printf("]");
}
