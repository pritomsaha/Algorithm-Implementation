#include <bits/stdc++.h>
using namespace std;
char arr[50];
vector<char>result;
int taken[50],n,l;
void call(int start){
	if(result.size()==n){
		for(int i=0;i<n;i++)
			printf("%c",result[i]);
		puts("");return;
	}
	for(int i=start;i<l;i++){
		if(taken[i]==0){
			taken[i]=1; result.push_back(arr[i]);
			call(i+1);
			taken[i]=0; result.pop_back();
		}
	}
}
int main(){
	while(scanf("%s%d",arr,&n)){
		memset(taken,0,sizeof(taken));
		l=strlen(arr);
		call(0);
	}
}