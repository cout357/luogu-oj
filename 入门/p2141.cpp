/*
题目描述
珠心算是一种通过在脑中模拟算盘变化来完成快速运算的一种计算技术。珠心算训练，既能够开发智力，又能够为日常生活带来很多便利，因而在很多学校得到普及。

某学校的珠心算老师采用一种快速考察珠心算加法能力的测验方法。他随机生成一个正整数集合，集合中的数各不相同，然后要求学生回答：其中有多少个数，恰好等于集合中另外两个（不同的）数之和？

最近老师出了一些测验题，请你帮忙求出答案。

(本题目为2014NOIP普及T1)

输入格式
共两行，第一行包含一个整数nn，表示测试题中给出的正整数个数。

第二行有nn个正整数，每两个正整数之间用一个空格隔开，表示测试题中给出的正整数。

输出格式
一个整数，表示测验题答案。

输入输出样例
输入 #1 复制
4
1 2 3 4
输出 #1 复制
2
说明/提示
【样例说明】

由1+2=3,1+3=41+2=3,1+3=4，故满足测试要求的答案为22。

注意，加数和被加数必须是集合中的两个不同的数。

【数据说明】

对于100\%100%的数据，3 ≤ n ≤ 1003≤n≤100，测验题给出的正整数大小不超过10,00010,000。
*/ 

#include<iostream>
#include<algorithm>
 
using namespace std;

int arr[105];
//二分查找 
bool find(int begin,int end,int cNum){
	int mid;
	while(begin<=end){
		mid = (begin+end)/2;
		if(arr[mid]<cNum)
			begin = mid+1;
		else if(arr[mid]>cNum)
			end = mid-1;
		else if(arr[mid]==cNum)
			return true;
	}
	return false;
}
int main(){
	int n,sum{0};
	int cNum;
	cin >> n;	
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	
	for(int i = 2;i < n;i++){
		for(int j = 0;arr[j]*2<arr[i];j++){		//因为数字各不相同，所以循环到不小于arr[j]的1/2就终止 
			cNum = arr[i]-arr[j];
			if(find(j+1,i-1,cNum)){sum++;break;}
		}
	}
	cout << sum << endl;
	
	return 0;
}
