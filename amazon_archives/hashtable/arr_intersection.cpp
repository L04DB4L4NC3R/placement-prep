// https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1
int cnt;
int NumberofElementsInIntersection (int a[], int b[], int n, int m )
{
		// Your code goes here
		int i;
		cnt = 0;
		unordered_map<int, bool> mm;

		for(i = 0; i < n; ++i) {
				mm[a[i]] = false;
		}
		for(i = 0; i < m; ++i) {
				if (mm.find(b[i]) != mm.end())
						if (!mm[b[i]]) {
								cnt++;
								mm[b[i]] = true;
						}
		}
		return cnt;
}
