// https://practice.geeksforgeeks.org/problems/trail-of-ones/0
#include <iostream>
#include <cmath>
using namespace std;

/*
2^n - sum of prev 2
*/
int main() {
    int t, n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        if (n == 0 || n == 1) {
            cout << 0 << endl;
            continue;
        }
        if (n == 2) {
            cout << 1 << endl;
            continue;
        }
        
        long a = 2, b = 3, c;
        for(int i = 3; i <= n; ++i) {
            c = a + b;
            if (i == n) {
                cout << (int)pow(2, n) - c << endl;
            }
            a = b;
            b = c;
        }
    }
	//code
	return 0;
}
