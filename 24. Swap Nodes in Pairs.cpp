#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *q = head, *m = head->next,*p=L;
		while (m != NULL){
			q->next = m->next;
			m->next = q;
			p->next = m;
			q = q->next;
			if (q == NULL)
				break;
			q = q->next;
			if (q == NULL)
				break;
			m = m->next->next;
			p = p->next->next;
			ListNode *tmp = m;
			m = q;
			q = tmp;
		}
		return L->next;

	}
};

