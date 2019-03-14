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

//��ȡ��rootΪ������AVL����
int getHeight(node* root){
	if (root == NULL) 
		return 0;
	return root->height;
}

//��ȡ��ǰ�ڵ��ƽ������
int getBalanceFactor(node* root){
	return getHeight(root->lchild) - getHeight(root->rchild);
}

//������rootΪ������AVL����
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

//��AVL���в���������Ϊx�Ľ��
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

//��������
void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

//��������
void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

//��AVL���в���һ��������Ϊx�Ľ�㣬ʹ֮�������AVL��
void insertAVL(node* &root, int x){
	if (root == NULL){
		root = new node(x);
		return;
	}
	if (x < root->data){
		insertAVL(root->lchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == 2){ //�ҵ�������������ƽ������Ϊ2�Ľ��
			if (getBalanceFactor(root->lchild) == 1){ //LL��
				R(root); //ֱ�Ӷ�������ڵ�Ϊ������������һ��
			}
			else if (getBalanceFactor(root->lchild) == -1){  //LR��
				L(root->lchild); //�ȶ�����ڵ������������
				R(root); //�ٶ�������ڵ�Ϊ������������һ��
			}
		}
	}
	else{
		insertAVL(root->rchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == -2){ //�ҵ�������������ƽ������Ϊ-2�Ľ��
			if (getBalanceFactor(root->rchild) == -1){ //RR��
				L(root); //ֱ�Ӷ�������ڵ�Ϊ������������һ��
			}
			else if (getBalanceFactor(root->rchild) == 1){ //RL��
				R(root->rchild); //�ȶ�����ڵ������������
				L(root); //�ٶ�������ڵ�Ϊ������������һ��
			}
		}
	}
}

//����AVL��
node* createAVL(int data[], int n){
	node* root = NULL;
	for (int i = 0; i < n; i++){
		insertAVL(root, data[i]);
	}
	return root;
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

	node* root = createAVL(data, n);
	preOrder(root);

	system("pause");
	return 0;
}