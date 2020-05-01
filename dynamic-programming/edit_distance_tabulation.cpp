/* Edit distance problem with tabulation
 */
#include <iostream>
using namespace std;

int min(int x, int y, int z) {
		return min(min(x, y), z);
}

int editDist(string str1, string str2, int m, int n) {

		// create a table to store subproblems
		int dp[m+1][n+1];

		for(int i = 0; i <= m; ++i) {
				for(int j = 0; j <= n; ++j) {
						if(i == 0) 
								dp[i][j] = j;
						else if (j == 0) 
								dp[i][j] = i;
						else if (str1[i-1] == str2[j-1]) 
								dp[i][j] = dp[i-1][j-1];
						else 
								dp[i][j] = 1 + min(dp[i][j-1],   // insert
																	 dp[i-1][j],   // delete
																	 dp[i-2][j-1]); // modify
				}
		}
		return dp[m][n];
}

int main() {
		string s1 = "sunday";
		string s2 = "saturday";
		cout << editDist(s1, s2, s1.length(), s2.length()) << endl;
		return 0;
}
