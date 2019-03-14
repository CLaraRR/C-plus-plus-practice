#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//still have problem
	void reorderList(ListNode* head) {
		if (!head || !head->next)
			return;
		ListNode *L = new ListNode(0);
		L->next = head;
		ListNode *q = head, *p = head, *pre = L;
		while (1){
			while (p->next != NULL){
				p = p->next;
				pre = pre->next;
			}
			pre->next = p->next;
			p->next = q->next;
			q->next = p;
			q = p->next;
			if (q == NULL || q->next == NULL || q->next->next == NULL)
				break;
			p = pre;
			pre = q;
			while (pre->next != p)
				pre = pre->next;
		}
	}


	//¿ìÂýÖ¸Õë£¬³¬Ê±£¿£¿£¿
	ListNode *reverse(ListNode *head){
		ListNode *p1 = NULL;
		ListNode *p2 = head;
		ListNode *p3 = p2;

		while (p2){
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		return p1;
	}
	void reorderList1(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return;
		ListNode *slow = head, *fast = head,*p=head;
		while (fast->next != NULL&&fast->next->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *re=slow->next;
		slow->next == NULL;
		re = reverse(re);

		ListNode *cur = head;
		while (cur && re){
			ListNode *curSecond = re;
			re = re->next;
			ListNode *nextCur = cur->next;
			curSecond->next = cur->next;
			cur->next = curSecond;
			cur = nextCur;
		}
		
	}
};