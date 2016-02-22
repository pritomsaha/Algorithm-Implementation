#include<bits/stdc++.h>
using namespace std;
vector<int> graph[30001];
vector<int> w[30001];
int color[30001],d[30001];
int n,Max,node;
void dfs(int u){
    int l=graph[u].size();
    color[u]=1;
    for(int i=0;i<l;i++){
        if(!color[graph[u][i]]){
            d[graph[u][i]]=d[u]+w[u][i];
            dfs(graph[u][i]);
        }
    }
    if(d[u]>Max){node=u;Max=d[u];}
}
int main(){
    int T,cse,i,u,v,wi;
    scanf("%d",&T);
    for(cse=1;cse<=T;cse++){
        scanf("%d",&n);
        for(i=0;i<n;i++){graph[i].clear();w[i].clear();}
        for(i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&wi);
            graph[u].push_back(v);
            graph[v].push_back(u);
            w[u].push_back(wi);
            w[v].push_back(wi);
        }
        memset(color,0,sizeof(color));
        Max=0;
        d[0]=0;
        dfs(0);
        memset(color,0,sizeof(color));
        Max=0;
        d[node]=0;
        dfs(node);
        printf("Case %d: %d\n",cse,Max);
    }
    return 0;
}
