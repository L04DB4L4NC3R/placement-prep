// https://practice.geeksforgeeks.org/problems/check-for-bst/1
vector<int> v;
void inorder(Node* ref) {
    if (ref == NULL) 
      return;
    inorder(ref -> left);
    v.push_back(ref -> data);
    inorder(ref -> right);
}

bool isBST(Node* root) {
    // Your code here
    v.clear();
    inorder(root);
    
    for(int i = 1; i < v.size(); ++i) {
        if (v[i-1] >= v[i])
          return false;
    }
    return true;
}

