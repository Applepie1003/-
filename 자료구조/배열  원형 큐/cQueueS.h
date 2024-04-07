#pragma once
#define Q_SIZE 4

typedef char element;

typedef struct {
    element data[Q_SIZE];
    int front, rear;
} QueueType;

QueueType *createCQueue(); // 큐 만들기
int isCQueueFull(QueueType* cQ); // 큐가 full인지 확인
int isCQueueEmpty(QueueType* cQ); // 큐가 empty인지 확인
void enCQueue(QueueType* cQ, element item); // 큐 삽입
element deCQueue(QueueType* cQ); // 큐 제거
element peekCQ(QueueType* cQ); // 맨위에 있는 큐 반환
void printCQ(QueueType* cQ); // 큐 출력