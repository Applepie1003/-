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

void insertRear(DQueType* DQ, element item) {
    DQnode *newnode;
    newnode = (DQnode*) malloc(sizeof(DQnode));
    newnode->data = item;
    if (isDQueEmpty(DQ)) {
        DQ->front = newnode;
        DQ->rear = newnode;
    } else {
        newnode->rlink = NULL;
        newnode->llink = DQ->rear;
        DQ->rear->rlink = newnode;
        DQ->rear = newnode;
    }
}

element deleteFront(DQueType* DQ) {
    DQnode *old;
    element item;
    old = DQ->front;
    if (isDQueEmpty(DQ)) {
        printf("삭제할 데이터가 존재 하지 않습니다.");
        return 0;
    } else {
        item = DQ->front->data;
        if (DQ->front == DQ->rear) {
            old = DQ->front;
            DQ->front = NULL;
            DQ->rear = NULL;
        } else {
            DQ->front = DQ->front->rlink;
            DQ->front->llink = NULL;
        }
        free(old);
        return item;
    }
}
// 노드를 삭제하고 노드의 데이터를 반환함

element deleteRear(DQueType* DQ) {
    DQnode *old;
    element item;
    if (isDQueEmpty(DQ)) {
        printf("삭제할 데이터가 존재하지 않습니다.");
        return 0;
    } else {
        item = DQ->rear->data;
        old = DQ->rear;
        if (DQ->front == DQ->rear) {
            DQ->front = NULL;
            DQ->rear = NULL;
        } else {
            DQ->rear = DQ->rear->llink;
            DQ->rear->rlink = NULL;
        }
        free(old);
        return item;
    }
}

element peekFront(DQueType* DQ) {
    element temp;
    if (isDQueEmpty(DQ)) {
        printf("데이터가 존재 하지 않습니다.");
        return 0;
    } else {
        temp = DQ->front->data;
        return temp;
    }
}

element peekRear(DQueType* DQ) {
    element temp;
    if (isDQueEmpty(DQ)) {
        printf("데이턱 존재하지 않습니다.");
        return 0;
    } else {
        temp = DQ->rear->data;
        return temp;
    }
}

void printDQ(DQueType* DQ) {
    DQnode *p;
    p = DQ->front;
    printf("deQue [");
    while (p != NULL) {
        printf(" %c", p->data);
        p = p->rlink;
    }
    printf("]");
}