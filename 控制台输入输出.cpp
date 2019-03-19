#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
	//输入数字
	/*int a, b;
	while (scanf("%d%d", &a, &b) != EOF){ //两个数中间不管有多少个空格都看作是一个空格
		cout << a + b << endl;
	}*/

	//输入string
	/*string str;
	while (getline(cin,str)){ //读入空格
		cout << str << endl;
	}*/

	//输入char数组
	char str[256];
	while (gets(str) != NULL){ //读入空格
		cout << str << endl;
	}
	//while (scanf("%s", str) != EOF){ //这种方法不读入空格
	//	cout << str << endl;
	//}

	system("pause");
	return 0;
}