#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1000;
const int INF = 0x3fffffff;

int n, m, G[maxn][maxn];
int d[maxn];
bool visited[maxn] = { false };

int Prim(){
	fill(d, d + n, INF);
	d[0] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++){
		int u = -1, min = INF;
		for (int j = 0; j < n; j++){
			if (visited[j] == false && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if (u == -1)
			return -1;
		visited[u] = true;
		ans += d[u];
		for (int v = 0; v < n; v++){
			if (visited[v] == false && G[u][v] != INF && G[u][v] < d[v]){
				d[v] = G[u][v];
			}
		}
	}
	return ans;
}



int main(){
	cin >> n >> m;
	fill(G[0], G[0] + maxn*maxn, INF);
	int u, v, w;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = w;
	}
	int ans = Prim();
	cout << ans << endl;
	
	system("pause");
	return 0;
}