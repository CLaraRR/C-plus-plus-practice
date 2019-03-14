#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;

int pre[maxn], in[maxn]; //������������
int n; //������

struct node
{
	int data; //������
	int layer; //����������
	node* lchild; //���ӽ��
	node* rchild; //�Һ��ӽ��
};

//����������������н���
//��ǰ������������Ϊ[preL,preR],������������Ϊ[inL,inR],���ظ�����ַ
node *buildTree(int preL, int preR, int inL, int inR){
	if (preL > preR) return NULL; //�������г���С�ڵ���0ʱ��ֱ�ӷ���

	node* root = new node; //�½�һ���ڵ�������ŵ�ǰ�������ĸ��ڵ�
	root->data = pre[preL]; //����㼴Ϊ���������е�һ��
	int k = inL;
	while (k <= inR){
		if (in[k] == pre[preL]) break; //�������������ҵ�in[k]==pre[preL]�Ľ�㣬�ýڵ��Ǹ����
		k++;
	}

	int numLeft = k - inL; //�������Ľ�����

	//����������������Ϊ[preL + 1, preL + numLeft],��������Ϊ[inL, k - 1]
	//�����������ĸ�����ַ����ֵ��root������ָ��
	root->lchild = buildTree(preL + 1, preL + numLeft, inL, k - 1);

	//����������������Ϊ[preL + numLeft + 1, preR],��������Ϊ[k + 1, inR]
	//�����������ĸ��ڵ��ַ����ֵ��root���Һ���ָ��
	root->rchild = buildTree(preL + numLeft + 1, preR, k + 1, inR);

	return root; //���ظ�����ַ
}

//�������
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
	//����������
	for (int i = 0; i < n; i++){
		cin >> pre[i];
	}
	//����������
	for (int i = 0; i < n; i++){
		cin >> in[i];
	}

	//��������������н���
	node* root = buildTree(0, n - 1, 0, n - 1);

	//��α�������
	BFS(root);

	system("pause");
	return 0;
}