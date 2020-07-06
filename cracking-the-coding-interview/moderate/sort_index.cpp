/*
 
17.6
Given an array of integers, write a method to find indices m and n such that if you
sorted elements m through n, the entire array would be sorted. Minimize n - m
(that is, find the smallest such sequence).
EXAMPLE
Input: 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19
Output: (3, 9)

*/

// Had to See the Solution

/*
 * Find end of left subsequence
 * Find end of right subsequence
 * Find min and max element of the middle
 * Slide left until index less than array[min_indexn 
 * Slide right until index greater than array[max_element]
 * Sliding left and right increases the size of the middle, and incorporates unsorted elements so when they get sorted, the whole array will be sorted.
 */
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int endofleft(vector<int> arr) {
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i - 1] > arr[i]) return i - 1;
	}
	return arr.size() - 1;
}

int begofright(vector<int> arr) {
	for (int i = arr.size() - 2; i >=0; --i) {
		if (arr[i + 1] < arr[i]) return i + 1;
	}
	return 0;
}

int shrinkleft(vector<int> arr, int middlemin, int start) {
	int comp = arr[middlemin];

	// include the out of order element in the middle
	for (int i = start - 1; i >= 0; --i) {
		if (arr[i] >= comp) return i - 1;
	}
	return 0;
}

int shrinkright(vector<int> arr, int middlemax, int start) {
	int comp = arr[middlemax];
	for (int i = start; i < arr.size(); ++i) {
		if (arr[i] >= comp) return i - 1;
	}
	return arr.size() - 1;
}

int main() {
	vector<int> arr = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};

	// find end of the left subsequence
	// i.e till where is it sorted
	int endleft = endofleft(arr);

	// find end of the right subsequence
	// i.e till where is the right array sorted
	int endright = begofright(arr);

	// find max and min of the middle subarray
	int middlemin = endleft + 1;
	int middlemax = endright - 1;
	if (middlemin == arr.size()) return 0; // already sorted

	for (int i = endleft; i < endright - 1; ++i) {
		if (arr[i] > arr[i+1]) middlemax = i;
		if (arr[i] < arr[i+1]) middlemin = i;
	}
	// Now we have the 3 subarrays and the max/min elements of the middle subarray
	// lets elongate and incorporate unsorted elements of left and right subarrays
	// in the middle subarray
	
	int left_index = shrinkleft(arr, middlemin, endleft);
	int right_index = shrinkright(arr, middlemax, endright);

	printf("(%d, %d)", left_index, right_index);

	return 0;
}
