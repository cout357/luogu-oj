#include<iostream>
#include<cstdio>
#define maxn 63000
using namespace std;

char chs[63000];
int idx;		//�洢һ����idx���ȷ� 
bool isOver(int a,int b,int num){
	int res = a<b?b-a:a-b;		//ȡ����ֵ
	if((a>=num||b>=num)&&res>=2)return true;
	return false; 
}
//����num���Ƶı��� 
void game(int num){
	int aTotal = 0,bTotal = 0;
	for(int i = 0;i < idx;i++){
		if(chs[i]=='W')aTotal++;
		else if(chs[i]=='L')bTotal++;
		if(isOver(aTotal,bTotal,num)){
			cout << aTotal << ":" << bTotal << endl;
			aTotal = 0;bTotal = 0;
		}
	}
	if(aTotal!=0||bTotal!=0)
		cout << aTotal << ":" << bTotal << endl;
}
int main(){
	char ch;
	//���ձȷ��ַ��� 
	for(int i = 0;ch!='E';i++){
		scanf("%c",&ch);
		if(ch=='W'||ch=='L'){
			chs[idx] = ch;
			idx++;
		}
	}
	//���11���ƽ��
	game(11);
	cout << endl;
	game(21);
	
	return 0;
}
