#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1000;
char s[maxn];
int dp[maxn][maxn];

int main(){
	cin.getline(s, maxn);
	int len = strlen(s);
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			dp[i][j] = 0;
		}
	}

	int maxlen = 1;//���ĳ�������Ϊ1��ÿ���������ַ�����һ������
	//�߽�
	for (int i = 0; i < len; i++){
		dp[i][i] = 1; //ÿ���������ַ�����һ������
		if (i < len - 1){
			if (s[i] == s[i + 1]){
				dp[i][i + 1] = 1; //�������������ַ���ͬ��Ϊ����
				maxlen = 2;//���ĳ��ȸ���Ϊ2
			}
		}
	}

	//״̬ת�Ʒ���
	for (int k = 3; k <= len; k++){ //ö���Ӵ��ĳ���
		for (int i = 0; i + k - 1 < len; i++){
			int j = i + k - 1;
			//����ǰ���ȵ��Ӵ����������˵���ͬ���м���Ӵ�Ϊ���Ĵ���������Ӵ�Ϊ����
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1){
				dp[i][j] = 1;
				maxlen = k;//���ĳ��ȸ���
			}
		}
	}

	cout << maxlen << endl;



	system("pause");
	return 0;
}