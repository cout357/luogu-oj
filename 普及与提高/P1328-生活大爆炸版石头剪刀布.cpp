#include<iostream>

using namespace std;

int as[205];
int bs[205];
int aScore = 0,bScore = 0;		//�÷�	
//��ӮΪ1����ӮΪ2 
int game[5][5] = {{0,2,1,1,2},{1,0,2,1,2},{2,1,0,2,1},{2,2,1,0,1},{1,1,2,2,0}};
//���ݳ�ȭ�ж�ʤ������ʤ���ӷ� 
void func(int a,int b){
	if(game[a][b]==1)aScore++;
	else if(game[a][b]==2)bScore++;
}

int main(){
	int n,al,bl;					//��ȭ����,a�ĳ�ȭ���ڣ�b�ĳ�ȭ����		
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
