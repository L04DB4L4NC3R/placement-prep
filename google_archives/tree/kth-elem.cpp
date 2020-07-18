/*
 * https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
 */
#include <bits/stdc++.h>
using namespace std;

void traverse(Node *root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    traverse(root -> left, arr);
    arr.push_back(root -> data);
    traverse(root -> right, arr);
}

// Return the Kth smallest element in the given BST 
int KthSmallestElement(Node *root, int K)
{
    //add code here.
    vector<int> arr;
    traverse(root, arr);
    if (K > arr.size()) {
        return -1;
    }
    return arr[K-1];
}
