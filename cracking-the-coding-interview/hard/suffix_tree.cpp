/*
 
18.8
Given a string s and an array of smaller strings T, design a method to search s
for each small string in T.

 */

// NOTE: had to see the solution
// suffix tree can be used here. Create a suffix tree for the long word and then traverse it for each char in the small word

// suffix tree is a Trie made of all of the suffixes of a current word. For example in the case of "banana":
// banana
// anana
// nana
// ana
// na
// a

// To search for a string of size 'm' in text 'n' (n > m), the time complexity is only O(m) after making the tree

#include <iostream>
#include <vector>
using namespace std;

struct trie {
	trie *arr[26];
	bool endofword;
	int location;
	
	trie() {
		endofword = false;
	}
};

void insert_in_trie(string s, trie *root, int initial_index) {
	trie *temp = root;
	int index;	
	for(auto i : s) {
		index = i - '0';
		if (temp -> arr[index] == nullptr) {
			temp -> arr[index] = new trie();
		}
		temp -> location = initial_index++;
		temp = temp -> arr[index];
	}
	temp -> endofword = true;
}

bool search(trie *root, string s) {
	int index;
	int count = 0;
	trie *temp = root;
	for (auto i : s) {
		index = i - '0';
		if (temp -> arr[index] == nullptr) {
			return false;
		}
		temp = temp -> arr[index];
		count++;
	}
	printf("Found %s at index %d\n", s, temp -> location - count);
	return true;
}

void makesuffixtree(string s, trie *root) {
	for (int i = 0; i < s.length(); ++i) {
		insert_in_trie(s.substr(i), root, i);
	}
}

int main() {
	string str = "loadbalancerlo";
	vector<string> list = {"lo", "ad", "er", "balance", "load", "bala", "rece"};

	trie *root = new trie();
	makesuffixtree(str, root);
	for (auto i : list) {
		cout << search(root, i);
	}
	return 0;
}
