#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void showdq(deque<int> d) {
    deque<int>::iterator itr;
    for(itr = d.begin(); itr != d.end(); ++itr) {
        printf("%d ", *itr);
    }
    printf("\n");
}


int main() {
	//code
	int t, i, n, offset, j, elem;
	deque<int> d;
	scanf("%d", &t);
	
	for (i = 0; i < t; ++i) {
	    scanf("%d", &n);
	    scanf("%d", &offset);
	    for(j = 0; j < n; j++) {
	        scanf("%d", &elem);
	        d.push_back(elem);
	    }
	    rotate(d.begin(), d.begin() + offset, d.end());
	    showdq(d);
	    d.clear();
	}
	return 0;
}
