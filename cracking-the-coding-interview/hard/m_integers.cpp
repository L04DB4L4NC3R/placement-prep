/*
 
18.3 Write a method to randomly generates set of m integers from an array of size n.
Each element must have equal probability of being chosen.

*/

// approach:
/*
 * [1] Ways to select m items out of a set of n items = nCm ( Binomial theorem )
 * [2] loop and keep generating random numbers between 0 and max index
 * [3] check if the index is already in the array, if not then increase count and add that in
 * [4] if count == m then break
 */

#include <iostream>
using namespace std;

void generate(int data[], int n, int m) {
	int index;
	int *subset = new int[m];

	// copy the first m numbers in the subset
	for (int i = 0; i < m; ++i) {
		subset[i] = data[m];
	}

	// go in the original array from m to n and select
	// a random number 0 to the iterator and then change the subset
	srand(time(NULL));
	for (int i = m; i < n; ++i) {
		index = rand() % i;
		if (index < m) {
			subset[index] = data[i];
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << subset[i] << endl;
	}
}
int main() {
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int window = 4;
	generate(data, sizeof(data)/sizeof(int), window);
	return 0;
}
