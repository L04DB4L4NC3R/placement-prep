#include <iostream>
using namespace std;

void selection(int arr[], int n) {
  int i, j, temp, minn;

  for(i = 0; i < n; ++i) {
    minn = i;
    for(j = i+1; j < n; ++j) {
      if(arr[j] < arr[minn]) {
        minn = j;
      }
    }
    temp = arr[minn];
    arr[minn] = arr[i];
    arr[i] = temp;
  }
  printf("DONE\n");
}
