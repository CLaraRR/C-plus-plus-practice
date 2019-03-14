#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;

int pre[maxn], in[maxn]; //先序、中序序列
int n; //结点个数

struct node
{
	int data; //数据域
	int layer; //结点所在深度
	node* lchild; //左孩子结点
	node* rchild; //右孩子结点
};

//利用先序和中序序列建树
//当前先序序列区间为[preL,preR],中序序列区间为[inL,inR],返回根结点地址
node *buildTree(int preL, int preR, int inL, int inR){
	if (preL > preR) return NULL; //先序序列长度小于等于0时，直接返回

	node* root = new node; //新建一个节点用来存放当前二叉树的根节点
	root->data = pre[preL]; //根结点即为先序序列中第一个
	int k = inL;
	while (k <= inR){
		if (in[k] == pre[preL]) break; //在中序序列中找到in[k]==pre[preL]的结点，该节点是根结点
		k++;
	}

	int numLeft = k - inL; //左子树的结点个数

	//左子树的先序区间为[preL + 1, preL + numLeft],中序区间为[inL, k - 1]
	//返回左子树的根结点地址，赋值给root的左孩子指针
	root->lchild = buildTree(preL + 1, preL + numLeft, inL, k - 1);

	//右子树的先序区间为[preL + numLeft + 1, preR],中序区间为[k + 1, inR]
	//返回右子树的根节点地址，赋值给root的右孩子指针
	root->rchild = buildTree(preL + numLeft + 1, preR, k + 1, inR);

	return root; //返回根结点地址
}

//层序遍历
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	int k = 0;
	while (!q.empty()){
		node* now = q.front();
		q.pop();
		cout << now->data;
		if (k < n) cout << " ";
		if (now->lchild) q.push(now->lchild);
		if (now->rchild) q.push(now->rchild);
	}
	cout << endl;

}


int main(){
	cin >> n;
	//先输入先序
	for (int i = 0; i < n; i++){
		cin >> pre[i];
	}
	//再输入中序
	for (int i = 0; i < n; i++){
		cin >> in[i];
	}

	//用先序和中序序列建树
	node* root = buildTree(0, n - 1, 0, n - 1);

	//层次遍历该树
	BFS(root);

	system("pause");
	return 0;
}