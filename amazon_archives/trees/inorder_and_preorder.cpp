// https://practice.geeksforgeeks.org/problems/inorder-traversal/1
// https://practice.geeksforgeeks.org/problems/preorder-traversal/1
void inorder(Node* root)
{
  // Your code here
  if(root == NULL) 
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void preorder(Node* root)
{
  // Your code here
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
