#include <iostream>
#include <stack>
using namespace std;

// Note: iterator doesnt work in stack
void showstack(stack<int> s) {
  while(!s.empty()) {
    cout << s.top() << '\t';
    s.pop();
  }
}

void stacks() {
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  showstack(s);
}
