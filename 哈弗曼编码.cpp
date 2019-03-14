#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

const int maxn = 1000;
int wpl = 0; //带权路径和
vector<int> path; //记录先序遍历时产生的01编码

struct node
{
	char data;
	int freq;
	vector<int> huffcode;
	node* lchild;
	node* rchild;
	node(char x,int y) :data(x), freq(y),lchild(NULL), rchild(NULL){}
	node(int y) :data(NULL), freq(y), lchild(NULL), rchild(NULL){}
};

//重载操作符，freq域小的结点优先级高
struct cmp
{
	bool operator()(node* a, node* b){
		return a->freq > b->freq;
	}
};

//构造哈夫曼树
node* createHuffman(priority_queue<node*, vector<node*>, cmp> q, int n){
	while (q.size() > 1){ //只要优先队列中至少有两个元素，就要不断弹出构造父节点
		node* x = q.top();
		q.pop();
		node* y = q.top();
		q.pop();
		node* newnode = new node(x->freq + y->freq); //每次取出堆顶的两个结点，将两个节点的值相加后作为新的节点的数据域
		newnode->lchild = x; //将新节点的左右孩子指针分别指向那两个结点
		newnode->rchild = y;
		q.push(newnode); //将新节点压入优先队列
		wpl += x->freq + y->freq; //累计求带权路径和
	}
	node* root = q.top(); //优先队列中剩下的最后一个结点即为建好的哈夫曼树的根结点
	return root;
}

//先序遍历对叶子结点进行编码
void EncodeHuffman(node* root){
	if (root->lchild == NULL&&root->rchild == NULL){ //若当前是叶子结点
		root->huffcode = path; //则把当前path记录的编码串赋给叶子结点
		path.pop_back(); //把最后一个码元从path中删除
		return;
	}

	if (root->lchild != NULL){
		path.push_back(0); //往左子树走编码0
		EncodeHuffman(root->lchild);
	}
	if (root->rchild != NULL){
		path.push_back(1); //往右子树走编码1
		EncodeHuffman(root->rchild);
	}
	
}


void printHuffmanCode(vector<node*> nodes){
	for (int i = 0; i < nodes.size();i++){
		cout << nodes[i]->data << ":";
		vector<int> code = nodes[i]->huffcode;
		for (int j = 0; j < code.size();j++){
			cout << code[j];
		}
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	char data;
	int freq;
	priority_queue<node*, vector<node*>, cmp> q; //代表小顶堆的优先队列，用于构建哈夫曼树
	vector<node*> nodes; //保存原始叶子结点（不包含非叶子节点）
	for (int i = 0; i < n; i++){
		cin >> data >> freq;
		node* newnode = new node(data, freq);
		nodes.push_back(newnode);
		q.push(newnode);
	}

	node* root = createHuffman(q, n); //构建哈夫曼树
	EncodeHuffman(root); //哈弗曼编码
	printHuffmanCode(nodes); //输出每个字符对应的哈弗曼编码
	cout << wpl << endl; //带权路径和

	system("pause");
	return 0;
}