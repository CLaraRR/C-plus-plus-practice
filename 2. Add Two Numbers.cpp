#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *l1iter = l1;
		ListNode *l2iter = l2;
		ListNode *result = new ListNode(0);
		ListNode *m = result;
		int jinwei = 0;
		while (1){
			int p;
			int q;
			if (l1iter == NULL)
			{
				p = l1iter->val;
				l1iter = l1iter->next;
			}
			else
				p = 0;
				
			if (l2iter != NULL)
			{
				q = l2iter->val;
				l2iter = l2iter->next;
			}
			else
				q = 0;
			
			int sum = p + q + jinwei;
			int benwei = sum % 10;
			ListNode *newnode = new ListNode(benwei);
			m->next = newnode;
			m = m->next;
			jinwei = sum / 10;
			if (l1iter == NULL&&l2iter == NULL)
				break;
		}
		if (l1iter == NULL&&l2iter == NULL){
			if (jinwei != 0){
				ListNode *newnode = NULL;
				newnode = new ListNode(jinwei);
				m->next = newnode;
			}

		}
		return result->next;

	}

};


int main(){


}