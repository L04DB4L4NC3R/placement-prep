// https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t, n, k, i, j, elem;
	
	vector<int> arr;
	
	scanf("%d", &t);
	for(i = 0; i < t; ++i) {
	    scanf("%d", &n);
	    for(j = 0; j < n; ++j) {
	        scanf("%d", &elem);
	        arr.push_back(elem);
	    }
	    scanf("%d", &k);
	    nth_element(arr.begin(), arr.begin() + k-1, arr.end());
	    printf("%d\n", arr[k-1]);
	    arr.clear();
	}
	return 0;
}
