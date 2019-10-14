#include<iostream>
#include<queue>
using namespace std;

int seen[1005];		//做标记，有没有在队列中 

int main(){
	int m,n;
	int num;
	int total = 0;		//查找次数 
	queue<int> que;
	
	cin >> m >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		if(seen[num]==0){			//如果内存中没有该单词 
			total++;
			seen[num] = 1;
			if(que.size()==m){		//如果内存已满 ,就把队头元素删除并消除相应标记
				seen[que.front()] = 0;
				que.pop();
			}
			que.push(num);
		}
		
	}
	cout << total << endl;
	
	return 0;
}
