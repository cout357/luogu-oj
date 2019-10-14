#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int total = 0;			//年末到手的钱
	int hand = 0;			//手上的钱 
	int thing;		//预算 
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
