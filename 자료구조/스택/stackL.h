#pragma once

// int형 노드 데이터 element
typedef int element;

// 스택 노드 생성
typedef struct stackNode {
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top;

int isStackEmpty();
void push(element item);
element pop();
element peek();
void printStack();
