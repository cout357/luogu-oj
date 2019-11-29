#include<iostream>
#include<algorithm>

using namespace std;

int kRow[1005];
int lRow[1005];

int main(){
	int row,col,k,l,d;			//行，列，横向，纵向，说话对数 
	int x1,y1,x2,y2;
	int ks[1005],ls[1005],maxk,maxl;
	cin >> row >> col >> k >> l >> d;
	for(int i = 0;i < d;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1==x2){
			lRow[min(y1,y2)]++;
		}
		else if(y1==y2){
			kRow[min(x1,x2)]++;
		}
	}
	for(int i = 0;i < k;i++){
		maxk = 1;
		for(int j = 1;j <= row;j++){
			if(kRow[j]>kRow[maxk])maxk = j;
		}
		ks[i] = maxk;
		kRow[maxk] = 0;
	}
	for(int i = 0;i < l;i++){		//这两个排序基本一致，可以做成函数 
		maxl = 1;
		for(int j = 1;j <= col;j++){
			if(lRow[j]>lRow[maxl])maxl = j;
		}
		ls[i] = maxl;
		lRow[maxl] = 0;
	}
	sort(ks,ks+k);
	sort(ls,ls+l);
	for(int i = 0;i < k-1;i++)cout << ks[i] << " ";
	cout << ks[k-1] << endl;
	for(int i = 0;i < l-1;i++)cout << ls[i] << " ";
	cout << ls[l-1] << endl;
	
	return 0;
}
