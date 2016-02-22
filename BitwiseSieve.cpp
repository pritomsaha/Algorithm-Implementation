#include<iostream>
#include<cstdio>
#define MAX 100000000
#define LIM 10000

using namespace std;

unsigned flag[MAX>>6]={0};
#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))         //LINE 1
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))        //LINE 2

void sieve() {
    unsigned i, j, k;
    for(i=3; i<LIM; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<LIM*LIM; j+=k)
                isc(j);
}

int main()
{
    sieve();
    for(int i=2;i<100;i++)
        if(isc(i)) cout<<i<<endl;

    return 0;
}
