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

//����BST��������Ϊx�Ľ��
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

//��BST�в���������Ϊx���½ڵ�     
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

//BST�Ľ���
node* createBST(int data[], int n){
	node* root = NULL;
	for (int i = 0; i < n; i++){
		insertBST(root, data[i]);
	}
	return root;
}

//�ҵ�BST�����Ȩֵ���
node* findMaxNodeBST(node* root){
	while (root->rchild)
		root = root->rchild;
	return root;
}

//�ҵ�BST����СȨֵ���
node* findMinNodeBST(node* root){
	while (root->lchild)
		root = root->lchild;
	return root;
}

//ɾ��ȨֵΪx�Ľ��,����ʹ�ø߶Ȳ�ƽ��
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

//�������
void preOrder(node* root){
	if (root == NULL){
		return;
	}
		
	cout << root->data << " ";
	preOrder(root->lchild);
	preOrder(root->rchild);
}

//�������
void inOrder(node* root){
	if (root == NULL){
		return;
	}
	inOrder(root->lchild);
	cout << root->data << " ";
	inOrder(root->rchild);
}

//�������
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