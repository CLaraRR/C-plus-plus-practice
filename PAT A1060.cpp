/* �������������ʽ�����д�ɱ���NλС���Ŀ�ѧ���������Ƿ���ȡ�
�����ȣ������YES����������ת��������������ȣ������NO��
���ֱ������������ת�������
*/
#include <iostream>
#include <stdlib.h>                                                       
#include <string>
using namespace std;

string deal(string s, int &e,int n){
	int k = 0;
	while (s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());
	}
	if (s[0] == '.'){
		s.erase(s.begin());
		while (s.length() > 0 && s[0] == '0'){
			s.erase(s.begin());
			e--;
		}
	}
	else{
		while (k < s.length() && s[k] != '.'){
			k++;
			e++;
		}
		if (k < s.length()){
			s.erase(s.begin() + k);
		}
	}
	if (s.length() == 0){
		e = 0;
	}
	int num = 0;
	k = 0;
	string res;
	while (num < n){
		if (k < s.length()){
			res += s[k++];
		}
		else{
			res += '0';
		}
		num++;
	}
	return res;
}

int main(){
	string s1, s2, s3, s4;
	int n, e1 = 0, e2 = 0;
	cin >> n >> s1 >> s2;
	s3 = deal(s1, e1, n);
	s4 = deal(s2, e2, n);
	if (s3 == s4&&e1 == e2){
		cout << "YES 0." << s3 << "*10^" << e1 << endl;
	}
	else{
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
	}
	system("pause");
	return 0;
}