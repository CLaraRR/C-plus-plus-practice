#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000;

int n, capacity; //n����Ʒ������Ϊcapacity�ı���
int w[maxn], v[maxn]; //ÿ����Ʒ����������ÿ����Ʒ�ļ�ֵ
int dp[maxn]; //�������飬��ÿ����ƷΪһ���׶Σ�����ÿ���׶Σ�dp[j]��ʾ����Ϊjʱ��ǰi����Ʒ��������װ��ȥ����õ�����ֵ��ǰi����һ����װ��ȥ��


int getMaxValue(){
	for (int i = 1; i <= n; i++){
		for (int j = w[i]; j <= capacity; j++){
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);	
		}
	}
	return dp[capacity]; //�����Ǹ�Ԫ�ؾ��ǻ�õ�����ֵ
}



int main(){
	cin >> n >> capacity;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
		cin >> v[i];

	//��ʼ���߽�
	for (int i = 0; i <= capacity; i++){
		dp[i] = 0;
	}
	int maxValue = getMaxValue();
	cout << maxValue << endl;

	system("pause");
	return 0;


}