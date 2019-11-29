#include<algorithm>
#include<iostream>

using namespace std;

struct Apple{
	int h,s;
}apple[5005];

bool mysort(Apple a,Apple b){
	return a.s<b.s;
}
int main(){
	int n,s;
	int a,b,h;
	int aIdx = 0;
	int total = 0;		//最终能摘到的苹果数 
	cin >> n >> s >> a >> b;
	h = a+b;
	for(int i = 0;i < n;i++){
		cin >> apple[aIdx].h >> apple[aIdx].s;
		if(apple[aIdx].h<=h)aIdx++;		//能摘到的苹果 
	}
	sort(apple,apple+aIdx,mysort);
	for(int i = 0;i < aIdx&&s>0;i++){
		if(apple[i].s<=s){
			total++;
			s-=apple[i].s;
		}
	}
	cout << total << endl;
	
	return 0;
}
