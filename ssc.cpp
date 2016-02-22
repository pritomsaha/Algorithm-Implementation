#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
int ft[8],dt[8];
int color[8],time;
vector<int> adj[8];

void dfs_visit(int u){

    color[u]=1;
    time++;
    dt[u]=time;
    int len=adj[u].size();
    for(int i=0;i<len;i++){
        if(color[i]==0)dfs_visit(i);
    }
    color[u]=2;
    time++;ft[u]=time;
}

int main(){

    for(int i=0;i<8;i++){
        color[i]=0;
        dt[i]=0;
        ft[i]=0;
    }




    return 0;
}
