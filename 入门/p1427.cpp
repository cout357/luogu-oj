#include<iostream>
#include<list>

using namespace std;

int main(){
	list<long long> li;
	long long num;
	while(cin >> num){
		if(num == 0)break;
		li.push_front(num);
	}
	long long ba= li.back();
	li.pop_back();
	for(long long num:li)
		cout << num << " ";
	cout << ba << endl;
	
	return 0;
}
