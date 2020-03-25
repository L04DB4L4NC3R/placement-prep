#include <iostream>
#include <algorithm>
using namespace std;
void show(int*);
bool custom_comparator(int, int);
class custom_type {
  public:
    string name;
    int age;
};
bool custom_type_comparator(custom_type, custom_type);

void sorting_and_searching() {
  int a[10] = {78,12,324,546,42,123,546,7568,234,1};
  show(a);

  // sort in ascending order
  sort(a, a+10);
  show(a);

  // sort in descending order
  sort(a, a+10, greater<int>());
  show(a);
  
  // using a custom comparator
  sort(a, a+10, custom_comparator);
  show(a);

  // sorting in a custom type
  custom_type t[3] = {{"Angad", 20}, {"Dhruv", 27}, {"Radhika", 20}};
  sort(t, t+3, custom_type_comparator);
  printf("%d %d %d\n", t[0].age, t[1].age, t[2].age);
  printf("%d %d %d\n", t[0].age, t[1].age, t[2].age);

  // binary search
  sort(a, a+10);
  if (binary_search(a, a + 10, 1)) {
    printf("Found value");
  } else {
    printf("Not found value");
  }
}


void show(int *arr) {
  printf("Array is: ");
  for(int i = 0; arr[i] != '\0'; ++i) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

bool custom_comparator(int a, int b) {
  return (a << 4) < b;
}

bool custom_type_comparator(custom_type a, custom_type b) {
  return a.age > b.age;
}
