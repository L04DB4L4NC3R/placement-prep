// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
#include <vector>
int getNthFromLast(Node *head, int n)
{
       // Your code here
       vector<int> v;
       while(head) {
           v.push_back(head -> data);
           head = head -> next;
       }
       if (v.size() < n) 
            return -1;
       return v[v.size() - n];
}
