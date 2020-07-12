/*

18.5 You have a large text file containing words. Given any two words, find the
shortest distance (in terms of number of words) between them in the file. If the
operation will be repeated many times for the same file (but different pairs of
words), can you optimize your solution?

 */

// my approach -> fill hashmap up with word and its index
// multiple occurrences will be there, so in that case, push in a vector
// then after its done, find the lowest arithmetic difference between the two vectors
//
// Time complexity = O(m * n) where m and n are the occurences of word 1 and 2
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void makehashmap(unordered_map<string, vector<int>> &m, string words[], int n) {
	for (int i = 0; i < n; ++i) {
		m[words[i]].push_back(i);
	}
}

int find_difference(vector<int> l1, vector<int> l2) {
	int diff;
	int min = abs(l2[0] - l1[0]);

	for (auto i : l1) {
		for (auto j : l2) {
			diff = abs(j-i);
			if (min > diff) {
				min = diff;
			}
		}
	}
	return min;
}

int main() {
	string file[] = {"my", "name", "is", "gopi", "is", "the",
					"Delhi", "me", "airport", "Palam", "is", "the", "my", "my"};

	string w1 = "my", w2="the";

	unordered_map<string, vector<int>> m;
	makehashmap(m, file, 14);
	cout << find_difference(m[w1], m[w2]);
	return 0;
}
