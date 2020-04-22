#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heaps() {
  vector<int> v = {1, 5, 6, 2, 4, 8};
  make_heap(v.begin(), v.end());
  printf("Max element in heap = %d\n", v.front());

  make_heap(v.begin(),v.end(), greater<int>());
  printf("Min element in heap = %d\n", v.front());

  // push element
  v.push_back(9);
  // max heapify
  push_heap(v.begin(), v.end());

  printf("Is the vector a heap?: %d", is_heap(v.begin(), v.end()));
}
