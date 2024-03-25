#pragma once

typedef struct ListNode {
    struct ListNode* llink;
    char data[4];
    struct ListNode* rlink;
} listNode;

typedef struct {
    listNode* head;
} linkedlist_h;

linkedlist_h* createLinkedList_h(void);
void printList(linkedlist_h* DL);
void insertNode(linkedlist_h* DL, listNode* pre, char* x);
void deleteNode(linkedlist_h* DL, listNode* old);
linkedlist_h* searchNode(linkedlist_h* DL, char* x);

