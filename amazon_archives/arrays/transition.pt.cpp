// https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1
int m;
int binary_search(int arr[], int left, int right) {
    if (left > right)
      return -1;
    m = (left + right) / 2;
    if (arr[m] == 1 && arr[m - 1] == 0) {
        return m;
    } else if (arr[m-1] > 0) {
        return binary_search(arr, left, m-1);
    } 
    else {
        return binary_search(arr, m + 1, right);
    }
}
int transitionPoint(int arr[], int n) {
    // code here
    return binary_search(arr, 0, n - 1);
}
