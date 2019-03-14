#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 100;
int heap[maxn], n;

//自上向下调整堆
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

//自下向上调整堆
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

//构造最大堆
void createHeap(){
	for (int i = n / 2; i >= 1; i--){
		downAdjust(i, n);
	}
}

//删除堆顶元素
void deleteHeap(){
	heap[1] = heap[n--]; //用最后一个元素覆盖堆顶元素，并让元素个数-1
	downAdjust(1, n); //向下调整堆顶元素
}

//添加元素x
void insertHeap(int x){
	heap[++n] = x; //让元素个数+1，然后将数组末位赋值为x
	upAdjust(1, n); //向上调整新加入的结点n
}

void heapSort(){
	createHeap(); //最大堆
	for (int i = n; i > 1; i--){ //倒着枚举，直到堆中只有一个元素
		swap(heap[i], heap[1]); //每次交换heap[i]与堆顶
		downAdjust(1, i - 1); //调整堆顶
	}
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> heap[i];
	}
	heapSort(); //从小到大排序
	for (int i = 1; i <= n; i++){
		cout << heap[i] << " ";
	}
	system("pause");
	return 0;
}