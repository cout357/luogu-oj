#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n,x,sum{0};
	cin >> n >> x;
	for(int i = 1;i <= n;i++){
		int num = i;
		while(num){
			if(x==num%10)sum++;
			num/=10;
		}
	}
	cout << sum << endl;
	
	return 0;
}
