#include<iostream>
#define maxn 15

using namespace std;

int allQueen[maxn];
int a[50],b[50],c[50];			//�ֱ��ʾռ�����С������������ϡ������������¶Խ��� 
int n;			//���̴�С 
int sum;		//�ܹ��м����� 

void dfs(int row){
	if(row == n){
		if(sum++ < 3){
			for(int i = 0;i < n;i++)
				cout << allQueen[i] << " ";
			cout << endl;
		}
		return;
	}
	for(int col = 0;col < n;col++){
		if(a[col]||b[row+col]||c[row-col+n])continue;
		allQueen[row] = col+1;
		a[col] = 1;
		b[row+col] = 1;
		c[row-col+n] = 1;
		dfs(row+1);
		a[col] = 0;
		b[row+col] = 0;
		c[row-col+n] = 0;
	}
} 
int main(){
	cin >> n;
	dfs(0);
	cout << sum << endl; 
	
	return 0;
}
