// 17.9 Design a method to find the frequency of occurrences of any given word in a book.

#include <iostream>
#include <unordered_map>
using namespace std;

void makemap(unordered_map<string, int> &m, string str[], int n) {
	for (int i = 0; i < n; ++i) {
		if (m.find(str[i]) != m.end()) {
			m[str[i]]++;
			continue;
		}
		m[str[i]] = 1;
	}
}

int main() {
	string book[1000];
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		cin >> book[i];
	}
	unordered_map <string, int> m;
	makemap(m, book, n);

	string word;
	cin >> word;

	cout << "Frequency = " << m[word];
}
