// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
void removeTheLoop(Node *head)
{
     //Your code here
     unordered_set<Node*> s;
     
     while(head -> next) {
         if (s.find(head -> next) != s.end()) {
             head -> next = nullptr;
             continue;
         }
         s.insert(head);
         head = head -> next;
     }
}
