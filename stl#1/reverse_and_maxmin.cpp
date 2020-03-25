#include <iostream>
#include <algorithm>
using namespace std;

void reverse_and_maxmin() {
  int a[10] = {123, 123, 324, 434, 234, 234, 234, 324, 23, 45};
  reverse(a, a+10);
  show(a, 10);
  // int x = *max_element(a, a + 10, custom_comparator);
  int x = *max_element(a, a + 10);
  printf("Maximum element: %d\n", x);
  x = *min_element(a, a+10);
  printf("Minimum element: %d\n", x);
  int c = count(a, a + 10, 123);
  printf("Count: %d\n", c);
}
