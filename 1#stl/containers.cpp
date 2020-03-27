#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;

// vectors
void vectors() {
  vector<int> v;

  for(int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  // forward iterator
  for(vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
    printf("%d ", *i);
  }
  printf("\n");

  // reverse iterator
  for(vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i) {
    printf("%d ", *i);
  }
  printf("\n");

  // constant reverse iterator
  // for(vector<int>const_reverse_iterator i = v.crbegin(); i != v.crend(); ++i) {
    // printf("%d ", *i);
  // }

  if(!v.empty()) {
    printf("Vector is not empty\n");
  }
  printf("Size: %d\n", v.size());
  printf("Capacity: %d\n", v.capacity());

  printf("Front Data: %d\n", v.front());
  printf("Back Data: %d\n", v.back());
  printf("Data At: %d\n", v.at(1)); 
  printf("Reference pointer to the vector: %d\n", *v.data());

  // fill the place 5 times with 10
  v.assign(5, 10);

  // pop from the back
  v.pop_back();

  // insert -99 in the beginning
  v.insert(v.begin(), -99);

  // erase 2nd element
  v.erase(v.begin() + 2);
  sort(v.begin(), v.end(), greater<int>());

  for(vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
    printf("%d ", *i);
  }

  // clear vector
  v.clear();
}


// deque
void deques() {
  printf("\n");
  deque<string> d;
  d.push_back("Sharma");
  d.push_front("Angad");

  deque<string>::iterator itr;
  for(itr = d.begin(); itr != d.end(); ++itr) {
    cout << *itr << " ";
  }
  d.pop_front();
  d.pop_back();
}

// maps
void maps() {
  cout << endl;
  map<int, string> m;
  m.insert(pair<int, string>(0, "Angad"));
  m.insert(pair<int, string>(1, "Sharma"));
  map<int, string>::iterator itr;
  for(itr = m.begin(); itr != m.end(); ++itr) {
    cout << "KEY: " << itr->first << endl;
    cout << "VALUE: " << itr->second << endl;
  }

  // multimap<int, string> mm;
}

void containers() {
  vectors();
  deques();
  maps();
}
