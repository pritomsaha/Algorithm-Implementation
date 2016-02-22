#include<bits/stdc++.h>
#define N 100
using namespace std;
int status[(N/32)+2];
bool Check(int n,int pos){
    return (bool)(n&(1<<pos));
}
int Set(int n,int pos){	return n=n | (1<<pos);}
void sieve()
{
	 int i, j, sqrtN;
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j <= N; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }

	 puts("2");
	 for(i=3;i<=N;i+=2)
		 if( Check(status[i>>5],i&31)==0)
	 	 printf("%d\n",i);
}

int main(){
    sieve();
    //cout<<Check(status[9>>5],9&31);
    return 0;
}
