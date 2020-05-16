// https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
void traverse(Node *node, int sum, int S, bool *flag) {
		// Your code here
		if(node == nullptr) {
				return;
		}
		sum += node -> data;

		traverse(node -> left, sum, S, flag);
		if (sum == S && node -> left == nullptr && node -> right == nullptr) {
				*flag = true;
		}
		traverse(node -> right, sum, S, flag);
}

bool hasPathSum(Node *node, int sum) { 
		bool flag = false;
		traverse(node, 0, sum, &flag);
		return flag;
}
