#include <bits/stdc++.h>
using namespace std;
long long MOD=1000000007;
const int x=3;
struct matrix{
	long long mat[x][x];
}initM,ansM;
matrix mult(matrix a,matrix b){
	int i,j,k;
	matrix ans;
	for(i=0;i<x;i++)
		for(j=0;j<x;j++){
			ans.mat[i][j]=0;
			for(k=0;k<x;k++){
				ans.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%MOD;
			}
			ans.mat[i][j]=ans.mat[i][j]%MOD;
		}
	return ans;
}
void solve(int n){
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++)ansM.mat[i][j]=0;
		ansM.mat[i][i]=1;
	}
	initM.mat[0][0]=0;
	initM.mat[0][1]=1;
	initM.mat[0][2]=0;
	initM.mat[1][0]=1;
	initM.mat[1][1]=1;
	initM.mat[1][2]=0;
	initM.mat[2][0]=0;
	initM.mat[2][1]=1;
	initM.mat[2][2]=1;
	while(n){
		if(n&1)ansM=mult(initM,ansM);
		initM=mult(initM,initM);
		n=n>>1;
	}
}
int main(){

	int n,m,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(m==0)printf("0\n");
		else if(m==1)printf("1\n");
		else{
			solve(m);
			long long ans=ansM.mat[2][1]%MOD;
			if(n>1){
				solve(n-1);
				ans-=ansM.mat[2][1]%MOD;
				ans=(ans+MOD)%MOD;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}