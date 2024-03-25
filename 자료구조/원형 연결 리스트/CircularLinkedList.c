// CircularLinkedList.c
#include "CircularLinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

linkedList_h* createLinkedList_h(void) {
    linkedList_h* CL;
    CL = (linkedList_h*)malloc(sizeof(linkedList_h));
    CL->head = NULL;
    return CL;
}

void printNode(linkedList_h* CL) {
    listNode *p;
    printf("CL =(");
    while(CL->head != p->link) {
        printf("%d ", p->data);
        if(p->link != NULL) printf(", ");
    }
}

void insertFirstNode(linkedList_h* CL, char* x) {
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*) malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (CL == NULL) {
        newNode->link = CL->head;
        CL->head = newNode;
    }
    else {
        temp = CL->head;
        while (temp->link != CL) {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = CL->head;
        CL->head = newNode;
    }
}

void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (CL->head == NULL) {
        newNode->link = CL->head;
        CL->head = newNode;
    } else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

linkedList_h* searchNode(linkedList_h* CL, char* x) {
    listNode* temp;
    temp = CL->head;
    if (temp == NULL) return NULL;
    while(CL->head != temp->link) {
        if (strcmp(temp->data, x)) return temp;
        temp = temp->link;
    }
    return NULL;
}

void deleteNode(linkedList_h* CL, listNode* old) {
    listNode* pre;
    if (CL->head == NULL) return;
    else {
        old = pre->link;
        pre->link = old->link;
        if (CL == old) {
            pre->link = old->link;
            CL->head = pre->link;
        }
        free(old);
    }
}
