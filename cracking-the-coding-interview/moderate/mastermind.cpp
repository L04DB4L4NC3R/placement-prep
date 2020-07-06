/*
 
17.5 The Game of Master Mind is played as follows:
The computer has four slots, and each slot will contain a ball that is red (R), yellow
(Y), green (G) or blue (B). For example, the computer might have RGGB {Slot #1 is
red, Slots #2 and #3 are green, Slot #4 is blue).
You, the user, are trying to guess the solution. You might, for example, guess
YRGB.
When you guess the correct color for the correct slot, you get a "hit." If you guess
a color that exists but is in the wrong slot, you get a "pseudo-hit." Note that a slot
that is a hit can never count as a pseudo-hit.
For example, if the actual solution is RGBY and you guess GGRR, you have one
hit and one pseudo-hit.
Write a method that, given a guess and a solution, returns the number of hits
and pseudo-hits.

*/

#include <iostream>
#include <unordered_map>
#define N 4
using namespace std;

void makemap(unordered_map<char, bool> &m, string s1) {
	for(int i = 0; i < N; ++i) {
		m[s1[i]] = true;
	}
}

int numhits(unordered_map<char, bool> &m, string s1, string s2) {
	int hits = 0;

	// count number of hits
	// and turn them false
	for (int i = 0; i < N; ++i) {
		if (s1[i] == s2[i]) {
			hits++;
			m[s1[i]] = false; // not to be counted in pseudohits
		}
	}
	return hits;
}

// count all leftover chars in the map (marked as true)
// by using the chars in s2. 
// When found, turn it to false to avoid duplication
int numphits(unordered_map<char, bool> &m, string s2) {
	int phits = 0; 
	for (auto i : s2) {
		if (m[i] == true) {
			phits++;
			m[i] = false;
		}
	}
	return phits;
}

int main() {
	string s1, s2;
	unordered_map<char, bool> m;
	cin >> s1 >> s2;
	makemap(m, s1);
	cout << numhits(m, s1, s2) << endl << numphits(m, s2);
	return 0;
}

