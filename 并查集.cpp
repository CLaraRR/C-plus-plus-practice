#include <iostream>
#include <stdlib.h>
using namespace std;

const int maxn = 1000;
int father[maxn];
bool isRoot[maxn];

//��ü��ϵĸ����
int findFather(int x){
	int a = x;
	while (x != father[x]){
		x = father[x];
	}

	//·��ѹ�����ɲ�д����ֻҪѹ��һ�Σ��Ժ���father��ֻ�û���O(1)ʱ��
	while (a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;

	}
	return x;
}


//�ϲ�a��b���ڵļ���
void Union(int a, int b){
	int fA = findFather(a);
	int fB = findFather(b);
	if (fA != fB){
		father[fA] = fB;
	}
}

//��ʼ��father[i]=i,��һ��ʼÿ��Ԫ�ص�father�����Լ�
void init(int n){
	for (int i = 1; i <= n; i++){
		father[i] = i;
		isRoot[i] = false;
	}
}

int main(){
	int n, m, a, b;
	cin >> n >> m;
	init(n);
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= n; i++){
		isRoot[findFather(i)] = true;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans += isRoot[i];
	}

	cout << ans << endl;
	system("pause");
	return 0;
}