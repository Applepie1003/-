#pragma once

typedef char element;

typedef struct DQnode {
    element data;
    struct DQnode* llink;
    struct DQnode* rlink;
} DQnode;

typedef struct {
    DQnode *front, *rear;
} DQueType;

DQueType *createDQue();
int isDQueEmpty(DQueType* DQ);
void insertFront(DQueType* DQ, element item);
void insertRear(DQueType* DQ, element item);
element deleteFront(DQueType* DQ);
element deleteRear(DQueType* DQ);
element peekFront(DQueType* DQ);
element peekRear(DQueType* DQ);
void printDQ(DQueType* DQ);