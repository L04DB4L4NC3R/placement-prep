// 17.1 Write a function to swap a number in place (that is, without temporary variables).

#include <iostream>
using namespace std;

void swap(int &x, int &y) {
	x = x + y;
	y = x - y;
	x = x - y;
}

int main() {
	int x, y;
	cin >> x >> y;
	printf("x is %d and y is %d before swap\n", x, y);
	swap(x, y);
	printf("x is %d and y is %d after swap", x, y);
	return 0;
}
