#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count = 0;

bool isSafe(int board[], int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i] == col || abs(board[i] - col) == abs(i - row))
			return false;
	}
	return true;
}

void solveNQueen(int board[], int row, int n) {
	if (row == n) {
		count++;
		return;
	}

	for (int col = 0; col < n; col++) {
		if (isSafe(board, row, col)) {
			board[row] = col;
			solveNQueen(board, row + 1, n);
		}
	}
}

int nQueen(int n) {
	count = 0;
	int board[15];
	solveNQueen(board, 0, n);
	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", nQueen(n));
	return 0;
}