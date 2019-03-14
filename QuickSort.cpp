#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// �̶�������ֵ
int Partition(int A[], int left, int right){
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

void quickSort(int A[], int left, int right){
	if (left < right){
		//int pos = Partition(A, left, right);
		int pos = randPartition(A, left, right); // ���������ֵ�Ļ��ֺ���
		quickSort(A, left, pos - 1);
		quickSort(A, pos + 1, right);
	}
}

int main(){
	srand((unsigned)time(NULL));
	int A[1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}
	quickSort(A, 0, n - 1);
	for (int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	system("pause");
	return 0;

}