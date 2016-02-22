#include <bits/stdc++.h>
using namespace std;
int n=7,value[]={-100000,5,0,9,2,7,3,4},dp[8];
int dir[8];
int longest(int u){

	if(dp[u]!=-1)return dp[u];
	int maxi=0;
	for(int i=u+1;i<=n;i++){
		if(value[i]>value[u]){
			int dis=longest(i);
			if(dis>maxi){
				maxi=dis;
				dir[u]=i;
			}
		}
	}
	return dp[u]=1+maxi;
}
int main(){
	memset(dp,-1,sizeof(dp));
	memset(dir,-1,sizeof(dir));
	int lis=0,start,numofLis=1;
	for(int i=1;i<=n;i++){
		int dis=longest(i);
		if(dis==lis)numofLis++;
		if(dis>lis){
			lis=dis;
			start=i;
			numofLis=1;
		}
	}
	printf("%d %d %d\n",start,lis,numofLis);
	while(start!=-1){
		printf("%d ", value[start]);
		start=dir[start];
	}

	return 0;
}