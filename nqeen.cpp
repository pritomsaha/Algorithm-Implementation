#include <bits/stdc++.h>
using namespace std;
int size,result[100];
bool canPlace(int x,int y){
	for(int i=0;i<x;i++){
		if(result[i]==y||(abs(i-x)==abs(result[i]-y)))return false;
	}
	return true;
}
void placeQueen(int x){
	for(int i=0;i<size;i++){
		if(canPlace(x,i)){
			result[x]=i;
			if(x==size-1){
				for(int j=0;j<size;j++)printf("%d ",result[j]);
				printf("\n");
			}
			placeQueen(x+1);
		}
	}
}
int main(){
	size=8;
	placeQueen(0);
	return 0;
}