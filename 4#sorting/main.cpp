#include <iostream>
#include "./4#sorting/sequential.cpp"
#include "./4#sorting/bubble.cpp"
#include "./4#sorting/selection.cpp"
#include "./4#sorting/insersion.cpp"
#include "./4#sorting/quick.cpp"
#include "./4#sorting/merge.cpp"
#include "./4#sorting/heap.cpp"
#include "./4#sorting/radix.cpp"
#include <vector>
using namespace std;

int main() {
  vector<int> d = {6,3,1,8,9,23,123,53,6,1,32,43,1};
  printf("\x1B[31mSEQUENTIAL\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  sequential(d.begin(), d.end());
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mBUBBLE\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  bubble(d.begin(), d.end());
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mSELECTION\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  selection(d.begin(), d.end());
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mINSERSION\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  insersion(d.begin(), d.end());
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mQUICK\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  quick(d.begin(), d.end());
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mMERGE\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  merge(d.begin(), d.end());
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mHEAP\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  heap(d.begin(), d.end());
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");

  printf("\x1B[31mRADIX\033[0m\t\t\n");
  printf("\x1B[31m----------------------\033[0m\t\t\n");
  radix_sort(d.begin(), d.end());
  printf("\n\x1B[31m----------------------\033[0m\t\t\n");


  return 0;
}
