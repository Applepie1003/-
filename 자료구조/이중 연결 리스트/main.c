// main.c
#include <stdlib.h>
#include <stdio.h>
#include "DoubleLinkedList.h"

int main(void) {
    linkedList_h *DL;
    listNode* p;

    DL = createLinkedList_h();  // ???? ?????
    printf("(1) 공백 리스트 생성하기 \n");
    printList(DL);

    printf("\n(2)\n");
    insertNode(DL, NULL, "월");
    printList(DL);

    printf("\n(3) \n");
    p = searchNode(DL, "??"); insertNode(DL, p, "금");
    printList(DL);

    printf("\n(4)\n");
    p = searchNode(DL, "월"); insertNode(DL, p, "수");
    printList(DL);

    printf("\n(5)\n");
    p = searchNode(DL, "수"); deleteNode(DL, p);
    printList(DL);

    getchar();
    return 0;
}