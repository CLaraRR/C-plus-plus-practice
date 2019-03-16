/*
����һ�������޻�ͼ��DAG�����������ͼ������·����Ȩֵ֮������������
��dp[i]��ʾ��i�Ž�β�����ܻ�õ��·������
*/
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000;
const int INF = 0x3fffffff;
int n, m, G[maxn][maxn]; //�ڵ�������������¼����ͼ�ڵ�֮���Ȩֵ��ά����
int dp[maxn]; //dp[i]��ʾ��i�Ž�β�����ܻ�õ��·������
vector<int> pre[maxn]; //��¼�·���϶����ǰ�̽��

void DP(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (G[i][j] != INF){
				int temp = dp[i] + G[i][j];
				if (temp > dp[j]){
					dp[j] = temp;
					pre[j].clear();
					pre[j].push_back(i);
				}
				else if (temp == dp[j]){
					pre[j].push_back(i);
				}
			}
		}
	}
}

//����ж����·�������������һ�����޷�����ֵ�����С�ģ�
void printPath(int i){
	if (pre[i].size() == 0){
		cout << i << " ";
		return;
	}
	printPath(pre[i][0]);
	cout << i << " ";
}

int main(){
	cin >> n >> m;
	memset(dp, 0, sizeof(dp));
	fill(G[0], G[0] + maxn*maxn, INF);
	int u, v, wt;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> wt;
		G[u][v] = wt;
	}
	
	//����Ը�������iΪ��β���·��dp[i]
	//��dp[i]�����ֵ������DAG���·������
	DP();
	int maxdis = dp[0];
	int end = 0;
	for (int i = 1; i < n; i++){
		if (dp[i] > maxdis){
			maxdis = dp[i];
			end = i; //��¼�·�����յ�
		}
	}
	cout << maxdis << endl;
	printPath(end); //��ӡ����dp[i]Ϊ��β���·�������ж������ӡ����һ��

	system("pause");
	return 0;
}