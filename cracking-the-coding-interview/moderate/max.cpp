// 17.4 Write a method which finds the maximum of two numbers. You should not use if-else or any other comparison operator.

// NOTE: had to seek solution
/*
 * Logic:
 * [1] Check sign of the negation of the numbers
 * [2] x * sign + y * ~sign
 * Problem is where y is negative then int might overflow
 * in that case take use the sign of the negative num always
 */

#include <iostream>
using namespace std;

// returns 0 if neg
// 1 is +ve
bool sign(int x) {
	// shift x right by 31 bits (since int is 4 bytes)
	// to get the sign bit
	// return !((x >> 31) & 0x1);
	return !((x >> (sizeof(int)*8 -1)) & 0x1);
}

int findmax(int x, int y) {
	// might cause overflow if y is negative
	// in that case check if signs are opposite or not
	bool s = sign(x - y);
	return (s * x) + (!s * y);
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << findmax(x, y);
	return 0;
}
