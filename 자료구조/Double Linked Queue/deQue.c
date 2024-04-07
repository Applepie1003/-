#include "deQue.h"
#include <stdio.h>
#include <stdlib.h>

DQueType *createDQue() {
    DQueType *DQ;
    DQ = (DQueType*) malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

int isDQueEmpty(DQueType* DQ) {
    if (DQ->front == NULL) return 1;
    else return 0;
}

void insertFront(DQueType* DQ, element item) {
    DQnode *newnode;
    newnode = (DQnode*) malloc(sizeof (DQnode));
    newnode->data = item;
    if (isDQueEmpty(DQ)) {
        DQ->front = newnode;
        DQ->rear = newnode;
    } else {
        newnode->rlink = DQ->front;
        DQ->front->llink = newnode;
        newnode->llink = NULL;
        DQ->front = newnode;
    }
}

void