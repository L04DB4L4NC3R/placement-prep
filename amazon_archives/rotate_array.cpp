// https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
		int t, n, d;
		cin >> t;
		for(int i = 0; i < t; ++i) {
				cin >> n;
				cin >> d;
				int arr[n];

				for(int j = 0; j < n; ++j) 
						cin >> arr[j];
				rotate(arr, arr + d, arr + n);
				for(int j = 0; j < n; ++j) 
						cout << arr[j] << " ";
				cout << endl;
		}
		return 0;
}
