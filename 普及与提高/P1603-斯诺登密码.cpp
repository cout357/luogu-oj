#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

char numWord[20][30] = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
char inNum[6][3];
int idx;
long long mi;
//返回是单词对应数字值，如果不是数字单词就返回-1 
int isNum(const char word[]){
	for(int i = 0;i < 20;i++){
		if(strcmp(word,numWord[i])==0)return i+1;
		else if(strcmp(word,"a")==0||strcmp(word,"another")==0||strcmp(word,"first")==0)return 1;
		else if(strcmp(word,"both")==0||strcmp(word,"second")==0)return 2;
		else if(strcmp(word,"third")==0)return 3;
	}
	return -1;
}

//随机排列
void func(int begin,int end){
	char tmp[3];
	if(begin+1==end){
		long long num = 0;
		char word[20];
		for(int i = 0;i < idx;i++){
			word[i*2] = inNum[i][0];	
			word[i*2+1] = inNum[i][1];
		}
		word[idx*2] = '\0';
		for(int i = 0;i < strlen(word);i++)
			num = num*10+word[i]-'0';
		if(mi==0||mi>num)mi = num;
	}
	for(int i = begin;i<end;i++){
		strcpy(tmp,inNum[begin]);
		strcpy(inNum[begin],inNum[i]);
		strcpy(inNum[i],tmp);
		func(begin+1,end);
		strcpy(tmp,inNum[begin]);
		strcpy(inNum[begin],inNum[i]);
		strcpy(inNum[i],tmp);
	}
	
} 
int main(){
	func(0,3);
	char word[20];
	int num;
	//把数字单词以两位形式存入inNum中 
	while((cin >> word)&&strcmp(word,".")!=0){
		num = isNum(word);
		if(num!=-1){
			num = num*num%100;
			if(num<10){inNum[idx][0] = '0';inNum[idx][1] = num+'0';inNum[idx][2] = '\0';idx++;}
			else {inNum[idx][0] = num/10+'0';inNum[idx][1] = num%10+'0';inNum[idx][2] = '\0';idx++;}
		}	
	}
	//排序 
	func(0,idx);
	cout << mi << endl;
	
	return 0;
}
