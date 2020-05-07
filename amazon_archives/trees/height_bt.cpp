// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
int height(Node* node)
{
   // Your code here
   if (node == nullptr) {
       return 0;
   }
   
   return 1 + max(height(node -> left), height(node -> right));
}

