#include <iostream>
#include <algorithm>
using namespace std;

void array_algo() {
  int arr[6] = {2, 4, 6, 8, 10, 12};

  // using all_of to avoid using loops
  // all_of checks a property in every single array element
  // if the property exists in all, it returns
  // if all elements exist with x%2 = 0
  all_of(arr, arr + 6, [](int x) {
      return x%2 == 0;
  })? cout << "All elements are even\n" : cout << "All elements are odd\n";

  // any_of can be used to check the property in any 1 element
  // of the array
  // if any element exists with x = 4
  any_of(arr, arr + 6, [](int x) {
      return x == 4;
  })? cout << "Element found in the array" : cout << "Element not found in the array";

  // none_pf
  // if no element exists with x < 0 then return true
  none_of(arr, arr + 6, [](int x) {
      return x < 0;
  })? cout << "\nNo negative element" : cout << "\nNegative element exists";
}
