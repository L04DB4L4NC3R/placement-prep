// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
int findLongestConseqSubseq(int arr[], int n)
{
  //Your code here
  sort(arr, arr + n);
  
  int c = 0, d;
  int minc = INT_MIN;
  for(int i = 0; i < n-1; ++i) {
      d = arr[i+1] - arr[i];
      if (d == 1) {
          c++;
          if (minc < c) {
              minc = c;
          }
      } else if (d == 0) {
          continue;
      } else {
          c = 0;
      }
  }
  return (minc == INT_MIN)? 1:minc+1;
}
