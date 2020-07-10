/*
 
17.14 Oh, no! You have just completed a lengthy document when you have an unfor-
tunate Find/Replace mishap. You have accidentally removed all spaces, punc-
tuation, and capitalization in the document. A sentence like "I reset the
computer. It still didn't boot!"would become"iresetthecomput-
eritstilldidntboot". You figure that you can add back in the punctation and
capitalization later, once you get the individual words properly separated. Most
of the words will be in a dictionary, but some strings, like proper names, will not.
Given a dictionary (a list of words), design an algorithm to find the optimal way
of "unconcatenating"a sequence of words. In this case, "optimal" is defined to be
the parsing which minimizes the number of unrecognized sequences of char-
acters.
For example, the string "jesslookedjustliketimherbrother" would be
optimally parsed as "JESS looked just like TIM her brother". This
parsing has seven unrecognized characters, which we have capitalized for clarity.
_
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#define MAX_WORD 45 // pnewomonoultramicroscopicsilicovolcanoconiosis
using namespace std;

//
// approach:
// start from the end
// keep gouing towards the left
// if word exists put it in buffer
// if bigger word exists before reaching the front, update the buffer 
// When final word is ready start from the end - final word length
void makehashmap(unordered_map<string, bool> &m, string dict[], int n) {
	for (int i = 0; i < n; ++i) {
		m[dict[i]] = true;
	}
}

string generatedollar(int n) {
	string l = "";
	for (int i = 0 ; i < n ; ++i) {
		l += '$';
	}
	return l;
}

// we have a result with a number of words in order
// run order wise and replace the found word with the word + spaces and beg and end
// capitalize the remaining words
string capitalize_notfounds(unordered_map<string, pair<int, int>> valid_word_indices, string input) {
	for (auto i : valid_word_indices) {
		if (i.second.first == -1) {
			i.second.first = 0;
		}
		input.replace(i.second.first, i.second.second, generatedollar(i.second.second - i.second.first));
	}

	// whatever isnt a dollar capitalize
	for (auto i : input) {
		if (i != '$') {
			i = toupper(i);
		}
	}

	// TODO: using the hashmap, stich the input back again
	return input;
}

string unconcatenate(string input, unordered_map<string, bool> &m) {

	string t = "";
	string buf = "";
	string result = "";
	string rev_t;
	int i;
	int end = input.length() - 1;
	unordered_map<string, pair<int, int>> valid_word_indices;

	while (end >= 0) {
		for (i = end; i >= 0; --i) {
			t += input[i]; // add in temporary variable
			rev_t = t;
			reverse(rev_t.begin(), rev_t.end());
			if (m.find(rev_t) != m.end()) { // find candidate words
				buf = t;
			}
		}

		// TODO: In the case oof buflen 0 proper noun is there
		// gotta remove it
		// approach:
		// maintain a list of valid words in input
		// after list is complete capitalize anything in input that is not in the list
		// approach:
		// replace these words by $
		// capitalize everything that is not a $
		// re-insert the words at the specific indices
		// try maintaining a hashmap of words and their specific indices
		if (buf.length() == 0) {
			end -= 1;
			continue;
		}
		if (buf.length() >= end) {
			valid_word_indices[buf] = pair<int, int>(0, end);
		}
		valid_word_indices[buf] = pair<int, int>(end - buf.length(), end);
		result += buf + " "; // select the best candidate
		end -= buf.length(); // reduce the end variable to leave buffer
		buf = "", t = "", rev_t = ""; // reset values
	}
	reverse(result.begin(), result.end());
	
	result = capitalize_notfounds(valid_word_indices, input);
	return result;
}

int main() {
	string dict[] = {"looked", "just", "like", "her", "brother", "a", "look", "he", "bro"};

	// string input = "jesslookedjustliketimherbrother";
	string input = "timlookedjusther";

	unordered_map<string, bool> m;
	int n = sizeof(dict)/sizeof(string);
	makehashmap(m, dict, n);
	cout << unconcatenate(input, m);

	return 0;
}
