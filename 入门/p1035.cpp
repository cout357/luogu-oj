/*
��Ŀ����
��֪��S_n= 1+1/2+1/3+��+1/nS 
n
?	 =1+1/2+1/3+��+1/n����Ȼ��������һ������KK����nn�㹻���ʱ��S_nS 
n
?	 ����KK��

�ָ���һ������KK��1 \le k \le 151��k��15����Ҫ������һ����С��nn��ʹ��S_n>KS 
n
?	 >K��

�����ʽ
һ��������KK

�����ʽ
һ��������NN

�����������
���� #1 ����
1
��� #1 ����
2
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	double s = 0.0;
	int k,i;
	cin >> k;
	for(i = 1;s<=k;i++)
		s+=1/double(i);
	cout << i-1 << endl;
	
	return 0;
}
