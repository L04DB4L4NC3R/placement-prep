// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
#include <vector>
int getMiddle(Node *head)
{
   // Your code here
   vector<int> v;
   
   while(head) {
       v.push_back(head -> data);
       head = head -> next;
   }
   if (v.size() % 2 == 0) {
       return v[v.size()/2];
   }
   return v[(v.size() + 1)/2 -1];
}
