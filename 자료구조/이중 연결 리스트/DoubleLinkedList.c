#include <stdlib.h>
#include "DoubleLinkedList.h"
#include <stdio.h>
#include <string.h>

linkedlist_h* createLinkedList_h(void) {
    linkedlist_h* DL;
    DL = (linkedlist_h*) malloc(sizeof(linkedlist_h));
    DL->head = NULL;
    return DL;
}

void printList(linkedlist_h* DL) {
    listNode *p;
    if(DL->head == NULL) return;
    p = DL->head;
    printf("( ) = {");
    while(p->rlink != NULL) {

        printf("%s", p->data);
        // if(p->rlink != NULL)
        printf(", ");
        p = p->rlink;
    }
    printf("}\n");
}

void insertNode(linkedlist_h* DL, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if(DL->head == NULL) {
        return;
    } else if(pre->rlink == NULL) {
        pre->rlink = newNode;
        newNode->llink = pre;
        newNode->rlink = NULL;
    } else {
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        pre->rlink->llink = newNode;
    }
}

void deleteNode(linkedlist_h* DL, listNode* old) {
    listNode* pre;
    listNode* p;
    pre = old->llink;
    if(DL->head == NULL || old == NULL) return;
    else {
        if(old == DL->head) {
            pre->rlink = old->rlink;
            old->rlink->llink = pre;
            p = old;
            free(p);
            return;
        }
        pre->rlink = old->rlink;
        old->rlink->llink = pre;
        p = old;
        free(p);
        return;
    }
}

linkedlist_h* searchNode(linkedlist_h* DL, char* x) {
    listNode* temp;
    temp = DL->head;
    while(temp != NULL) {
        if(strcmp(temp->data, x) == 0) return temp;
        else temp = temp->rlink;
    }
    return temp;
}
