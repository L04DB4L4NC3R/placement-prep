// https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1
//
// TOUGH
bool findTriplets(int arr[], int n)
{ 
    //Your code here
    sort(arr, arr + n);
    int cnt = 0;
    for(int i = 0; i < n-2; ++i) {
        int j = i+1;
        int k = n-1;
        while(j<k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == 0) {
                cnt++;
                break;
            } else if (sum > 0) {
                k--;
            } else {
                j++;
            }
        }
    }
    return cnt;
}
