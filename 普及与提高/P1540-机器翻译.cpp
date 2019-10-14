#include<iostream>
#include<queue>
using namespace std;

int seen[1005];		//����ǣ���û���ڶ����� 

int main(){
	int m,n;
	int num;
	int total = 0;		//���Ҵ��� 
	queue<int> que;
	
	cin >> m >> n;
	for(int i = 0;i < n;i++){
		cin >> num;
		if(seen[num]==0){			//����ڴ���û�иõ��� 
			total++;
			seen[num] = 1;
			if(que.size()==m){		//����ڴ����� ,�ͰѶ�ͷԪ��ɾ����������Ӧ���
				seen[que.front()] = 0;
				que.pop();
			}
			que.push(num);
		}
		
	}
	cout << total << endl;
	
	return 0;
}
