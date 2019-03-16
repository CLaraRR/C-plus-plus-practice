/*
��n�����Σ�ÿ�����ο�����a,b����������ʾ���Ϳ�����X(a,b)����Ƕ����
����Y(c,d)�е��ҽ���a<c,b<d����b<c,a<d���൱����תX90�ȣ���
���磨1,5������Ƕ���ڣ�6,2���ڣ�������Ƕ���ڣ�3,4���С�
���������ѡ�������ܶ�ľ����ų�һ�У�ʹ�ó����һ���⣬ÿһ�����ζ�
����Ƕ������һ�������ڡ�

��ÿ�����ο���һ�����㣬����Ƕ�׹�ϵ��Ϊ����֮�������ߣ���Ȩ��Ϊ1������ת��ΪDAG�·����
*/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1000;
const int INF = 0x3fffffff;

int n; //���θ���
int G[maxn][maxn];
int dp[maxn];
vector<int> post[maxn];

struct Rectangle
{
	int x;
	int y;
}rec[maxn];

bool isContain(Rectangle a, Rectangle b){
	return (a.x < b.x) && (a.y < b.y);
}

int DP(int i){
	if (dp[i] > 0)
		return dp[i]; //dp[i]�Ѿ�����õ�
	for (int j = 0; j < n; j++){ //����i�����г���
		if (G[i][j] != INF){
			int temp = DP(j) + 1; //״̬ת�Ʒ���dp[i]=max(dp[i],dp[i]+1)
			if (temp > dp[i]){ //������Ի�ø�����·��
				dp[i] = temp; //����dp[i]
				post[i].clear(); //֮ǰ��¼�ĺ�̽�㶼Ҫ���
				post[i].push_back(j); //�����µĺ�̽ڵ�
			}
			else if (temp == dp[i]){
				post[i].push_back(j); //�������ͬ��·�����ȣ�Ҳ�������̽ڵ����
			}
		}

	}
	return dp[i]; //���ؼ�����ϵ�dp[i]
}

//����ж����·����������ֵ�����С��·��
void printPath(int i){
	cout << i << " ";
	while (post[i].size() != 0){
		i = post[i][0];
		cout << i << " ";
	}
	cout << endl;
}


int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> rec[i].x >> rec[i].y;
		if (rec[i].x < rec[i].y){
			swap(rec[i].x, rec[i].y);
		}
	}
	fill(G[0], G[0] + maxn*maxn, INF);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (isContain(rec[i], rec[j])){
				G[i][j] = 1;
			}
		}
	}
	memset(dp, 0, sizeof(dp));
	int maxdis = 0;
	int start;
	for (int i = 0; i < n; i++){
		int dis = DP(i);
		if (dis > maxdis){
			maxdis = dis;
			start = i;
		}
	}
	cout << maxdis + 1 << endl; //���θ��������·��+1
	printPath(start); //����㿪ʼ��ӡ���·��������Ӹ���㿪ʼ�ж����·�����ӡ�ֵ�����С������

	system("pause");
	return 0;
}