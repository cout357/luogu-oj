#include<iostream>
#include<cstdio>

using namespace std;

int map[7][7];
int n,m,t;
int bx,by,ex,ey;
int xAdd[] = {-1,0,1,0};
int yAdd[] = {0,1,0,-1};
int seen[7][7];
void dfs(int x,int y,int &sum){
	if(x == ex&&y == ey&&map[x][y]!=1){sum++;return;}		//走到终点
	//遇障碍或越界或走过 
	if(map[x][y]==1||x<1||x>n||y<1||y>m||seen[x][y])return;	
	seen[x][y] = 1;
	for(int i = 0;i < 4;i++){
		dfs(x+xAdd[i],y+yAdd[i],sum);
	} 
	seen[x][y] = 0;
}
int main(){
	int tmpx,tmpy,sum = 0;
	cin >> n >> m >> t;
	cin >> bx >> by >> ex >> ey;
	
	for(int i = 0;i < t;i++){
		cin >> tmpx >> tmpy;
		map[tmpx][tmpy] = 1;		//标记为障碍 
	}
	dfs(bx,by,sum);	
	cout << sum << endl;
		
	return 0;
}
