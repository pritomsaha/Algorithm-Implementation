#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#define  Max 100

using namespace std;

bool arr[200000005];

void Sieve(long long n)
{
    arr[0]=true;
    arr[1]=true;
    arr[2]=false;

    for(long long i=4;i<=n;i=i+2)
        arr[i]=true;

    int squart = sqrt(n);

    for(long long i=3;i<=squart;i=i+2)
    {
        if(arr[i]==true) continue;

        for(long long j=i*i;j<=n;j+=i)
            arr[j]=true;

    }
}

int main()
{
    //vector<int> prime=getSieveOfEratosthenes();

    Sieve(100000000);

    for(int i=2;i<101;i++)
    {
        if(!arr[i]) cout<<i<<endl;
    }


    return 0;
}



