/*
 * C(n, k) = n! / ( k! * (n-k)* )
 *
 * Optimal substructure: 
 * C(n, k) + C(n-1, k-1) + C(n-1, k)
 * C(n, 0) = C(n, n) = 1
 */
#include <iostream>
#include <cstring> // for memset
using namespace std;

// recursive solution
int BC(int n, int k) {

	// base case
	if (k == n || k == 0)
			return 1;

	// recursive case
	return BC(n-1, k-1) + BC(n-1, k);
}

// Using dynamic programming
// We solve and place each unique result
// in a table
int BC_DP(int n, int k) {
		int C[n+1][k+1];

		for(int i = 0; i <= n; ++i) {
				for (int j = 0; j <= min(i, k); ++j) {
						if (j == 0 || j == 1) {
								C[i][j] = 1;
						} else {
								C[i][j] = C[i-1][j-1] + C[i-1][j];
						}
				}
		}
		return C[n][k];
}

// Space optimized DP binary coefficients
// Uses a 1D array and pascal triangle
int BC_DP_SO(int n, int k) {
	int C[k+1];
	memset(C, 0, sizeof(C));
	C[0] = 1;
	for(int i = 1; i <= n; ++i) {
			for(int j = min(i, k); j > 0; --j) {
					C[j] = C[j] + C[j-1];
			}
	}
	return C[k];
}

int main() {
		cout << BC(4, 2) << endl;
		cout << BC_DP(4, 2) << endl;
		cout << BC_DP_SO(4, 2) << endl;
		return 0;
}
