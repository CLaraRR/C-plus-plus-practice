#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const int maxn = 1000;

vector<int> Adj[maxn];
int n, m, inDegree[maxn];

bool TopologicalSort(){
	int num = 0;
	priority_queue<int, vector<int>,greater<int> > q;
	for (int i = 0; i < n; i++){
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()){
		int u = q.top();
		q.pop();
		for (int i = 0; i < Adj[u].size(); i++){
			int v = Adj[u][i];
			inDegree[v]--;
			if (inDegree[v] == 0)
				q.push(v);
		}
		Adj[u].clear();
		num++;
	}
	if (num == n)
		return true;
	else
		return false;
}

int main(){
	cin >> n >> m;
	memset(inDegree, 0, sizeof(inDegree));
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		Adj[u].push_back(v);
		inDegree[v]++;
	}
	bool isTopo = TopologicalSort();
	if (isTopo)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	system("pause");
	return 0;
}