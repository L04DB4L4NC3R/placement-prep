// https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
//
// Explanation:
// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
int maxLen(int arr[], int n) {
		// find max subsequence with sum = 0
		unordered_map<int, int>m;
		int sum = 0, maxlen = 0;
		for(int i = 0; i < n; ++i) {
				// if arr elem is 0, convert to -1
				arr[i] = (arr[i] == 0)? -1:1;

				// find intermediate sum
				sum += arr[i];

				// case where subarray len = 1
				// if single element is 0
				if (arr[i] == 0 && maxlen == 0)
						maxlen = 1;

				// if found sum 0 then record
				// arr length
				if (sum == 0)
						maxlen = i+1;

				// if prev recorded 0 sum
				// then maxlen should be max of
				// current and recorded
				// else if not found then
				// record k,v = sum,len
				if (m.find(sum) != m.end()) {
						maxlen = max(maxlen, i-m[sum]);
				} else {
						m[sum] = i;
				}
		}
		return maxlen;
}
