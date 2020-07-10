/*

17.13 Consider a simple node-like data structure called BiNode, which has pointers to
two other nodes.
1 public class BiNode {
2
public BiNode nodel, node2j
3
public int data;
4
}
The data structure BiNode could be used to represent both a binary tree (where
nodel is the left node and node2 is the right node) or a doubly linked list (where
nodel is the previous node and node2 is the next node). Implement a method
to convert a binary search tree (implemented with BiNode) into a doubly linked
list. The values should be kept in order and the operation should be performed
in place (that is, on the original data structure).

*/

// NOTE: Had to see the solution
// [1] For each tree, convert the left and right subtree to a linked list
// [2] recurse
// [3] merge left and right

#include <iostream>
using namespace std;

class BiNode {
	public:
	 	BiNode *node1, *node2;
		int data;
};

// utility function to get the tail of the converted linked list
// to join it to the other one
BiNode *gettail(BiNode *root) {
	if (root == nullptr) return root;
	while (root -> node2 != nullptr) {
		root = root -> node2;
	}
	return root;
}

// utility function to concatenate 2 lists
// if p1 = 1 <-> 2 <-> 3
// and p2 = 4 <-> 5
// then ans = 1 <-> 2 <-> 3 <-> <4 <-> 5
void concat(BiNode *p1, BiNode *p2) {
	p1 -> node2 = p2;
	p2 -> node1 = p1;
}

// convert a subtree to a linkedlist
BiNode *convert(BiNode *root) {
	if (root == nullptr) return root;
	
	// this will recurse till the vcry left and keep on merging 
	// left and right sides and assigning the left pointer to part 1
	// and right to part2
	BiNode *part1 = convert(root -> node1);
	BiNode *part2 = convert(root -> node2);

	// for merging left and right
	if (part1 != nullptr) {
		concat(gettail(part1), root);
	}

	if (part2 != nullptr) {
		concat(root, part2);
	}

	return part1 == nullptr ? root : part1;
}
