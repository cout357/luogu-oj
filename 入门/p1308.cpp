#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

void toLower(string& str){
	for(int i = 0;str[i];i++)
		if(str[i]>=97&&str[i]<97+26)str[i]-=32;
}
int main(){
	string src;
	string str;
	string word;
	int sum(0);
	int first = -1;
	int idx = 0;
	
	cin >> src;
	getchar();
	getline(cin,str);
	toLower(str);
	toLower(src);
	
	for(int i = 0;;i++){
		if(str[i]==' '||str[i]=='\0'){
			if(src==word){
				sum++;
				if(first==-1)first = i-src.size();
			}
			word.clear();
			if(str[i]=='\0')break;
		}
		else{
			word+=str[i];
		}
	}
	if(sum)
		cout << sum << " " << first << endl;
	else
		cout << "-1" << endl;
	
	return 0;
}
