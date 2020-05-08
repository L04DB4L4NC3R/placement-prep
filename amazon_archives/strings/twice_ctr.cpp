// https://practice.geeksforgeeks.org/problems/twice-counter/0
int main() {
	//code
	int t, n;
	string ss;
	cin >> t;
	int count; 
	
	while(t--) {
	  cin >> n;
	  unordered_map<string, int> s;
	  count = 0;
	  for(int i = 0; i < n; ++i) {
	      cin >> ss;
	      if(s.find(ss) != s.end()) {
	          s[ss]++;
	      } else {
	          s[ss] = 0;
	      }
	  }
	  for(auto i : s) {
	      if (i.second == 1)
	        count++;
	  }
	  cout << count << endl;
	}
	return 0;
}
