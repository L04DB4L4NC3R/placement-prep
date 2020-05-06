/* https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1
 *
 * node is the counter for the arrays (iterator)
 * [1] create a new node in every call
 * [2] if L, then just return the created node
 * [3] else increment pointer
 * [3.1] build left subtree
 * [3.2] increment iterator
 * [3.3] build right subtree
 * [4] return n
 */
Node* build(int v , int pre[] , char pren[] , int &node){
		if(node>=v) return NULL;
		Node* n=new Node(pre[node]);
		if(pren[node]=='L'){
				n->left=NULL;
				n->right=NULL;
				return n;
		}
		n->data=pre[node];
		node++;
		n->left=build(v,pre,pren,node);
		node++;
		n->right=build(v,pre,pren,node);
		return n;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
		// Code here
		int node=0;
		return build(n,pre,preLN,node);
}
