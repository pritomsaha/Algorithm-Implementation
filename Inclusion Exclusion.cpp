#include <bits/stdc++.h>
using namespace std;
long long LCM(long long a, long long b){
	return (a*b)/__gcd(a,b);
}
int main(){
	long long n,m,a,d,p,q,lcm,ar[5];
	int cc=(1<<5)-1,T,cnt;
	cin>>T;
	while(T--){
		cin>>n>>m>>a>>d;
		if(a==d){
			cout<<(m-n+1)-(m/a-(n-1)/a)<<endl;
			continue;
		}
		for(int i=0;i<5;i++){
			ar[i]=a+d*i;
		}
		p=m,q=--n;
		for(int i=1;i<=cc;i++){
			lcm=1ULL;cnt=0;
			for (int j=0;j<5;j++){
				if((1<<j)&i){
					lcm=LCM(lcm,ar[j]);
					cnt++;
				}
			}
			if(cnt&1){
				p-=m/lcm;
				q-=n/lcm;
			}
			else{
				p+=m/lcm;
				q+=n/lcm;	
			}
		}
		cout<<p-q<<endl;
	}
	return 0;
}