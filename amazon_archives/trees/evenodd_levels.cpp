// https://practice.geeksforgeeks.org/problems/odd-even-level-difference/1
int ceven, codd;
void inorder(Node *ref, int depth) {
    if(!ref)
      return;
    inorder(ref -> left, depth + 1);
    if (depth % 2 == 0) {
        ceven += ref -> data;
    } else {
        codd += ref -> data;
    }
    inorder(ref -> right, depth + 1);
}
int getLevelDiff(Node *root)
{
    codd = 0;
    ceven = 0;
    inorder(root, 0);
    return ceven - codd;
   //Your code here
}
