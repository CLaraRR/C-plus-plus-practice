#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int A[maxn], dp[maxn];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	int maxlen = -1; //��¼����dp[i]
	for (int i = 0; i < n; i++){ //��˳������dp[i]��ֵ
		dp[i] = 1; //�߽��ʼ���������ȼ���ÿ��Ԫ���Գ�һ�����У�
		for (int j = 0; j < i; j++){
			if (A[j]<=A[i] && dp[j] + 1>dp[i]){ //״̬ת������
				dp[i] = dp[j] + 1; //״̬ת�Ʒ��̣����Ը���dp[i]
			}
		}
		maxlen = max(maxlen, dp[i]);
	}
	cout << maxlen << endl;
	system("pause");
	return 0;
}