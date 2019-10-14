#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int mymax;			//�洢��������� 
int seen[25];		//��¼ÿ������ʹ�ô��� 

//dfs���������ֱ��ʾ���ʿ⡢��һ��ʹ�õĵ��ʵ���������ǰ���ĳ��� 
void dfs(const vector<string> &words,int last,int tenMax){
	int add;		//�������ӳ��� 
	for(int i = 0;i < words.size();i++){
		if(seen[i]==2)continue;		//ʹ�ù����ξ������������ 
		//�Ƚ���һ�����������������û���ظ����� 
		int idx;
		for(idx = words[last].length()-1;idx>=1;idx--){
			if(words[i].length()<words[last].length()-idx)continue;
			if(words[last].substr(idx)==words[i].substr(0,words[last].length()-idx)){
				add = words[i].length()-(words[last].length()-idx);
				break;
			}
		} 
		if(idx==0)continue;		//û���ظ����־����� 
		seen[i]++;
		dfs(words,i,tenMax+add);
		seen[i]--;				//���� 
	}
	mymax = tenMax>mymax?tenMax:mymax;
}

int main(){
	vector<string> words;
	string word;
	int n;
	char head;
	cin >> n;
	//�������е��ʲ�����words�� 
	for(int i = 0;i < n;i++){
		cin >> word;
		words.push_back(word);
	}
	getchar();cin >> head;		 
	//���ΰ�ÿ�����ʵ�����ĸ��head�Ƚϣ���ͬ����Ϊ���Ŀ�ͷ��������������һ��dfs() 
	for(int i = 0;i < n;i++)
		if(words[i][0]==head){		
			seen[i]++;
			dfs(words,i,words[i].length());
			seen[i]--;
		}
	cout << mymax << endl;
	
	return 0;
}
