// ihttps://practice.geeksforgeeks.org/problems/overlapping-intervals/0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t, n;
	cin >> t;
	int l, r;
	
	while(t--) {
	    cin >> n;
	    vector<pair<int, int>> arr;
    	pair<int, int> p[n];
	
	    for (int i = 0; i < n; ++i) {
	        cin >> p[i].first >> p[i].second;
	    }
	    sort(p, p + n);

        arr.push_back(p[0]);
        
        for (int i = 1; i < n; ++i) {
            if (p[i].first <= arr.back().second) {
                arr.back().second = max(arr.back().second, p[i].second);
            } else {
                arr.push_back(p[i]);
            }
        }
        
        for (auto i : arr) {
            cout << i.first << " " << i.second << " ";
        }
	    cout << endl;
	}
	return 0;
}
