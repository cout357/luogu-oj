#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int total = 0;			//��ĩ���ֵ�Ǯ
	int hand = 0;			//���ϵ�Ǯ 
	int thing;		//Ԥ�� 
	int month = 0;
	for(int i = 1;i <= 12;i++){
		cin >> thing;
		if(hand+300<thing)
			month = month==0?i:month;
		total+=(hand+300-thing)/100*100;
		hand = (hand+300-thing)%100;
	} 
	cout << (month==0?total*1.2+hand:month*-1) << endl;
	
	return 0;
}
