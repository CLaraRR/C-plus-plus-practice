#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
	//��������
	/*int a, b;
	while (scanf("%d%d", &a, &b) != EOF){ //�������м䲻���ж��ٸ��ո񶼿�����һ���ո�
		cout << a + b << endl;
	}*/

	//����string
	/*string str;
	while (getline(cin,str)){ //����ո�
		cout << str << endl;
	}*/

	//����char����
	char str[256];
	while (gets(str) != NULL){ //����ո�
		cout << str << endl;
	}
	//while (scanf("%s", str) != EOF){ //���ַ���������ո�
	//	cout << str << endl;
	//}

	system("pause");
	return 0;
}