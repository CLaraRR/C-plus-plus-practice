#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1000;

struct node
{
	int data;
	node* lchild;
	node* rchild;
	node(int x) :data(x), lchild(NULL), rchild(NULL){}
};

//查找BST中数据域为x的结点
void searchBST(node* root, int x){
	if (root == NULL){
		cout << "search failed!" << endl;
		return;
	}

	if (x == root->data)
		cout << root->data;
	else if (x < root->data) 
		searchBST(root->lchild, x);
	else 
		searchBST(root->rchild, x);
}

//在BST中插入数据域为x的新节点     
void insertBST(node* &root, int x){
	if (root == NULL){
		root = new node(x);
		return;
	}

	if (x == root->data)
		cout << root->data;
	else if (x < root->data)
		insertBST(root->lchild, x);
	else
		insertBST(root->rchild, x);
}

//BST的建立
node* createBST(int data[], int n){
	node* root = NULL;
	for (int i = 0; i < n; i++){
		insertBST(root, data[i]);
	}
	return root;
}

//找到BST中最大权值结点
node* findMaxNodeBST(node* root){
	while (root->rchild)
		root = root->rchild;
	return root;
}

//找到BST中最小权值结点
node* findMinNodeBST(node* root){
	while (root->lchild)
		root = root->lchild;
	return root;
}

//删除权值为x的结点,容易使得高度不平衡
void deleteNodeBST(node* &root, int x){
	if (root == NULL) return;

	if (root->data > x)
		deleteNodeBST(root->lchild, x);
	else if (root->data < x)
		deleteNodeBST(root->rchild, x);
	else if(root->data == x){
		if (root->lchild == NULL&&root->rchild == NULL)
			root = NULL;
		else if (root->lchild!=NULL){
			node* pre = findMaxNodeBST(root->lchild);
			root->data = pre->data;
			deleteNodeBST(pre, pre->data);
		}
		else if(root->rchild!=NULL){
			node* next = findMinNodeBST(root->rchild);
			root->data = next->data;
			deleteNodeBST(next, next->data);
		}
	}
}

//先序遍历
void preOrder(node* root){
	if (root == NULL){
		return;
	}
		
	cout << root->data << " ";
	preOrder(root->lchild);
	preOrder(root->rchild);
}

//中序遍历
void inOrder(node* root){
	if (root == NULL){
		return;
	}
	inOrder(root->lchild);
	cout << root->data << " ";
	inOrder(root->rchild);
}

//后序遍历
void postOrder(node* root){
	if (root == NULL){
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	cout << root->data << " ";
}


int main(){
	int n;
	cin >> n;
	int data[maxn];
	for (int i = 0; i < n; i++){
		cin >> data[i];
	}

	node* root = createBST(data, n);
	preOrder(root);

	system("pause");
	return 0;
}