#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *p = head->next, *tail = head,*q=L;
		int times = n - m;
		while (--m){
			p = p->next;
			tail = tail->next;
			q = q->next;
		}
		while (times--){
			tail->next = p->next;
			p->next = q->next;
			q->next = p;
			p = tail->next;

		}
		return L->next;
	}
};