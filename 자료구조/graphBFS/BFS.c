#include "LinkedQueue.h"
#include "adjList.h"
#include "BFS.h"

// �׷��� g���� ���� v�� ���� �ʺ� �켱 Ž�� ����
void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;
	Q = createLinkedQueue();
	g->visited[v] = TRUE;
	printf(" %c", v + 65);
	enLQueue(Q, v);

	// ť�� ������ �ƴ� ���� �ʺ� �켱 Ž�� ����
	while (!isLQEmpty(Q)) {
		v = deLQueue(Q);
		// ���� ���� w�� �湮���� ���� ����
		for (w = g->adjList_H[v]; w; w = w->link)
			if (!g->visited[w->vertex]) {
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				enLQueue(Q, w->vertex);
			}
	}
}