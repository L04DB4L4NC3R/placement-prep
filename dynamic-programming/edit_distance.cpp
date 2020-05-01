// WITHOUT DP
/* Find minimum no of edits 
 * required to convert string1 to string2
 *
 * edits are: Insert, Delete, Modify
 *
    If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
    Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
        Insert: Recur for m and n-1
        Remove: Recur for m-1 and n
        Replace: Recur for m-1 and n-1
*/
#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) {
		return min(min(x, y), z);
}

int editDist(string str1, string str2, int m, int n) {
		if (m == 0)
				return n;
		if(n == 0)
				return m;
		if(str1[m-1] == str2[n-1]) {
				return editDist(str1, str2, m-1, n-1);
		}

		return 1 + min(editDist(str1, str2, m, n-1), // insert
									 editDist(str1, str2, m-1, n), // remove
									 editDist(str1, str2, m-1, n-1)); // replace
}

int main() {
		string str1 = "sunday";
		string str2 = "saturday";

		printf("Edit distance: %d\n", editDist(str1, str2, str1.length(), str2.length()));
		return 0;
}
