#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxv = 110;
const int maxe = 10010;

int n, m;

struct Edge
{
	int u, v;
	int cost;
}edges[maxe];

bool cmp(Edge a, Edge b){
	return a.cost < b.cost;
}

int father[maxv];
//获得集合的根结点(递归)
int findFather(int x){
	if (x == father[x]) return x;
	else{
		int f = findFather(father[x]);
		father[x] = f; //路径压缩
		return f;
	}
}

int Kruskal(){
	int ans = 0, numEdge = 0;
	for (int i = 0; i < n; i++)
		father[i] = i;
	sort(edges, edges + m, cmp);
	for (int i = 0; i < m; i++){
		int faU = findFather(edges[i].u);
		int faV = findFather(edges[i].v);
		if (faU != faV){
			father[faU] = faV;
			ans += edges[i].cost;
			numEdge++;
			if (numEdge == n - 1) 
				break;
		}
	}
	if (numEdge != n - 1)
		return -1;
	else
		return ans;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> edges[i].u >> edges[i].v >> edges[i].cost;

	}
	int ans = Kruskal();
	cout << ans << endl;

	system("pause");
	return 0;
}