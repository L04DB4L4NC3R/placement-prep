// https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0
#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
		//code
		int t, n;
		cin >> t;

		while(t--) {
				cin >> n;
				int arr[n];
				unordered_set<int> s;
				for(int i = 0; i < n; ++i) {
						cin >> arr[i];
						arr[i] *= arr[i];
						s.insert(arr[i]);
				}
				bool flag = false;
				for(int  i = 0; i < n-1; ++i) {
						if (flag) {
								break;
						}
						for(int j = i; j < n; ++j) {
								if (s.find(arr[i] + arr[j]) != s.end()) {
										flag = true;
										break;
								}
						}
				}
				if (!flag) {
						cout << "No" << endl;
				} else {
						cout << "Yes" << endl;
				}
		}
		return 0;
}
