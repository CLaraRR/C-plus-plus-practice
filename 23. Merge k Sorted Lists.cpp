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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *newList = new ListNode(0);
		ListNode *p1 = l1, *p2 = l2, *m = newList;
		while (p1 != NULL&&p2 != NULL){
			if (p1->val <= p2->val){
				ListNode *newnode = new ListNode(p1->val);
				m->next = newnode;
				m = m->next;
				p1 = p1->next;
			}
			else if (p1->val > p2->val){
				ListNode *newnode = new ListNode(p2->val);
				m->next = newnode;
				m = m->next;
				p2 = p2->next;
			}
		}
		if (p1 == NULL&&p2 != NULL)
			m->next = p2;
		else if (p2 == NULL&&p1 != NULL)
			m->next = p1;
		return newList->next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int size = lists.size();
		if (size == 0)
			return NULL;
		else if (size == 1)
			return lists[0];
		else if (size == 2)
			return mergeTwoLists(lists[0], lists[1]);
		else{
			int mid = size / 2;
			vector<ListNode*> lists1, lists2;
			int i = 0;
			while (i < mid)
				lists1.push_back(lists[i++]);
			while (i<size)
				lists2.push_back(lists[i++]);
			ListNode *l1 = mergeKLists(lists1);
			ListNode *l2 = mergeKLists(lists2);
			return mergeTwoLists(l1, l2);

		}
	}
};