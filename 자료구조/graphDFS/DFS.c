#include <stdio.h>
#include "adjList.h"
#include "stackL.h"
#include "DFS.h"

void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;
	push(v);
	g->visited[v] = TRUE;
	printf(" %c", v + 65);

	// 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
	while (!isStackEmpty()) {
		w = g->adjList_H[v];
		// 인접 정점이 있는 동안 수행
		while (w) {
			// 현재 정점 w를 방문하지 않은 경우 
			if (!g->visited[w->vertex]) {
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			// 현재 정점 w가 이미 방문된 경우
			else w = w->link;
		}
		v = pop();
	}
}