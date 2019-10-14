#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main(){
	string str;
	int num;
	int trueRes = 0;
	int res;
	for(int i = 1;i <= 9;i++){
		num = cin.get();
		if(num>='0'&&num<='9')num-='0';
		else num = cin.get()-'0';
		trueRes+=num*i;
	}
	trueRes%=11;
	cin.get();
	res = cin.get()-'0';
	if(trueRes==res||(trueRes==10&&res=='X'-'0'))cout << "Right" << endl;
	else cout << (trueRes==10?'X':trueRes) << endl;
	
	return 0;
}
