#include<bits/stdc++.h>
#define maxn 1000010
using namespace std;
int primes[maxn],num[maxn],numOfprimes;
void sieve(){
    num[numOfprimes++]=2;
    for(int i=3;i<maxn;i+=2){
        if(!primes[i]){
            num[numOfprimes++]=i;
            for(int j=i+i;j<maxn;j+=i)primes[j]=1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int n,ans,c;
    while(1){
        cin>>n;
        ans=1;
        for(int i=0;i<numOfprimes&&num[i]<=sqrt(n);i++){
            if(n%num[i]==0){
                c=1;
                while(n%num[i]==0){
                    n/=num[i];
                    c++;
                }
                ans*=c;
            }
        }
        if(n>1)ans*=2;
        cout<<ans<<endl;
    }
    return 0;
}
