#include "stackL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isStackEmpty() {
    if (top == NULL) return 1;
    else return 0;
}
// isStackFull 함수는 넣을 필요가 없다.
// 연결 리스트로 구현한 스택함수는 무한으로 스택을 쌓을수 있기 떄문이다.

void push(element item) {
    stackNode *newNode;
    newNode = (stackNode*)malloc(sizeof(stackNode));
    if (isStackEmpty()) {
        newNode->link = NULL;
        newNode->data = item;
        newNode->link = NULL;
        top = newNode;
    } else {
        newNode->link = top;
        newNode->data = item;
        top = newNode;
    }
}

element pop() {
    stackNode *temp;
    element item;
    if (isStackEmpty()) {
        return 0;
    }
    temp = top;
    item = temp->data;
    top = temp->link;
    free(temp);
    return item;
}

void printStack() {
    stackNode* temp;
    element p;

    temp = top;
    printf("STACK [");
    while(temp != NULL) {
        p = temp->data;
        printf("%d", p);
        temp = temp->link;
    }
    printf(" ]");
}

element peek() {
    element item;
    if (isStackEmpty()) {
        return 0;
    }
    item = top->data;
    return item;
}
