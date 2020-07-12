/*
 
18.1
Write a function that adds two numbers. You should not use + or any arithmetic
operators.

 */

#include <iostream>
using namespace std;

// NOTE: had to see the solution

// first sum without carry
// then sum with carry recursively
int add (int a, int b) {
	if (b == 0) return a;
	int sum = a ^ b; // sum without carry
	int carry = (a & b) << 1; // only carries, left shift because ones place needs no carry
	return add (sum, carry); // do this until carry is 0
}

int main() {
	int a, b;
	cout << "Enter a and b\n";
	cin >> a >> b;
	cout << add (a, b);
	return 0;
}
