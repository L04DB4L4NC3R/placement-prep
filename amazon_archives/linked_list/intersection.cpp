// https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1
struct node* findIntersection(struct node* head1, struct node* head2)
{
		// code here
		unordered_set<int> s;
		vector<int> v;
		node *t1 = head1;

		while(t1) {
				s.insert(t1 -> data);
				t1 = t1 -> next;
		}

		node *t2 = head2;
		node *head = nullptr, *t3;
		while(t2) {
				if(s.find(t2 -> data) != s.end()) {
						v.push_back(t2 -> data);
				}
				t2 = t2 -> next;
		}

		sort(v.begin(), v.end());
		for(auto i : v) {
				if(!head) {
						head = new node();
						head -> data = i;
						t3 = head;
				} else {
						t3 -> next = new node();
						t3 -> next -> data = i;
						t3 = t3 -> next;
				}
		}

		return head;

}
