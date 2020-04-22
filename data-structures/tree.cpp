#include <iostream>
using namespace std;

struct node {
  int data;
  node* left;
  node* right;
};

class binary_tree {
  public:
    node* root;
    bool isempty();
    void insert(int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void display();
    bool search(int, node*);
};


bool binary_tree::isempty() {
  return root == NULL;
}

void binary_tree::insert(int data) {
  node* newnode = new node;
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  node* parent = NULL;

  if(isempty()) {
    root = newnode;
    return;
  }

  node* temp = root;
  while(temp != NULL) {
    parent = temp;
    if(data < temp->data) 
      temp = temp->left;
    else 
      temp = temp->right;
  }

  if(data < parent->data) 
    parent->left = newnode;
  else
    parent->right = newnode;
}

void binary_tree::inorder(node *n) {
  if(n != NULL) {
    inorder(n->left);
    printf("%d ", n->data);
    inorder(n->right);
  }
}

void binary_tree::preorder(node *n) {
  if (n != NULL) {
    printf("%d ", n->data);
    preorder(n->left);
    preorder(n->right);
  }
}

void binary_tree::postorder(node *n) {
  if (n != NULL) {
    preorder(n->left);
    preorder(n->right);
    printf("%d ", n->data);
  }
}

void binary_tree::display() {
  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
  printf("\n");
}

bool binary_tree::search(int data, node* n) {
  if (n == NULL) 
    return false;
  if (data == n->data) 
    return true;
  if (data > n->data)
    return search(data, n->right);
  else 
    return search(data, n->left);
}

void trees() {
  binary_tree *b;
  b->root = NULL;
  b->insert(1);
  b->insert(2);
  b->insert(3);
  b->insert(4);
  b->insert(5);
  b->insert(6);

  b->display();
  printf("%d\n", b->search(4, b->root));
  printf("%d\n", b->search(1, b->root));
  printf("%d", b->search(7, b->root));
}
