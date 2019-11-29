#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> stds;		//范文 
vector<string> ins;			//输入 
int main(){
	string tmp;		//输入的单行
	long long n = 0;
	int line = 0;
	int time;
	double res;		//平局每分钟打字个数 
	while(getline(cin,tmp)&&tmp!="EOF"){
		stds.push_back(tmp);
		line++;
	} 
	while(getline(cin,tmp)&&tmp!="EOF"){
		for(int i = 0;i < tmp.length();i++){
			if(tmp[i]=='<'){
				string t;
				if(i==0){
					t = tmp.substr(1);
					tmp.clear();
					tmp = t;
					i-=1;
				}
				else{
					t = tmp.substr(0,i-1);
					t+=tmp.substr(i+1);
					tmp = t;
					i-=2;
				}
				
			}
		}
		ins.push_back(tmp);
	}
	for(int i = 0;i < line;i++){
		for(int idx = 0;idx < stds[i].length()&&idx < ins[i].length();idx++)
			if(stds[i].at(idx)==ins[i].at(idx))n++;
	}
	cin >> time;
	res = n*1.0/time*60;
	cout << (res-int(res)<0.5?int(res):int(res+1)) << endl;
	
	return 0;
}
