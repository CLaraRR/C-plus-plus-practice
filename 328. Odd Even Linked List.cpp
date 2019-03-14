#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode *p = head->next,*q=head;
		while (p->next){
			q->next = p->next;
			ListNode *m = p->next;
			m->next = p;
			p->next = p->next->next;
			if (p->next)
				p = p->next;
			else
				break;
			q = q->next;

		}
		return head;
	}
};