// https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
#include <iostream>
using namespace std;

struct node {
    node *next[27];
    bool word;
};

void loadTrie(string word, node* root) {
    int id;
    node *temp = root;
    for (int i = 0; i < word.length(); ++i) {
        id = word[i] - 97;
        
        if (temp->next[id]) {
            temp = temp->next[id];
        } else {
            temp -> next[id] = new node();
            temp = temp -> next[id];
        }
        
    }
    temp -> word = true;
}

int search(string word, node* root) {
    int id;
    node *temp = root;
    for (int i = 0; i < word.length(); ++i) {
        id = (int)word[i] - 97;
        if (temp->next[id]) {
            temp = temp->next[id];
        } else {
            break;
        }
    }
    if (temp -> word) 
        return 1;
    return 0;
}

int main() {
	//code
	int t, n;
	string word;
	node *root = new node();
	cin >> t;
	while(t--) {
	    cin >> n;
	    for(int i = 0; i < n; ++i) {
	        cin >> word;
	        loadTrie(word, root);
	    }
	    cin >> word;
	    cout << search(word, root) << endl;
	}
	return 0;
}
