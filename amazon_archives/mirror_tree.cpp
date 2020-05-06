// https://practice.geeksforgeeks.org/problems/mirror-tree/1
Node *temp;
void mirror(Node* node) 
{
     // Your Code Here
     if (node == nullptr)
       return;
     temp = node -> left;
     node -> left = node -> right;
     node -> right = temp;
     mirror(node -> left);
     mirror(node -> right);
}
