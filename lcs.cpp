#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define FOR(i,n) for(int i=0;i<n;i++)
#define DIV 23102009

int main(){

    int t, m, n;
    char S[MAX], T[MAX];

    cin>>t;

    FOR(X,t){
        cin>>S;
        cin>>T;

        m = strlen(S);
        n = strlen(T);

        int c[m+1][n+1], count[m+1][n+1];

        FOR(i,m+1){
                c[i][0] = 0;
                count[i][0] = 1;
            }

        FOR(i,n+1){
                c[0][i] = 0;
                count[0][i] = 1;
            }


        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                    if(S[i-1]==T[j-1])
                    {
                        c[i][j] = c[i-1][j-1]+1;
                        count[i][j] = count[i-1][j-1];

                    }
                    else
                    {
                        c[i][j] = max(c[i-1][j],c[i][j-1]);
                        count[i][j] = 0;

                        if(c[i][j]==c[i-1][j]) count[i][j] = count[i][j]+ count[i-1][j];
                        if(c[i][j]==c[i][j-1]) count[i][j] = count[i][j]+ count[i][j-1];
                        if(c[i][j]==c[i-1][j-1]) count[i][j] = count[i][j] - count[i-1][j-1];
                        count[i][j] = (count[i][j]+DIV)%DIV;
                    }
            }
        }

        FOR(i,m+1){
            FOR(j,n+1) cout<<c[i][j]<<"|"<<count[i][j]<<" ";
            cout<<endl;}
        printf("%d %d\n",c[m][n],count[m][n]);
    }


}

