#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000;

int n, capacity; //n����Ʒ������Ϊcapacity�ı���
int w[maxn], v[maxn]; //ÿ����Ʒ����������ÿ����Ʒ�ļ�ֵ
int dp[maxn][maxn]; //dp[i][j]��ʾ����Ϊjʱ��ǰi����Ʒ��������װ��ȥ����õ�����ֵ��ǰi����һ����װ��ȥ��


int getMaxValue(){
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= capacity; j++){
			if (i == 0 || j == 0){ //�߽�
				dp[i][j] = 0;
			}
			else if (j < w[i]){ //�������jС�ڵ�ǰ��Ʒ������w[i],��װ����ȥ
				dp[i][j] = dp[i - 1][j];
			}
			else{ //�����ǰ��Ʒ����װ��ȥ����ô����ѡ��װ�����ߡ���װ��
				dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);	//�������װ����������Ϊjʱǰi����Ʒ������ֵ��������Ϊjʱǰi-1����Ʒ������ֵ
				//�����װ����������Ϊjʱǰi����Ʒ������ֵ���ڵ���ȥ��ǰ��Ʒ�������õ���ʣ������Ϊj-w[i]ʱǰi����Ʒ������ֵ��Ȼ���ټ��ϵ�ǰ��Ʒ�ļ�ֵ���õ��ļ�ֵ
				//����dp[i][j]��ֵΪ��������ֵ��ȡ�ϴ����һ��
			}
		}
	}
	return dp[n][capacity]; //�����Ǹ�Ԫ�ؾ��ǻ�õ�����ֵ
}



int main(){
	cin >> n >> capacity;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int maxValue = getMaxValue();
	cout << maxValue << endl;

	system("pause");
	return 0;


}