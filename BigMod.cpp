#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long   LL;

using namespace std;
LL bigmod(LL n, LL p) {
    if(p == 0) return 1;
    else if(p & 1) return (n * bigmod(n, p - 1)) % MOD;
    else {
        LL x = bigmod(n, p / 2);
        return (x * x) % MOD;
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    LL n,ans;
    cin>>n;
    ans=(bigmod(27, n) - bigmod(7, n)) % MOD;
    while(ans<0)ans+=MOD;
    cout<<ans<<endl;
    return 0;
}

