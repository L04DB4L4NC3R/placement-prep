/*
 
17.8
You are given an array of integers (both positive and negative). Find the contig-
uous sequence with the largest sum. Return the sum.
EXAMPLE
Input: 2, -8, 3, -2, 4, -10
Outputs (i.e., {3, -2, 4})
 
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

// to calc sum of a subarray
int sum(int beg, int end, int arr[]) {
	int s = 0;
	for (int i = beg; i <= end; ++i) {
		s += arr[i];
	}
	return s;
}

void populatemap(unordered_map<int, pair<int, int>> &m, int arr[], int n) {
	int middle = n/2;
	int left = middle, right =  middle;

	int lsum, rsum, s;

	// if left = 0 and right = n-1 then exit
	while(left != 0 || right != n-1) {
		// find left and right sum
		lsum = sum(left, middle, arr);
		rsum = sum(middle, right, arr);

		// if leftsum > rightsum, inc left side
		if (lsum > rsum) {
			middle=left;
			left--;
		} else {
			middle=right;
			right++;
		}


		// if left or right become dangerous, readjust them
		if (left == -1) left = 0;
		if (right == n) right = n - 1;

		// add a sum to pair mapping in a hash map
		m[sum(left, middle, arr)] = pair<int, int>(left, middle);

		// in case left never reaches 0 or right never reaches n-1
		if (m.size() > n/2) {
			break;
		}
	}

	// also include the full array sum
	m[sum(left, right, arr)] = pair<int, int>(left, right);
}

// custom function to find the max key in the hashmap keys
bool maxelem(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first < b.first;
}

// find the max element in the hashmap, according to the largest sum
pair<int, pair<int, int>> findmaxsubsequence(unordered_map<int, pair<int, int>> &m) {
	pair<int, pair<int, int>> mx = *max_element(m.begin(), m.end(), maxelem);
	return mx;
}

int main() {
	//int arr[] = {-1, 2, -3, -4};
	int arr[] = {2, -8, 3, -2, 4, -10};
	int n = sizeof(arr)/sizeof(int);
	unordered_map<int, pair<int, int>> m;

	populatemap(m, arr, n);

	pair<int, pair<int, int>> p = findmaxsubsequence(m);

	/* int mx = *max_element(arr, arr+n);
	if (mx > p.first) {
		cout << mx;
		return 0;
	}
	*/

	for (int i = p.first; i <= p.second.second; ++i) {
		cout << arr[i] << " ";
	}
	return 0;
}
