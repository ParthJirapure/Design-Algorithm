#include <stdio.h>

int max(int a, int b) {
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int N) {
	int dp[N+1][W+1];
	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				dp[i][w] = 0;
			else if (wt[i-1] <= w)
				dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
			else
				dp[i][w] = dp[i-1][w];
		}
	}
	return dp[N][W];
}

int main() {
	int N;
	scanf("%d", &N);
	int val[N], wt[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &val[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &wt[i]);
	}
	int W;
	scanf("%d", &W);
	int result = knapSack(W, wt, val, N);
	printf("%d\n", result);
	return 0;
}