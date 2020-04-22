#include <iostream>
#include <unordered_map>
using namespace std;

// unordered_map is a hash table only
void hash_tables() {
  unordered_map<int, string> m;
  m.insert(pair<int, string>(0, "Angad"));
  m.insert(pair<int, string>(1, "Sharma"));
  m[2] = "Dhruv";
  m[3] = "Sharma";

  unordered_map<int, string>::iterator itr;
  for(itr = m.begin(); itr != m.end(); ++itr) {
    cout << itr->first << endl;
    cout << itr->second << endl;
  }

  if (m.find(2) == m.end()) {
    cout << "If key is not found then end is returned";
  } else {
    cout << "Found key, and subsequent value is " << m[2];
  }
}
