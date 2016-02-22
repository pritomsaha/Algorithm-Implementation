#include<stdio.h>

int BitCount(unsigned int u)
 {
         unsigned int uCount;

         uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
         return ((uCount + (uCount >> 3)) & 030707070707) % 63;
 }

 int main(){

    unsigned int n;
    while(scanf("%d",&n)){
        printf("%d\n",BitCount(n));
    }

 }
