#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int price = 19;		//��λ��
	int a,total;
	cin >> a >>total;
	total+=a*10;
	a = total/price;
	cout << a << endl; 
	
	return 0;
} 
