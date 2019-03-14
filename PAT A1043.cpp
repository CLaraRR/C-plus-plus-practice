#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

const int maxn = 1010;

struct node
{
	int data;
	node* lchild;
	node* rchild;
	node(int x) :data(x), lchild(NULL), rchild(NULL){}
};

//在BST中插入数据域为x的新节点     
void insertBST(node* &root, int x,bool isBuildMirror){
	if (root == NULL){
		root = new node(x);
		return;
	}
	if (isBuildMirror == false){
		if (x < root->data)
			insertBST(root->lchild, x, isBuildMirror);
		else
			insertBST(root->rchild, x, isBuildMirror);
	}
	else{
		if (x > root->data)
			insertBST(root->lchild, x, isBuildMirror);
		else
			insertBST(root->rchild, x, isBuildMirror);
	}
	
}

//BST的建立
node* createBST(vector<int> data, int n,bool isBuildMirror){
	node* root = NULL;
	for (int i = 0; i < n; i++){
		insertBST(root, data[i],isBuildMirror);
	}
	return root;
}

//先序遍历
void preOrder(node* root,vector<int> &vi){
	if (root == NULL)
		return;
	
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
	
}

//后序遍历
void postOrder(node* root, vector<int> &vi){
	if (root == NULL)
		return;
	
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}

int main(){
	int n;
	cin >> n;
	vector<int> data;
	int num;
	for (int i = 0; i < n; i++){
		cin >> num;
		data.push_back(num);
	}
		
	node* root = createBST(data, n, false); //构造BST树
	node* root_mirror = createBST(data, n, true); //构造BST镜像树

	vector<int> pre, post, preM, postM;
	preOrder(root, pre);
	preOrder(root_mirror, preM);
	postOrder(root, post);
	postOrder(root_mirror, postM);
	if (data == pre){
		cout << "YES" << endl;
		for (int i = 0; i < n; i++){
			cout << post[i];
			if (i < n - 1) cout << " ";
		}
	}
	else if (data == preM){
		cout << "YES" << endl;
		postOrder(root_mirror, postM);
		for (int i = 0; i < n; i++){
			cout << postM[i];
			if (i < n - 1) cout << " ";
		}
	}
	else{
		cout << "NO" << endl;
	}
	

	system("pause");
	return 0;

}