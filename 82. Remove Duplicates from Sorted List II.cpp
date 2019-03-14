#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *p = head->next, *q = head,*m=L;
		int flag = 0;
		while (p != NULL){
			while (p!=NULL&&q->val == p->val){
				flag = 1;
				p = p->next;
			}
			if (flag)
				m->next = p;
			if (p == NULL)
				break;
			q = p;
			while (m->next != p)
				m = m->next;
			p = p->next;
			flag = 0;
		}
		return L->next;

	}
};