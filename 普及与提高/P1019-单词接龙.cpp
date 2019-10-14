#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int mymax;			//存储龙的最长长度 
int seen[25];		//记录每个单词使用次数 

//dfs三个参数分别表示单词库、上一个使用的单词的索引、当前龙的长度 
void dfs(const vector<string> &words,int last,int tenMax){
	int add;		//龙的增加长度 
	for(int i = 0;i < words.size();i++){
		if(seen[i]==2)continue;		//使用过两次就跳过这个单词 
		//比较上一个单词与这个单词有没有重复部分 
		int idx;
		for(idx = words[last].length()-1;idx>=1;idx--){
			if(words[i].length()<words[last].length()-idx)continue;
			if(words[last].substr(idx)==words[i].substr(0,words[last].length()-idx)){
				add = words[i].length()-(words[last].length()-idx);
				break;
			}
		} 
		if(idx==0)continue;		//没有重复部分就跳过 
		seen[i]++;
		dfs(words,i,tenMax+add);
		seen[i]--;				//回溯 
	}
	mymax = tenMax>mymax?tenMax:mymax;
}

int main(){
	vector<string> words;
	string word;
	int n;
	char head;
	cin >> n;
	//接收所有单词并存入words中 
	for(int i = 0;i < n;i++){
		cin >> word;
		words.push_back(word);
	}
	getchar();cin >> head;		 
	//依次把每个单词的首字母和head比较，相同就作为龙的开头来接龙，即调用一次dfs() 
	for(int i = 0;i < n;i++)
		if(words[i][0]==head){		
			seen[i]++;
			dfs(words,i,words[i].length());
			seen[i]--;
		}
	cout << mymax << endl;
	
	return 0;
}
