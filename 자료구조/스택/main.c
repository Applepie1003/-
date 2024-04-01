#include <stdio.h>
#include "stackL.h"

int main(void) {
    element item;
    top = NULL;
    printf("\n** 연결 스택 연산 **\n");
    printStack();
    printf("\n");

    push(1);    printStack();
    printf("\n");
    push(2);    printStack();
    printf("\n");
    push(3);	  printStack();
    printf("\n");

    item = peek(); printStack();
    printf("\tpeek => %d\n", item);

    item = pop();  printStack();
    printf("\t pop  => %d\n", item);

    item = pop();  printStack();
    printf("\t pop  => %d\n", item);

    item = pop();  printStack();
    printf("\t pop  => %d\n", item);

    getchar();  return 0;
}