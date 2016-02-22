#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
        int dividend,divisor;
        int rem,quet;
        int diff;

        rem=0;
        quet=dividend;

        cin>>dividend>>divisor;

        for(int i=0;i<2; i++)
        {
                int temp=quet;
                temp>>=1;

               // cout<<temp<<endl;
                quet<<=1;
                rem<<=1;
                rem|=temp;

                diff=rem-divisor;

                if(diff<0)
                        continue;

                rem=diff;
                quet|=1;
        }

        cout<<quet<<"  "<<rem<<endl;

        return 0;
}
