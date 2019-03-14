#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int wpl = 0; //带权路径和

struct node
{
	int data;
	node* lchild;
	node* rchild;
	node(int x) :data(x), lchild(NULL), rchild(NULL){}
};

//重载操作符,data域小的结点优先级高
struct cmp
{
	bool operator ()(node* a, node* b){
		return a->data > b->data;
	}
};


//构造哈夫曼树
node* createHuffman(priority_queue<node*, vector<node*>, cmp> q, int n){
	while (q.size() > 1){ //只要优先队列中至少有两个元素，就要不断弹出构造父节点
		node* x = q.top();
		q.pop();
		node* y = q.top();
		q.pop();
		node* newnode = new node(x->data + y->data); //每次取出堆顶的两个结点，将两个节点的值相加后作为新的节点的数据域
		newnode->lchild = x; //将新节点的左右孩子指针分别指向那两个结点
		newnode->rchild = y;
		q.push(newnode); //将新节点压入优先队列
		wpl += x->data + y->data; //累计求带权路径和
	}
	node* root = q.top(); //优先队列中剩下的最后一个结点即为建好的哈夫曼树的根结点
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

int main(){
	int n;
	cin >> n;
	int num;
	priority_queue<node*,vector<node*>,cmp> q; //代表小顶堆的优先队列，用于构建哈夫曼树
	for (int i = 0; i < n; i++){
		cin >> num;
		node* newnode = new node(num);
		q.push(newnode);
	}

	node* root = createHuffman(q, n); //构建哈夫曼树
	preOrder(root); //先序遍历
	cout << endl; 
	cout << wpl << endl; //带权路径和
	system("pause");
	return 0;
}