// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1
//
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



vector<int> merge(Node *root1,Node *root2);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* The structure of Node is

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// Return a integer of integers having all the nodes in both the BSTs in a sorted order.

void traverse(Node *root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    traverse(root -> left, arr);
    arr.push_back(root -> data);
    traverse(root -> right, arr);
}
vector<int> merge(Node *root1, Node *root2)
{
   //Your code here
   vector<int> a1, a2, res;
   traverse(root1, a1);
   traverse(root2, a2);
   int n = a1.size(), m = a2.size();
   int i1=0, i2=0;
   while (i1 < n && i2 < m) {
       if (a1[i1] <= a2[i2]) {
           res.push_back(a1[i1++]);
       } else {
           res.push_back(a2[i2++]);
       }
   }
   if (i2 == m) { // s1 > s2
       for (int i = i1; i < n; ++i) {
           res.push_back(a1[i]); 
       }
   } else { // a2 > a1
       for (int i = i2; i < m; ++i) {
           res.push_back(a2[i]); 
       }
   }
   return res;
}
