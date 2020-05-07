/* https://practice.geeksforgeeks.org/problems/repetitive-addition-of-digits/0
 *
 * Sum of digits can be found out by 
 * Modulo operation with 9
 *
 * [1] if n is 0, output 0
 * [2] if n % 9 is 0, output 9
 * [3] otherwise output n % 9
	 */
#include <iostream>
using namespace std;

int main() {
	
	int t, sum, interim;
	cin >> t;
    long long int n;
    
	while(t--) {
	    cin >> n;
	    
	    if (n == 0)
	        cout << 0 << endl;
	    else {
	        interim = n % 9;
	        if (interim == 0)
	            cout << 9;
	        else
	            cout << n % 9 << endl;   
	    }
	}
	return 0;
}

