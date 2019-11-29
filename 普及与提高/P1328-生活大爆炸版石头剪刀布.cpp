#include<iostream>

using namespace std;

int as[205];
int bs[205];
int aScore = 0,bScore = 0;		//得分	
//甲赢为1，乙赢为2 
int game[5][5] = {{0,2,1,1,2},{1,0,2,1,2},{2,1,0,2,1},{2,2,1,0,1},{1,1,2,2,0}};
//根据出拳判断胜负并给胜方加分 
void func(int a,int b){
	if(game[a][b]==1)aScore++;
	else if(game[a][b]==2)bScore++;
}

int main(){
	int n,al,bl;					//猜拳次数,a的出拳周期，b的出拳周期		
	int aIdx = 0,bIdx = 0;
	
	cin >> n >> al >> bl;
	for(int i = 0;i < al;i++)cin >> as[i];
	for(int i = 0;i < bl;i++)cin >> bs[i];
	
	for(int i = 0;i < n;i++){
		func(as[aIdx],bs[bIdx]);
		aIdx = (aIdx+1)%al;
		bIdx = (bIdx+1)%bl;
	}
	cout << aScore << " " << bScore << endl;
	
	return 0;
}
