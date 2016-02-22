#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    cout<<((int)pow(n,k-2)%k)<<endl;//a^{-1} = a^{m-2}(mod{m}).if(m==prime)

    return 0;
}
