#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n;
	int a,b,x,y;
	int arr[100005][100005];
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d%d",&a,&b,&x,&y);
		for(int xAdd = 0;xAdd < x;xAdd++){
			for(int yAdd = 0;yAdd < y;yAdd)
				arr[a+xAdd][b+yAdd] = i;
		}
	}
	cin >> x >> y;
	cout << arr[x][y] << endl;
	
	return 0;
}
