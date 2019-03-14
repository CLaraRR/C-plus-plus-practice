#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

const int maxn = 1000;
int wpl = 0; //��Ȩ·����
vector<int> path; //��¼�������ʱ������01����

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

//���ز�������freq��С�Ľ�����ȼ���
struct cmp
{
	bool operator()(node* a, node* b){
		return a->freq > b->freq;
	}
};

//�����������
node* createHuffman(priority_queue<node*, vector<node*>, cmp> q, int n){
	while (q.size() > 1){ //ֻҪ���ȶ���������������Ԫ�أ���Ҫ���ϵ������츸�ڵ�
		node* x = q.top();
		q.pop();
		node* y = q.top();
		q.pop();
		node* newnode = new node(x->freq + y->freq); //ÿ��ȡ���Ѷ���������㣬�������ڵ��ֵ��Ӻ���Ϊ�µĽڵ��������
		newnode->lchild = x; //���½ڵ�����Һ���ָ��ֱ�ָ�����������
		newnode->rchild = y;
		q.push(newnode); //���½ڵ�ѹ�����ȶ���
		wpl += x->freq + y->freq; //�ۼ����Ȩ·����
	}
	node* root = q.top(); //���ȶ�����ʣ�µ����һ����㼴Ϊ���õĹ��������ĸ����
	return root;
}

//���������Ҷ�ӽ����б���
void EncodeHuffman(node* root){
	if (root->lchild == NULL&&root->rchild == NULL){ //����ǰ��Ҷ�ӽ��
		root->huffcode = path; //��ѵ�ǰpath��¼�ı��봮����Ҷ�ӽ��
		path.pop_back(); //�����һ����Ԫ��path��ɾ��
		return;
	}

	if (root->lchild != NULL){
		path.push_back(0); //���������߱���0
		EncodeHuffman(root->lchild);
	}
	if (root->rchild != NULL){
		path.push_back(1); //���������߱���1
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
	priority_queue<node*, vector<node*>, cmp> q; //����С���ѵ����ȶ��У����ڹ�����������
	vector<node*> nodes; //����ԭʼҶ�ӽ�㣨��������Ҷ�ӽڵ㣩
	for (int i = 0; i < n; i++){
		cin >> data >> freq;
		node* newnode = new node(data, freq);
		nodes.push_back(newnode);
		q.push(newnode);
	}

	node* root = createHuffman(q, n); //������������
	EncodeHuffman(root); //����������
	printHuffmanCode(nodes); //���ÿ���ַ���Ӧ�Ĺ���������
	cout << wpl << endl; //��Ȩ·����

	system("pause");
	return 0;
}