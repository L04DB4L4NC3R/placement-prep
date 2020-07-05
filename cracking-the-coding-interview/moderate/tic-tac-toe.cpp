// 17.2 design an algorithm to figure out if someone has won a game of tic-tac-toe.
#include <iostream>
#define N 3
using namespace std;

bool is_winner(int mat[][N]) {
	int left_diag = 0;
	int right_diag = 0;
	int horizontal_cnt = 0;
	int vertical_cnt = 0;
	
	// Check for diagonals first
	// O(n) in this case
	for (int i = 0; i < N; ++i) {
		left_diag += mat[i][i];
		right_diag += mat[i][N-1-i];
	}
	if (left_diag == N || right_diag == N) {
		return true;
	}

	// for the arms
	// O(n^2) in this case
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// for the horizontal arms
			horizontal_cnt += mat[i][j];

			// for the vertical arms
			vertical_cnt += mat[j][i];
		}
		if (horizontal_cnt == N || vertical_cnt == N) {
			return true;
		} else {
			horizontal_cnt = 0;
			vertical_cnt = 0;
		}
	}
	return false;
}


int main() {
	int game[N][N] = { {true, false, true}, 
						{false, true, false},
						{true, false, false} };
	if (is_winner(game)) {
		cout << "Winner";
	} else {
		cout << "Loser";
	}
	return 0;
}
