#include <iostream>
#include <stdlib.h>
using namespace std;

const int maxn = 1000;
int father[maxn];
bool isRoot[maxn];

//获得集合的根结点
int findFather(int x){
	int a = x;
	while (x != father[x]){
		x = father[x];
	}

	//路径压缩（可不写），只要压缩一次，以后找father都只用花费O(1)时间
	while (a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;

	}
	return x;
}


//合并a和b所在的集合
void Union(int a, int b){
	int fA = findFather(a);
	int fB = findFather(b);
	if (fA != fB){
		father[fA] = fB;
	}
}

//初始化father[i]=i,即一开始每个元素的father都是自己
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