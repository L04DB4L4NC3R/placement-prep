// https://practice.geeksforgeeks.org/problems/absolute-list-sorting/1
void sortList(Node** head)
{
    // Your Code Here
    multiset<int> s;
    Node *temp = *head;
    while(temp) {
        s.insert(temp -> data);
        temp = temp -> next;
    }
    temp = *head;
    for (auto i : s) {
        temp -> data = i;
        temp = temp -> next;
    }
}
