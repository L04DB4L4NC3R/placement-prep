// https://practice.geeksforgeeks.org/problems/remove-half-nodes/1
Node *RemoveHalfNodes(Node *root)
{
   //add code here.
   if(!root)
     return nullptr;
   root -> left = RemoveHalfNodes(root -> left);
   root -> right = RemoveHalfNodes(root -> right);
   
   if (!root -> left && root -> right) {
       return root -> right;
   }
   if (root -> left && !root -> right) {
       return root -> left;
   }
   return root;
}
