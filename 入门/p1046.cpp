#include<iostream>

using namespace std;

int main(){
	int sum{0},height[10],taoH;
	for(int i = 0;i < 10;i++)
		cin >> height[i];
	cin >> taoH;
	for(int i = 0;i < 10;i++)
		if(taoH+30>=height[i])sum++;
	cout << sum << endl;
	
	return 0;
}
