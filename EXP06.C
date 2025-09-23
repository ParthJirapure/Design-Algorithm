#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
const int MAX = 10000;

typedef struct Edge {
	int u, v, cost;
} Edge;

int find(int parent[], int i) {
	if (parent[i] != i)
		parent[i] = find(parent, parent[i]);
	return parent[i];
}

void union1(int parent[], int rank[], int x, int y) {
	int xroot = find(parent, x);
	int yroot = find(parent, y);

	if (xroot != yroot) {
		if (rank[xroot] < rank[yroot]) {
			parent[xroot] = yroot;
		} else if (rank[xroot] > rank[yroot]) {
			parent[yroot] = xroot;
		} else {
			parent[yroot] = xroot;
			rank[xroot]++;
		}
	}
}

int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;

    if (e1->cost != e2->cost)
        return e1->cost - e2->cost;
    else if (e1->u != e2->u)
        return e1->u - e2->u;
    else
            return e1->v - e2->v;
}

void kruskalMST(int **cost, int V) {
	Edge edges[V * V];
	int edgeCount = 0;

	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			if (cost[i][j] != MAX) {
				edges[edgeCount].u = i;
				edges[edgeCount].v = j;
				edges[edgeCount].cost = cost[i][j];
				edgeCount++;
			}
		}
	}

	qsort(edges, edgeCount, sizeof(Edge), compare);

	int parent[V], rank[V];
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		rank[i] = 0;
	}

	int mstCost = 0, edgesInMST = 0;

	for (int i = 0; i < edgeCount && edgesInMST < V - 1; i++) {
		int u = edges[i].u;
		int v = edges[i].v;

		int set_u = find(parent, u);
		int set_v = find(parent, v);

		if (set_u != set_v) {
				printf("Edge %d:(%d, %d) cost:%d\n", edgesInMST, u, v, edges[i].cost);
			mstCost += edges[i].cost;
			union1(parent, rank, set_u, set_v);
			edgesInMST++;
		}
	}
    
	printf("Minimum cost= %d\n", mstCost);
}

int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}