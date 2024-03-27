#pragma once

typedef struct ListNode {
    char data[4];
    struct ListNode* llink;
    struct ListNode* rlink;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void printList(linkedList_h* DL);
void insertNode(linkedList_h* DL,listNode* pre, char* x);
void deleteNode(linkedList_h* DL, listNode* old);
linkedList_h *searchNode(linkedList_h* DL, char* x);