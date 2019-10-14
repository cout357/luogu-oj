

#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	double x;
	double sum{0},m = 2;
	int n;
	cin >> x;
	for(n = 0;sum < x;n++){
		sum+=m;
		m*=0.98;
	}
	cout << n << endl;
	
	return 0;
}
