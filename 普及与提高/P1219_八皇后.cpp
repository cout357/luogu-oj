#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#define maxn 15

using namespace std;

int n;		//棋盘大小
int map[maxn][maxn] = {0};
string num;
vector<string> res;

int func(int x){		//返回绝对值 
	return x<0?-x:x;
}
void dfs(int row,int &cnt){
	if(row == n){res.push_back(num);cnt++;return;}
	for(int col = 0;col < n;col++){
		int trow;
		for(trow = 0;trow < row;trow++){
			if(num[trow]==col||func(num[trow]-col)==func(row-trow))break;
		}
		if(trow==row){
			num+=col;
			dfs(row+1,cnt);
			num.erase(row);
		}
	}
}
int main(){
	 cin >> n;
	 int cnt = 0;
	 dfs(0,cnt);
	 for(int i = 0;i < 3;i++){
	 	for(int j = 0;j < n;j++)
	 		cout << int(res[i][j]+1) << " ";
	 	cout << endl;
	 }
	 cout << cnt << endl;	
	 
	 return 0;
}
