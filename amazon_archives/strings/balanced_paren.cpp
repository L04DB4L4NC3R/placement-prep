// https://practice.geeksforgeeks.org/problems/parenthesis-checker/0
#include <iostream>
using namespace std;

int main() {
		//code
		int t;
		string str;
		cin >> t;	

		int brac, paren, wiggly;
		while(t--) {
				cin >> str;
				brac = 0; paren = 0; wiggly = 0;
				for(int i = 0; i < str.length(); ++i) {
						switch(str[i]) {
								case '[':
										brac++;
										break;
								case ']':
										brac--;
										break;
								case '(': 
										paren++;
										break;
								case ')': 
										paren--;
										break;
								case '{':
										wiggly++;
										break;
								case '}':
										wiggly--;
										break;
						}
				}
				if (brac==0 && paren==0 && wiggly==0) {
						cout << "balanced" << endl;
				} else {
						cout << "not balanced" << endl;
				}
		}
		return 0;
}
