// 17.3 Write an algorithm which computes the number of trailing zeros in n factorial.

// O(1) solution
// acting theory:
// 0-4 = 0 trailing zeroes
// 5-9 = 1
// 10 - 14 = 2
// therefore fact of x will have:
// x/5 if x is divisible by 5
// else if last digit of fact > 5 then x/5 + 1 else x/5
//
// because 11/5 = 2 trailing zeroes correct
// but 26/5 = 5 not, 5+1 needed for last digit > 5

#include <iostream>
using namespace std;

int numberofzeros(int x) {
	if (x%5 == 0) {
		return x/5;
	}
	return (x%10 > 5)? x/5 + 1 : x/5;
}

int main() {
	int x;
	cin >> x;
	cout << numberofzeros(x); 
	return 0;
}
