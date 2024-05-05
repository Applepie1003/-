#include "LinkedQueue.h"
#include "adjList.h"
#include "BFS.h"

// 그래프 g에서 정점 v에 대한 너비 우선 탐색 연산
void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;
	Q = createLinkedQueue();
	g->visited[v] = TRUE;
	printf(" %c", v + 65);
	enLQueue(Q, v);

	// 큐가 공백인 아닌 동안 너비 우선 탐색 수행
	while (!isLQEmpty(Q)) {
		v = deLQueue(Q);
		// 현재 정점 w를 방문하지 않은 경우다
		for (w = g->adjList_H[v]; w; w = w->link)
			if (!g->visited[w->vertex]) {
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				enLQueue(Q, w->vertex);
			}
	}
}