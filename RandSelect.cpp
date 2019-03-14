/* 
����������һ����������ɵļ��ϣ������е�����������ͬ������Ҫ������Ϊ�����Ӽ��ϣ�
ʹ���������Ӽ��ϵĲ�Ϊԭ���ϣ���Ϊ�ռ���ͬʱ�������Ӽ��ϵ�Ԫ�ظ���n1��n1֮���
����ֵ|n1-n2|������С��ǰ���£�Ҫ�����Ǹ��Ե�Ԫ��֮��S1��S2֮��ľ���ֵ|S1-S2|
�����ܴ�
���⣺�����|S1-S2|���ڶ��٣�
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// �������������ֵ
int randPartition(int A[], int left, int right){
	int p = (round(1.0*rand() / RAND_MAX*(right - left) + left));
	swap(A[p], A[left]);
	int temp = A[left];
	while (left < right){
		while (left<right&&A[right]>temp)
			right--;
		A[left] = A[right];
		while (left < right&&A[left] < temp)
			left++;
		A[right] = A[left];

	}
	A[left] = temp;
	return left;
}

int randSelect(int A[], int left, int right,int K){
	if (left == right)
		return A[left];
	int p = randPartition(A, left, right);
	int M = p - left + 1;
	if (K == M)
		return A[p];
	if (K < M){
		return randSelect(A, left, p - 1, K);
	}
	else{
		return randSelect(A, p + 1, right, K - M);
	}
}

int main(){
	srand((unsigned)time(NULL));
	int sum = 0, sum1 = 0;
	int n;
	int A[100010];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
		sum += A[i];
	}
	randSelect(A, 0, n - 1, n / 2);
	for (int i = 0; i < n / 2; i++){
		sum1 += A[i];
	}
	cout << (sum - sum1) - sum1 << endl;
	system("pause");
	return 0;
}