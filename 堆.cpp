#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100;
int heap[maxn], n;

//�������µ�����
void downAdjust(int low, int high){
	int i = low, j = i * 2;
	while (j <= high){
		if (j + 1 <= high&&heap[j + 1] > heap[j]){
			j = j + 1;
		}

		if (heap[j] > heap[i]){
			swap(heap[j], heap[i]);
			i = j;
			j = i * 2;
		}
		else{
			break;
		}
	}
}

//�������ϵ�����
void upAdjust(int low, int high){
	int i = high, j = i / 2;
	while (j >= low){
		if (heap[j] < heap[i]){
			swap(heap[j], heap[i]);
			i = j;
			j = i / 2;
		}
		else{
			break;
		}
	}
}

//��������
void createHeap(){
	for (int i = n / 2; i >= 1; i--){
		downAdjust(i, n);
	}
}

//ɾ���Ѷ�Ԫ��
void deleteHeap(){
	heap[1] = heap[n--]; //�����һ��Ԫ�ظ��ǶѶ�Ԫ�أ�����Ԫ�ظ���-1
	downAdjust(1, n); //���µ����Ѷ�Ԫ��
}

//���Ԫ��x
void insertHeap(int x){
	heap[++n] = x; //��Ԫ�ظ���+1��Ȼ������ĩλ��ֵΪx
	upAdjust(1, n); //���ϵ����¼���Ľ��n
}

void heapSort(){
	createHeap(); //����
	for (int i = n; i > 1; i--){ //����ö�٣�ֱ������ֻ��һ��Ԫ��
		swap(heap[i], heap[1]); //ÿ�ν���heap[i]��Ѷ�
		downAdjust(1, i - 1); //�����Ѷ�
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> heap[i];
	}
	heapSort(); //��С��������
	for (int i = 1; i <= n; i++){
		cout << heap[i] << " ";
	}
	system("pause");
	return 0;
}