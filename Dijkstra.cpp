#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1000;
const int INF = 0x3fffffff;

int n, m, s, G[maxn][maxn];
int d[maxn];
int pre[maxn];
bool visited[maxn] = { false };

void Dijkstra(int s){
	fill(d, d + n, INF);
	d[s] = 0;
	for (int i=0; i < n; i++){
		int u = -1, min = INF;
		for (int j = 0; j < n; j++){
			if (visited[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if (u == -1)
			return;
		visited[u] = true;
		for (int v = 0; v < n; v++){
			if (visited[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
				pre[v] = u;
			}
		}
	}
}

void printPath(int s, int v){
	if (v == s){
		cout << v << " ";
		return;
	}
	printPath(s, pre[v]);
	cout << v << " ";
}

int main(){
	cin >> n >> m >> s;
	fill(G[0], G[0] + maxn*maxn, INF);
	int u, v, w;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> w;
		G[u][v] = w;
	}
	Dijkstra(s);
	cout << endl;
	for (int i = 0; i < n; i++){
		cout << d[i] << " ";
	}
	for (int i = 0; i < n; i++){
		cout << s << "->" << i << ":";
		printPath(s, i);
		cout << endl;
	}
	system("pause");
	return 0;
}