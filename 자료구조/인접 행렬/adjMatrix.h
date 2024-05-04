#pragma once
#define MAX_VERTEX 30

typedef struct graphType {
    int n; // 정점의 개수
    int adjMatrix[MAX_VERTEX][MAX_VERTEX]; // 그래프에 대한 2차원 배열 30*30
} graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjMatrix(graphType* g);
