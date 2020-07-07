/*
 
17.12 Design an algorithm to find all pairs of integers within an array which sum to a
specified value.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printpairs(vector<int> v, int sum) {
	unordered_map<int, bool> m;

	for(auto i : v) {
		if (m.find(sum - i) != m.end()) {
			cout << "pair found (" << i << ", " << sum - i << ")" << endl;
		}
		m[i] = true;
	}
}

int main() {
	vector<int> v = {2, 8, 5, 4, 7, 1, 3, 9, 2, 0, 1};
	int tobe = 10;
	printpairs(v, tobe);
	return 0;
}
