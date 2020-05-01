/*
 * Given an array of weights and values and a weight capacity W
 * determine the max value so that the sum of weights <= W
 */
#include <iostream>
using namespace std;

// rescursive solution
int ks(int w, int wt[], int val[], int n) {
		// base case
		if (n == 0 || w == 0) 
				return 0;
		// check if nth item can be included or not
		if (wt[n-1] > w)
				return ks(w, wt, val, n-1);
		// check the maximum of if
		// [1] nth item is included
		// [2] nth item is not included
		return max ( val[n-1] + ks(w - wt[n-1], wt, val, n-1),
					                  ks(w, wt, val, n-1)	);
}


// knapsack using dynamic programming
// uses tabulation to save intermediate results
int ks_dp(int w, int wt[], int val[], int n) {
		int k[n+1][w+1];

		for(int i = 0; i <= n; ++i) {
				for (int j = 0; j <= w; ++j) {
						if(i == 0 || j == 0) 
								k[i][j] = 0;
						else if (wt[i-1] > j) 
								k[i][j] = k[i-1][j];
						else
								k[i][j] = max( val[i-1] + k[i-1][j - wt[i-1]], k[i-1][j]  );
				}
		}
		return k[n][w];
}

int main() {
		int wt[] = {10, 20, 30};
		int val[] = {60, 100, 120};
		int w = 50;

		cout << ks(w, wt, val, 3) << endl;
		cout << ks_dp(w, wt, val, 3) << endl;
		return 0;
}
