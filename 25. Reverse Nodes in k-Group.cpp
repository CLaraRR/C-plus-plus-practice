#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *p = L,*q=head,*m=head,*c=head;
		for (int i = 1; i < k; i++){
			c = c->next;
			if (c == NULL)
				return L->next;
		}	
		c = c->next;
		while (1){
			//m = q;
			for (int i = 1; i < k;i++){
				m = m->next;
				m->next = q;                           
				p->next = m;
				ListNode *tmp = m;
				m = q;
				q = tmp;

			}
			if (c == NULL)
				return L->next;
			m = c;
			q = c;
			for (int i = 1; i < k; i++){
				c = c->next;
				if (c == NULL)
					return L->next;
			}
			c = c->next;
			for (int i = 0; i < k; i++){
				p = p->next;
			}
			
		}
		return L->next;
		

	}
};