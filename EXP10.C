#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N

int min(int a, int b) {
	 return (a < b) ? a : b;
}

int main() {
	int n, e;
	printf("Enter the number of vertices : ");
	scanf("%d", &n);
	printf("Enter the number of edges : ");
	scanf("%d", &e);

	int dist[MAX_N+1][MAX_N+1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		int u, v, w;
		printf("Enter source : ");
		scanf("%d", &u);
		printf("Enter destination : ");
		scanf("%d", &v);
		printf("Enter weight : ");
		scanf("%d", &w);
		dist[u][v] = w;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				printf("%5s", "INF");
			else
				printf("%5d", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}