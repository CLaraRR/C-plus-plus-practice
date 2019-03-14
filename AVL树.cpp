#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1000;

struct node
{
	int data;
	int height;
	node* lchild;
	node* rchild;
	node(int x) :data(x), height(1), lchild(NULL), rchild(NULL){}
};

//获取以root为根结点的AVL树高
int getHeight(node* root){
	if (root == NULL) 
		return 0;
	return root->height;
}

//获取当前节点的平衡因子
int getBalanceFactor(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

//更新以root为根结点的AVL树高
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

//在AVL树中查找数据域为x的结点
void search(node* root, int x){
	if (root == NULL){
		cout << "search failed!" << endl;
		return;
	}
	if (x == root->data)
		cout << root->data << endl;
	else if (x < root->data)
		search(root->lchild, x);
	else
		search(root->rchild, x);
}

//左旋操作
void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

//右旋操作
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

//在AVL树中插入一个数据域为x的结点，使之插入后还是AVL树
void insertAVL(node* &root, int x){
	if (root == NULL){
		root = new node(x);
		return;
	}
	if (x < root->data){
		insertAVL(root->lchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == 2){ //找到离插入结点最近的平衡因子为2的结点
			if (getBalanceFactor(root->lchild) == 1){ //LL型
				R(root); //直接对以这个节点为根结点的树右旋一次
			}
			else if (getBalanceFactor(root->lchild) == -1){  //LR型
				L(root->lchild); //先对这个节点的左子树左旋
				R(root); //再对以这个节点为根结点的树右旋一次
			}
		}
	}
	else{
		insertAVL(root->rchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == -2){ //找到离插入结点最近的平衡因子为-2的结点
			if (getBalanceFactor(root->rchild) == -1){ //RR型
				L(root); //直接对以这个节点为根结点的树左旋一次
			}
			else if (getBalanceFactor(root->rchild) == 1){ //RL型
				R(root->rchild); //先对这个节点的右子树右旋
				L(root); //再对以这个节点为根结点的树左旋一次
			}
		}
	}
}

//构造AVL树
node* createAVL(int data[], int n){
	node* root = NULL;
	for (int i = 0; i < n; i++){
		insertAVL(root, data[i]);
	}
	return root;
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

	node* root = createAVL(data, n);
	preOrder(root);

	system("pause");
	return 0;
}