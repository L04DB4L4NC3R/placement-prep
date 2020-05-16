// https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0
#include <iostream>
using namespace std;


int main() {
	int t, a, ab, abc, n, i;
	string str;
	
	cin >> t;
	while(t--) {
	    cin >> str;
	    // # of ways to select at least 1 a
	    a = 0;
	    // # of ways to select at least 1 b | a
	    ab = 0;
	    // # of ways to select at least 1 c | a and b
	    abc = 0;
	    
	    n = str.length();

			/*
			 * [1] Combinatronics number of 'a's in each turn. 
			 * Number of 'a's in i-th turn = 
			 * number of 'a's in 2*(i-1th turn) + 1
			 * because with the new a in the i-th turn, you can permute the prev combination twice
			 *
			 * [2] Number of 'b' in i-th turn
			 * provided 'a' is already selected
			 * is 2*(no of b in i-1-th turn) + number of 'a's in i-th turn.
			 *
			 * [3] similarily with c provided a and b
			 */
	    for(i = 0; i < n; ++i) {
	        switch (str[i]) {
	            case 'a':
	                a = 1 + 2*a;
	                break;
	            case 'b': 
	                ab = a + 2*ab;
	                break;
	            case 'c':
	                abc = ab + 2*abc;
	                break;
	        }
	    }
	    cout << abc << endl;
	}
	return 0;
}
