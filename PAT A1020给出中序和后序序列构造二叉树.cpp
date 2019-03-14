#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;

int post[maxn], in[maxn]; //������������
int n; //������

struct node
{
	int data; //������
	int layer; //����������
	node* lchild; //���ӽ��
	node* rchild; //�Һ��ӽ��
};

//���ú�����������н���
//��ǰ������������Ϊ[postL,postR],������������Ϊ[inL,inR],���ظ�����ַ
node *buildTree(int postL, int postR, int inL, int inR){
	if (postL > postR) return NULL;//�������г���С�ڵ���0ʱ��ֱ�ӷ���

	node* root = new node;
	root->data = post[postR];//����㼴Ϊ�������������һ��
	int k = inL;
	while (k <= inR){
		if (in[k] == post[postR]) break;//�������������ҵ�in[k]==pre[postR]�Ľ�㣬�ýڵ��Ǹ����
		k++;
	}

	int numLeft = k - inL;//�������Ľ�����

	//�������ĺ�������Ϊ[postL, postL + numLeft-1],��������Ϊ[inL, k - 1]
	//�����������ĸ�����ַ����ֵ��root������ָ��
	root->lchild = buildTree(postL, postL + numLeft-1, inL, k - 1);

	//�������ĺ�������Ϊ[postL + numLeft, postR-1],��������Ϊ[k + 1, inR]
	//�����������ĸ��ڵ��ַ����ֵ��root���Һ���ָ��
	root->rchild = buildTree(postL + numLeft, postR-1, k + 1, inR);

	return root;//���ظ�����ַ
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
	//���������
	for (int i = 0; i < n; i++){
		cin >> post[i];
	}
	//����������
	for (int i = 0; i < n; i++){
		cin >> in[i];
	}

	//�ú�����������н���
	node* root = buildTree(0, n - 1, 0, n - 1);

	//��α����������
	BFS(root);

	system("pause");
	return 0;
}