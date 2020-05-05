// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
//
// hashtable has O(1) searching therefore total complexity = O(n)
int detectloop(Node *head) {

    // your code here
    unordered_set<Node*> s;
    int count = 0;
    Node* temp = head;
    
    while(temp) {
        if (s.find(temp) != s.end()) {
            return true;
        }
        s.insert(temp);
        temp = temp -> next;
    }
    return false;
}
