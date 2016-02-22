

#include<bits/stdc++.h>

using namespace std;
struct vertex{

    string name;
    int distance;
    string prev;

};

int main(){

    int w[5][5];
    int i,j,k;
    vertex vertics[5];

    for(i=0;i<5;i++){
        cin>>vertics[i].name;
        //scanf("%s",&vertics[i].name);
        for(j=0;j<5;j++)
            cin>>w[i][j];
            //scanf("%d",&w[i][i]);
    }

    for(i=0;i<5;i++){
       vertics[i].distance=9999999;
       vertics[i].prev="nil";
    }
    string source;
    printf("what is the source vertex?\n");
    scanf("%s",&source);

    for(i=0;i<5;i++)
        if(vertics[i].name==source){
            vertics[i].distance=0;
            break;
        }

    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            for(k=0;k<5;k++)
            if(w[j][k]!=0&&vertics[k].distance>(vertics[j].distance+w[j][k])){
                vertics[k].distance=vertics[j].distance+w[j][k];
                vertics[k].prev=vertics[j].name;
            }
    for(i=0;i<5;i++) cout<<vertics[i].name<<" "<<vertics[i].distance<<"\n";
        //printf("%s %d\n",vertics[i].name,vertics[i].distance);

    return 0;
}
