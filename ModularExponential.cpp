#include<iostream>
#include<cmath>

using namespace std;

int MOD(int x, int n, int M)
{
    if(n==0) return 1;

    else if(n&1)
        return ((x%M)*MOD(x,n-1,M))%M;
    else
    {
        int y=MOD(x,n/2,M);
        return (y*y)%M;
    }

}


int main()
{

    int base,power,modulas;
    cin>>base>>power>>modulas;
    cout<<MOD(base,power,modulas);

    return 0;
}
