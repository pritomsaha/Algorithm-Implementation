#include <bits/stdc++.h>
using namespace std;
int ans[]={4,6,2,7,3};
void sort(int arr[],int len){
	if(len==1){
		return;
	}
	int a[len/2],b[len-len/2];
	for(int i=0;i<len/2;i++)a[i]=arr[i];
	for(int i=len/2;i<len;i++)b[i-len/2]=arr[i];
	sort(a,len/2);
	sort(b,len-len/2);
	int l,m,i;
	l=m=i=0;
	while(l<len/2 && m<(len-len/2)){
		if(a[l]<b[m])ans[i++]=a[l++];
		else ans[i++]=b[m++];
	}
	while(l<len/2)ans[i++]=a[l++];
	while(m<(len-len/2))ans[i++]=b[m++];
}

int main(){
	//ans[5]={4,6,2,7};
	sort(ans,5);
	for (int i = 0; i < 5; ++i)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}