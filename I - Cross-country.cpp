#include<bits/stdc++.h>
using namespace std;
int lcs[2001][2001],agnee[2001],toms[2001];
int main(){

    int test,Max,i,j;
    scanf("%d",&test);
    int len1,len2,temp;
    while(test--){
        len1=0;
        Max=0;
        while(scanf("%d",&temp)&&temp){
            agnee[len1++]=temp;
        }
        while(scanf("%d",&temp)&&temp){
            len2=0;
            toms[len2++]=temp;
            while(scanf("%d",&temp)&&temp){
                toms[len2++]=temp;
            }
            for(i=0;i<=len1;i++){
                for(j=0;j<=len2;j++){
                    if(i==0||j==0)lcs[i][j]=0;
                    else if(agnee[i-1]==toms[j-1])lcs[i][j]=lcs[i-1][j-1]+1;
                    else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
            if(lcs[len1][len2]>Max)Max=lcs[len1][len2];
        }
        printf("%d\n",Max);
    }

    return 0;
}
