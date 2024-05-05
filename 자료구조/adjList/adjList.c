#include "adjList.h"
#include <stdio.h>
#include <stdlib.h>

// 공백 그래프 생성
void createGraph(graphType* g) {
    int v;
    g->n = 0;
    for( v = 0; v < MAX_VERTEX; v++) {
        g->adjList_H[v] = NULL;
    }
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTEX) {
        printf("\n 그래프 정점의 개수를 초과했습니다");
        return;
    }
    g->n++; // 그래프 정점의 개수를 하나씩 증가
}

void insertEdge(graphType* g, int u, int v) {
    graphNode* node;
    // 정점 (u, v)가 현재 그래프에 있는지 확인
    if (u >= g->n || v >= g->n) {
        printf("\n 그래프에 없는 정점입니다!");
        return;
    }
    node = (graphNode*)malloc(sizeof (graphNode)); // 메모리 누수 발생
    node->vertex = v;
    node->link = g->adjList_H[u]; // 삽입 간선에 대한 노드를 리스트의 첫 번째 노드로 연결
    g->adjList_H[u] = node;
}

void print_adjList(graphType* g) {
    int i;
    graphNode* p;
    for (i = 0; i < g->n; i++) {
        printf("\n\t\t정점 %c의 인접 리스트", i + 65);
        p = g->adjList_H[i];
        while (p) {
            printf(" -> %c", p->vertex + 65);
            p = p->link;
        }
    }
}