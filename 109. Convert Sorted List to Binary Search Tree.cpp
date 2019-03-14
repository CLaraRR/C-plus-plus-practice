#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<int> arr;
	TreeNode *buildBST(vector<int>::iterator start, vector<int>::iterator end){
		if (start == end)
			return NULL;
		auto mid = start + (start - end) / 2;
		TreeNode *root = new TreeNode(*mid);
		root->left = buildBST(start, mid);
		root->right = buildBST(mid + 1, end);
		return root;

	}
	TreeNode* sortedListToBST(ListNode* head) {
		ListNode *p = head;
		while (p != NULL){
			arr.push_back(p->val);
			p = p->next;
		}
		return buildBST(arr.begin(), arr.end());
	}
};