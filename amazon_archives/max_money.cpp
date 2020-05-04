// https://practice.geeksforgeeks.org/problems/maximum-money/0
#include <iostream>
#include <cmath>
using namespace std;

int main() {
		int t, n, money;
		cin >> t;

		while(t--) {
				cin >> n >> money;
				cout << ceil((float)n / 2.0) * money << endl;
		}
		return 0;
}

