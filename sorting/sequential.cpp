#include <iostream>
using namespace std;

// O(n^2)
void sequential(int arr[], int n) {
  int i, j, temp;

  for(i = 0; i < n; ++i) {
    for(j = 0; j < i; ++j) {
      if (arr[j] > arr[i]) {
        temp = arr[i]; 
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  printf("DONE\n");
}
