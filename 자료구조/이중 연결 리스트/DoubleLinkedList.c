#include "DoubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linkedList_h *createLinkedList_h(void) {
    linkedList_h * DL;
    DL = (linkedList_h*) malloc(sizeof(linkedList_h));
    DL->head = NULL;
    return DL;
}

void printList(linkedList_h* DL) {
    listNode *p;
    p = DL->head;
    printf("DL = (");
    while(p != NULL) {
        printf("%s", p->data);
        if (p->rlink != NULL) printf(", ");
        p = p->rlink;
    }
    printf(") \n");
}

void insertNode(linkedList_h* DL, listNode* pre, char* x) {
    listNode *newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if (DL->head == NULL) {
        newNode->llink = NULL;
        newNode->rlink = NULL;
        DL->head = newNode;
    } else if (pre->rlink == NULL){
        newNode->llink = pre;
        pre->rlink = newNode;
        newNode->rlink = NULL;
    } else {
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        pre->rlink->llink = newNode;
    }
}

void deleteNode(linkedList_h* DL, listNode* old) {
    if (DL == NULL) return;
    else if (old == NULL) return;
    else {
        if (old->rlink == NULL) {
            old->llink = NULL;
            free(old);
        } else {
            old->llink->rlink = old->rlink;
            old->rlink->llink = old->llink;
            free(old);
        }
    }
}

linkedList_h* searchNode(linkedList_h* DL, char* x) {
    listNode *temp;
    temp = DL->head;

    while (temp->rlink != NULL) {
        if (strcmp(temp->data, x) == 0) return temp;
        else temp = temp->rlink;
    }
    return temp;
}