#include <iostream>
using namespace std;

struct node {
  int data; 
  node* left;
  node* right;
};

void insert(node** n, int data) {
  node* newnode = new node;
  node* parent = NULL;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  if (n == NULL) {
    printf("New!!");
    n = &newnode;
  }
  else {
    node* temp = *n;
    parent = temp;
    while(temp != NULL) {
      parent = temp;
      if(data >= temp->data) {
        temp = temp->right;
      } else if(data < temp->data) {
        temp = temp->left;
      }
    }

    if (data > parent->data) {
      parent->left = newnode;
    } else {
      parent->right = newnode;
    }
  }
}


void inorder_traversal(node *root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
    printf("\n");
  }
}

void preorder_traversal(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    printf("\n");
  }
}

void postorder_traversal(node *root) {
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
    printf("\n");
}

void trees() {
  node* root;
  insert(&root, 1);
  insert(&root, 2);
  insert(&root, 3);
  insert(&root, 4);
  insert(&root, 5);
  insert(&root, 6);
  inorder_traversal(root);
  preorder_traversal(root);
  postorder_traversal(root);
}
