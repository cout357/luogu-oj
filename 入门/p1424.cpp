#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int x,n;
	int workday = 0;		//游泳的天数
	cin >> x >> n;
	workday+=(x+n)/7*5+((x+n)%7>5?5:(x+n)%7-1)-x+((x+n)%7==0?1:0);
	cout << workday*250 << endl;/*
	for(int i = 0;i < n;i++,x++){
		if(x==8)x=1;
		if(x==6||x==7)
			continue;
		workday++;
	}
	cout << workday*250 << endl;*/
	return 0; 
}
