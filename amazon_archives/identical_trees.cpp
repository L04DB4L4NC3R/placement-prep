// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
bool flag;
void inorder(Node *ref1, Node *ref2) {
    if(!flag) {
        return;
    }
    // if both are null then identical
    if (!ref1 && !ref2) {
        flag = true;
        return;
    }
    // if either is null but not both, unidentical
    if((ref1 && !ref2) || (ref2 && !ref1)) {
        flag = false;
        return;
    }
    // if data is different, unidentical
    if(ref1->data != ref2->data) {
        flag = false;
        return;
    }
    //recurse
    inorder(ref1->left, ref2->left);
    inorder(ref1->right, ref2->right);
}

bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    flag = true;
    inorder(r1, r2);
    return flag;
}
