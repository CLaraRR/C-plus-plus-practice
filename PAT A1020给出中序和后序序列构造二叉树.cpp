#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;

int post[maxn], in[maxn]; //后序、中序序列
int n; //结点个数

struct node
{
	int data; //数据域
	int layer; //结点所在深度
	node* lchild; //左孩子结点
	node* rchild; //右孩子结点
};

//利用后序和中序序列建树
//当前后序序列区间为[postL,postR],中序序列区间为[inL,inR],返回根结点地址
node *buildTree(int postL, int postR, int inL, int inR){
	if (postL > postR) return NULL;//后序序列长度小于等于0时，直接返回

	node* root = new node;
	root->data = post[postR];//根结点即为后序序列中最后一个
	int k = inL;
	while (k <= inR){
		if (in[k] == post[postR]) break;//在中序序列中找到in[k]==pre[postR]的结点，该节点是根结点
		k++;
	}

	int numLeft = k - inL;//左子树的结点个数

	//左子树的后序区间为[postL, postL + numLeft-1],中序区间为[inL, k - 1]
	//返回左子树的根结点地址，赋值给root的左孩子指针
	root->lchild = buildTree(postL, postL + numLeft-1, inL, k - 1);

	//右子树的后序区间为[postL + numLeft, postR-1],中序区间为[k + 1, inR]
	//返回右子树的根节点地址，赋值给root的右孩子指针
	root->rchild = buildTree(postL + numLeft, postR-1, k + 1, inR);

	return root;//返回根结点地址
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
	//先输入后序
	for (int i = 0; i < n; i++){
		cin >> post[i];
	}
	//再输入中序
	for (int i = 0; i < n; i++){
		cin >> in[i];
	}

	//用后序和中序序列建树
	node* root = buildTree(0, n - 1, 0, n - 1);

	//层次遍历输出该树
	BFS(root);

	system("pause");
	return 0;
}