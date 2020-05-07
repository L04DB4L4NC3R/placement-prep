// https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1
struct node* makeUnion(struct node* head1, struct node* head2)
{
		// code here
		// set is sorted and unique
		set<int> s;

		node *t1 = head1;
		node * t2 = head2;

		while(t1) {
				s.insert(t1 -> data);
				t1 = t1 -> next;
		}
		while(t2) {
				s.insert(t2 -> data);
				t2 = t2 -> next;
		}

		node *h = nullptr, *t;
		for(auto i : s) {
				if (h == nullptr) {
						h = new node(i);
						t = h;
				} else {
						t -> next = new node(i);
						t = t -> next;
				}
		}
		return h;
}
