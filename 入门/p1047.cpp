/*
题目描述
某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是11米。我们可以把马路看成一个数轴，马路的一端在数轴00的位置，另一端在LL的位置；数轴上的每个整数点，即0,1,2,…,L0,1,2,…,L，都种有一棵树。

由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多少棵树。

输入格式
第一行有22个整数L(1 \le L \le 10000)L(1≤L≤10000)和 M(1 \le M \le 100)M(1≤M≤100)，LL代表马路的长度，MM代表区域的数目，LL和MM之间用一个空格隔开。
接下来的MM行每行包含22个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。

输出格式
11个整数，表示马路上剩余的树的数目。

输入输出样例
输入 #1 复制
500 3
150 300
100 200
470 471
输出 #1 复制
298
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	int max,n,begin,end,sum{0};
	cin >> max >> n;
	char arr[max+1];
	memset(arr,1,max+1);
	for(int i = 0;i < n;i++){
		cin >> begin >> end;
		for(int j = begin;j <= end;j++)
			arr[j] = 0;
	}
	for(int i = 0;i <= max;i++)
		if(arr[i]==1)sum++;
	cout << sum << endl;
	
	return 0;
}
