#include<iostream>
#include<cstdio>
#define maxn 10005
using namespace std;

struct Plane{
	int x,y,xadd,yadd;
};
Plane ns[maxn];

int main(){
	int n;
	int endx,endy;
	int res = -1;
	cin >> n;
	
	for(int i = 1;i <= n;i++){
		cin >> ns[i].x >> ns[i].y >> ns[i].xadd >> ns[i].yadd;
 	} 
 	cin >> endx >> endy;
 	for(int i = 1;i <= n;i++){
 		if(ns[i].x<=endx&&ns[i].y<=endy&&ns[i].x+ns[i].xadd>=endx&&ns[i].y+ns[i].yadd>=endy)
 			res = i;
 	}
 	cout << res << endl;
 	
 	return 0;
}
