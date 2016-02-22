#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[10];
    for(int i=0;i<10;i++)scanf("%d",&arr[i]);
    int ls=0,rs=9,key,index,mid;
    scanf("%d",&key);
    while(ls<=rs){
        mid=(ls+rs)/2;
        if(arr[mid]>=key){
            rs=mid-1;
        }
        else ls=mid+1;
    }
    printf("%d\n",ls);
    return 0;
}
