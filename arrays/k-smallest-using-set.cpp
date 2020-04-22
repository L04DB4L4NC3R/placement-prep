/*
 * Note:
 * Sets are sorted in ascending order automatically
 * and every element is unique.
 *
 * if you want it to be descending order then use:
 * 
 * set<int, greater<int>> d;
 * 
 * */
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	//code
	set<int> d;
	int t, n, k, i, j, elem, count;
	
	scanf("%d", &t);
	for(i = 0; i < t; ++i) {
	    count = 0;
	    scanf("%d", &n);
	    for(j = 0; j < n; ++j) {
	        scanf("%d", &elem);
	        d.insert(elem);
	    }
	    scanf("%d", &k);
	    set<int>::iterator itr = d.begin();
	    for(itr; itr != d.end(); ++itr) {
	        if (++count > k-1) {
	            break;
	        }
	        //cout << *itr;
	    }
	    cout << *itr << endl;
	    d.clear();
	}
	return 0;
}
