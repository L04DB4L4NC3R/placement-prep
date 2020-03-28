#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

void lists() {

  // dxoubly linked_list
  list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_front(3);
  l.push_front(4);

  list<int>::iterator itr;
  for(itr = l.begin(); itr != l.end(); ++itr) {
    cout << *itr << endl;
  }

  // singly linked_list
  forward_list<int> sl;
  sl.push_front(1);
  sl.push_front(2);
  forward_list<int>::iterator it;
  for(it = sl.begin(); it != sl.end(); ++it) {
    cout << *itr << endl;
  }

}
