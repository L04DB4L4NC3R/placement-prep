// https://practice.geeksforgeeks.org/problems/sorted-matrix/0
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t, n, data, len;
	cin >> t;
	for (int i = 0; i < t; ++i) {
	   cin >> n; 
		 int arr[n * n];
		 len = n * n;
		 for(int j = 0; j < len; ++j) {
				 cin >> arr[j];
				 if (j % n == 0 || j == len - 1) {
						 sort(arr, arr + j);
				 }
		 }
		 for(int x = 0; x < n * n; ++x) {
				 cout << arr[x] << " ";
		 }
		 cout << endl;
	}
	return 0;
}
