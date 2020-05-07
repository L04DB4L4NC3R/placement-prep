// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
void deleteNode(Node *node)
{
   // Your code here
   if (node->next != NULL)
    *node = *node->next;
   else 
     node = NULL;
}
