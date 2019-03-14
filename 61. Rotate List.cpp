#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head==NULL||k == 0)
			return head;
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *p = head, *q = L;
		int len = 1;
		//计算链表长度
		while (p->next != NULL){
			len++;
			p = p->next;
			q = q->next;
		}
		k = k%len;
		while (k--){
			p->next = L->next;
			L->next = p;
			q->next = NULL;
			while (p->next != q){
				p = p->next;
			}
			ListNode *tmp = p;
			p = q;
			q = tmp;

		}
		return L->next;

	}
};