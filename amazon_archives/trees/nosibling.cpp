// https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1
void traverse(Node* node, bool *flag, set<int> &s)
{
		// Your code here
		if (node == nullptr) 
				return;

		if (node -> left && !node -> right) {
				*flag = true;
				s.insert(node -> left -> data);
		} else if (node -> right && !node -> left) {
				s.insert(node -> right -> data);
				*flag = true;
		}
		traverse(node -> left, flag, s);
		traverse(node -> right, flag, s);
}

void printSibling(Node *node) {
		bool flag = false;
		set<int> s;
		traverse(node, &flag, s);
		if (!flag) 
				cout << -1;
		else {
				for(auto i : s) {
						cout << i << " ";
				}
		}
}
