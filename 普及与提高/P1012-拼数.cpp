#include<iostream>
#include<string>
#include<algorithm>
#define maxn 25

using namespace std;


int main(){
	string nums[maxn];
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)cin >> nums[i];
	for(int i = 0;i < n-1;i++)
		for(int j = i+1;j < n;j++) 
			if(nums[i]+nums[j]<nums[j]+nums[i])
				swap(nums[i],nums[j]);
	for(int i = 1;i < n;i++)nums[0]+=nums[i];
	cout << nums[0] << endl;
	
	return 0;
}
