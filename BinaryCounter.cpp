#include<iostream>
#include<algorithm>

using namespace std;

int main(){


    string initial="00000000";
    string bin[17];
    bin[0]=initial;
    for(int i=1;i<17;i++){
        int j=0;
        while(j<8&&initial[7-j]=='1'){
            initial[7-j]='0';
            j++;
        }
        if(j<8) initial[7-j]='1';
        bin[i]=initial;

    }
    for(int i=0;i<17;i++)
        cout<<bin[i]<<endl;
    return 0;

}
