/*
 
18.7
Given a list of words, write a program to find the longest word made of other
words in the list.
EXAMPLE
Input: cat,
banana, dog, nana, walk, walker, dogwalker
Output: dogwalker

 */

// NOTE: had to see solution
// [1] Iterate through all the words
// [2] Find all possible pairs of a word and check if left and right exist in the map
// [3] if yes then return the word
// [4] This solves it for words formed by 2 words. For more words recurse the right side

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool validconcat(string word, unordered_map<string, bool> m, bool isoriginal) {
	int len = word.length();

	// if not original and exists in the dictionary
	// then check if the word has been deactivated or not, this will tell us when to stop
	if (m.find(word) != m.end() && !isoriginal) {
		return m[word];
	}
	string left, right;
	for (int i = 1; i < len; ++i) {
		left = word.substr(0, i);	
		right = word.substr(i);
		if (m.find(left) != m.end() && m[left] && validconcat(right, m, false)) {
			return true;
		}
	}

	// after the word has been checked and its not a valid concatenation
	// then let it be in the dict but deactivate it since it cannot be broken down further
	m[word] = false;
	return false;
}

string longest_word(vector<string> list, unordered_map<string, bool> m) {

	int maxlenstr = -1;
	int temp;
	string res;
	for (auto i : list) {
		if(!validconcat(i, m, true)) { // if the word is not a valid concatenation of 2 words.
			continue;
		}
		temp = i.length();
		if (maxlenstr < temp) {
			maxlenstr = temp;
			res = i;
		}
	}

	return res;
}

int main() {
	vector<string> list = {"dog", "nana", "walk", "walker", "dogwalker", "dogwalkernana"};
	unordered_map<string, bool> m;
	for(auto i : list) {
		m[i] = true;
	}
	cout << longest_word(list, m);
	return 0;
}
