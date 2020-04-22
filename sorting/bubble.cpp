#include <iostream>
using namespace std;

// O(n^2)
void bubble(int arr[], int n) {
  int i, j, temp;

  for(i = 0; i < n-1; ++i) {
    for(j = 0; j < n-i-1; ++j) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j]; 
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
  printf("DONE\n");
}
