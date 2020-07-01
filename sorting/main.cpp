#include <iostream>
#include "sequential.cpp"
#include "bubble.cpp"
#include "selection.cpp"
#include "insersion.cpp"
#include "quick.cpp"
#include "merge.cpp"
#include "heap.cpp"
#include "radix.cpp"
#include <vector>
using namespace std;

void showarray(int arr[], int n) {
  for(int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[10] = {1, 5, 2, 9, 12, 45, 67, 1, -2, 0};
  printf("\x1B[31mSEQUENTIAL\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  sequential(arr, 10);
  showarray(arr, 10);
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mBUBBLE\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  bubble(arr, 10);
  showarray(arr, 10);
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mSELECTION\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  selection(arr, 10);
  showarray(arr, 10);
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mINSERSION\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  insersion(arr, 10);
  showarray(arr, 10);
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mQUICK\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  quick(arr, 10);
  showarray(arr, 10);
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mMERGE\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  mergesort(arr, 10);
  showarray(arr, 10);
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mHEAP\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  heap(arr, 10);
  showarray(arr, 10);
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mRADIX\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  radix_sort(arr, 10);
  showarray(arr, 10);
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");


  return 0;
}
