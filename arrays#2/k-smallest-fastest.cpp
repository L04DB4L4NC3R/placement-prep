/*
 * Fastest way to find the k-smallest or the k-largest element 
 * is to use an algo called "quick selection" which uses quicksort along with selection
 *
 * What we have done here is used the "nth_element" STL function which sorts the nth element
 * so that (by default) all the left values are lesser and right values are greater than the nth element
 * */
#include <iostream>
#include <algorithm>
#include <vector>
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
