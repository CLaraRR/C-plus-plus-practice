#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int wpl = 0; //��Ȩ·����

struct node
{
	int data;
	node* lchild;
	node* rchild;
	node(int x) :data(x), lchild(NULL), rchild(NULL){}
};

//���ز�����,data��С�Ľ�����ȼ���
struct cmp
{
	bool operator ()(node* a, node* b){
		return a->data > b->data;
	}
};


//�����������
node* createHuffman(priority_queue<node*, vector<node*>, cmp> q, int n){
	while (q.size() > 1){ //ֻҪ���ȶ���������������Ԫ�أ���Ҫ���ϵ������츸�ڵ�
		node* x = q.top();
		q.pop();
		node* y = q.top();
		q.pop();
		node* newnode = new node(x->data + y->data); //ÿ��ȡ���Ѷ���������㣬�������ڵ��ֵ��Ӻ���Ϊ�µĽڵ��������
		newnode->lchild = x; //���½ڵ�����Һ���ָ��ֱ�ָ�����������
		newnode->rchild = y;
		q.push(newnode); //���½ڵ�ѹ�����ȶ���
		wpl += x->data + y->data; //�ۼ����Ȩ·����
	}
	node* root = q.top(); //���ȶ�����ʣ�µ����һ����㼴Ϊ���õĹ��������ĸ����
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

int main(){
	int n;
	cin >> n;
	int num;
	priority_queue<node*,vector<node*>,cmp> q; //����С���ѵ����ȶ��У����ڹ�����������
	for (int i = 0; i < n; i++){
		cin >> num;
		node* newnode = new node(num);
		q.push(newnode);
	}

	node* root = createHuffman(q, n); //������������
	preOrder(root); //�������
	cout << endl; 
	cout << wpl << endl; //��Ȩ·����
	system("pause");
	return 0;
}