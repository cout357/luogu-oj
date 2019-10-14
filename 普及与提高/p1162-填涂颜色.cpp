#include<iostream>
#include<queue>
#define maxn 35
using namespace std;

int n;
int map[maxn][maxn];
int check[maxn][maxn] = {0};

struct Point{
	int x,y;
};

bool bfs(int i,int j){
	queue<Point> que;
	que.push({i,j});
	check[i][j] = 1;
	while(!que.empty()){
		for(int iAdd = -1;iAdd<=1;iAdd++)
			for(int jAdd = -1;jAdd<=1;jAdd++){
				if(iAdd==0||jAdd==0){
					Point tmp = que.front();
					tmp.x+=iAdd;tmp.y+=jAdd;
					//越界说明不是在圈内 
					if(tmp.x<0||tmp.x>=n||tmp.y<0||tmp.y>=n)return false;
					//如果是加入过的点或是围墙，则不加入队列 
					else if(check[tmp.x][tmp.y]==1||map[tmp.x][tmp.y]==1)continue;
					que.push({tmp.x,tmp.y});
					check[tmp.x][tmp.y] = 1; 
				}
			}
		que.pop();
	}
	//如果队列为空了，说明初始点是在围墙内 
	return true;
}
int main(){
	cin >> n;
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> map[i][j];
	//bfs
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if(check[i][j]==0&&map[i][j]==0)
				if(bfs(i,j)){
					queue<Point> que;
					que.push({i,j});
					map[i][j] = 2;
					while(!que.empty()){
						for(int iAdd = -1;iAdd<=1;iAdd++)
							for(int jAdd = -1;jAdd<=1;jAdd++){
								if(iAdd==0||jAdd==0){
									Point tmp = que.front();
									tmp.x+=iAdd;tmp.y+=jAdd;
									if(map[tmp.x][tmp.y]==2||map[tmp.x][tmp.y]==1)continue;
									que.push({tmp.x,tmp.y});
									map[tmp.x][tmp.y] = 2;
								}
								
							}
						que.pop();
					}
					//打印结果 
					for(int i = 0;i < n;i++){
						for(int j = 0;j < n;j++)
								cout << map[i][j] << " ";
						cout << endl;
					}
					return 0; 
				};
	
	return 0;
}
