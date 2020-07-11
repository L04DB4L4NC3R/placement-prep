/*
 
18.10 Given two words of equal length that are in a dictionary, write a method to
transform one word into another word by changing only one letter at a time.
The new word you get in each step must be in the dictionary.
EXAMPLE
Input: DAMP, LIKE
Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE

*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void makehashmap(unordered_map<string, bool> &m, string dict[], int n) {
	for(int i = 0; i < n; ++i) {
		m[dict[i]] = true;
	}
}


// [1] loop through input
// [2] change first letter to the result's first
// [3] if resultant word in dict, continue to the second letter
// [4] else continue to the second letter and keep going but come back to the first one later
// Do so by maintaining a list of indices which couldn't be changed.
void step_up_transformer(unordered_map<string, bool> dict, string input, string result) {

	vector<int>remaining_indices;
	int n = input.length();
	if (n != result.length()) {
		cout << "400 bad input";
		return;
	}

	char temp;
	cout << input << " ";
	for (int i = 0; i < n; ++i) {
		if (input[i] == result[i]) {
			continue; // if the letters are the same
		}

		// if not the same then switch the letter and see if in dict
		temp = input[i];
		input[i] = result[i];
		if (dict.find(input) != dict.end()) { // if the switched letter gets to stay
			cout << input << " ";
			continue;
		}

		// if not then reassign it back and continue to the rest of the word
		input[i] = temp;
		remaining_indices.push_back(i);
	}

	// after it has gone through the word once
	// it only needs to go through the remaining indices
	// if 2 indices remaining then max number of loops would be 3 
	// 0 -> 0
	// 1 -> 1
	// 2 -> 3
	// 3 -> 6
	// 4 -> 10
	// 5 -> 15
	// therefore max iterations for nth number = sum of the first n numbers
	int max_iter = (n*(n+1)/2);

	int count = 0;
	for(int i = 0; count < max_iter && !remaining_indices.empty(); ++i, ++count) {

		if (i == remaining_indices.size()) i = 0;
		temp = input[remaining_indices[i]];
		input[remaining_indices[i]] = result[remaining_indices[i]];
		if (dict.find(input) != dict.end()) { // if the switched letter gets to stay
			cout << input << " ";
			// remove i from the vector
			remaining_indices.erase(remaining_indices.begin() + i);
			continue;
		}
		input[remaining_indices[i]] = temp;
	}

	if (input != result) {
		cout << " NADA! string cannot be converted";
	}
}

int main() {
	string dictionary[] = {"DAMP", "LAMP", "LIMP", "LIME", "LIKE"};

	unordered_map<string, bool> dict;
	makehashmap(dict, dictionary, 5);
	string input = "DAMP", result = "LIKE";
	step_up_transformer(dict, input, result);
}
