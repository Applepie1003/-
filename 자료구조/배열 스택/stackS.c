#include "stackS.h"
#include <stdio.h>

int top = -1;

int isStackEmpty() {
    if (top == -1) return 1;
    else return 0;
}

int isStackFull() {
    if (top == STACK_SIZE-1) return 1;
    else return 0;
}

void push(element item) {
    if (isStackFull()) {
        printf("stack이 존재하지 않습니다.\n");
    } else if (isStackEmpty()){
        stack[top++] = item;
    } else {
        stack[top++] = item;
    }
}

element pop() {
    element item;
    if (isStackEmpty()) printf("삭제가능한 노드가 없습니다.\n");
    else {
        item = stack[top];
        stack[top] = 0;
        top--;
        return item;
    }
}

element peek() {
    if (isStackEmpty()) {
        printf("스택이 존재 하지 않습니다.\n");
    }
    else {
        element item;
        item = stack[top];
        return item;
    }
}

void printStack() {
    int i = top;
    printf("\nSTACK [");
    while (i != -1) {
        printf("%d ", stack[i]);
        i--;
    }
    printf("]");
}