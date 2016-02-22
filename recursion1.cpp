#include <bits/stdc++.h>
using namespace std;
int arr[]={1,2,3,4,5,6,8,8,9,10};
void func(int i,int j,int num){
	if(i==j){
		if(arr[i]==num)printf("Yes\n");
		else printf("No\n");
		return;
	}
	int mid=(i+j)>>1;
	if(arr[mid]>num)func(i,mid-1,num);
	else func(mid+1,j,num);
}
int main(){
	func(0,9,7);
	return 0;
}