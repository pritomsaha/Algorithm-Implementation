#include <bits/stdc++.h>
using namespace std;
map<int,string> mp1;
map<string,int> mp2;
int numberOfnodes;
bool bfs(string nodeTosearch,vector<int> matrix[]){
	bool isVisited[numberOfnodes];
	memset(isVisited,false,sizeof(isVisited));
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		if(mp1[u]==nodeTosearch)return true;
		q.pop();
		int size=matrix[u].size();
		for(int i=0;i<size;i++){
			int v=matrix[u][i];
			if(mp1[v]==nodeTosearch)return true;
			if(!isVisited[v]){
				q.push(v);
			}
		}
		isVisited[u]=true;
	}
	return false;
}

int main(){
	
	//printf("Enter the number of nudes: ");
	scanf("%d",&numberOfnodes);
	vector<int> matrix[numberOfnodes];
	//printf("Enter the nodes: ");
	for(int i=0;i<numberOfnodes;i++){
		string node;
		cin>>node;
		mp1[i]=node;
		mp2[node]=i;
	}
	//printf("Enter the number of nodes and enter the nodes that are children of each node\n");
	for(int i=0;i<numberOfnodes;i++){
		int numOfchid;
		string child;
		scanf("%d",&numOfchid);
		while(numOfchid--){
			cin>>child;
			matrix[i].push_back(mp2[child]);
		}
	}
	string nodeTosearch;
	//printf("Enter the node to be searched: ");
	cin>>nodeTosearch;
	if(bfs(nodeTosearch,matrix)){
		cout<<nodeTosearch<<" has been found"<<endl;
	}
	else cout<<"Sorry cant find";

	return 0;
}