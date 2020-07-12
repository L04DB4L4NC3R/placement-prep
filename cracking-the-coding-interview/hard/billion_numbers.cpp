/*
 
18.6 Describe an algorithm to find the smallest one million numbers in one billion
numbers. Assume that the computer memory can hold all one billion numbers.

*/

// NOTE: had to see the solution
// Options :::>
// [1] Sorting O(nlog(n))
// [2] Max Heap of a million nums and keep deleting the largest one O(nlog(m))
// [3] Selection Rank Algorithm (used to find the ith smallest or largest element in an array in linear time) O(n) if unique elems

#include <iostream>
#include <vector>
#include <algorithm>
#define MILLION 7 // million
using namespace std;

// HEAP SOLUTION
void heap_solution() {

	vector<int> billion_nums = {1, 54, 122, 223, 34, 1231, 55435, 12, 12312, 12112};
	vector<int> maxheap;

	// make a heap of the first million numbers
	for (int i = 0; i < MILLION; ++i) {
		maxheap.push_back(billion_nums[i]);
	}
	make_heap(maxheap.begin(), maxheap.end());

	// loop from Million to the end of the vector
	for (int i = MILLION; i < billion_nums.size(); ++i) {
		// for every number which is less than the front of the heap
		// replace it
		if (maxheap.front() > billion_nums[i]) {
			// delete the top (max) element and insert the new element in

			// do it so that the largest element is at the leaf so can be removed easily
			// then pop_back, the heap will heapify automatically
			pop_heap(maxheap.begin(), maxheap.end());
			maxheap.pop_back();

			// push an element and then heapify using the push_heap function
			maxheap.push_back(billion_nums[i]);
			push_heap(maxheap.begin(), maxheap.end());
		}
	}
	for (auto i : maxheap) {
		cout << i << " ";
	}
}

int main() {
	heap_solution();
	return 0;
}
