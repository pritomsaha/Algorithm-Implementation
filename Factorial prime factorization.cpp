#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int flag[maxn],primes[maxn],numOfprimes;
void sieve(){
    primes[numOfprimes++]=2;
    for(int i=3;i<maxn;i+=2){
        if(!flag[i]){
            primes[numOfprimes++]=i;
            for(int j=i+i;j<maxn;j+=i)flag[j]=1;
        }
    }
}
int main(){
    sieve();
    int T,n,cse,i,sum,temp;
    scanf("%d",&T);
    for(cse=1;cse<=T;cse++){
        scanf("%d",&n);
        printf("Case %d: %d =",cse,n);
        for(i=0;n>=primes[i];i++){
            if(i!=0)printf(" *");
            sum=0;
            temp=n;
            while(temp>0){
                sum+=(temp/=primes[i]);
            }
            printf(" %d (%d)",primes[i],sum);
        }
        printf("\n");
    }
    return 0;
}
