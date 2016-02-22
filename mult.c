#include<stdio.h>

int multiply(int x, int y){

    if(!y) return 0;
    int z=multiply(x,y>>1);
    if(y&1) return (x+z<<1);
    else z<<1;
}

int main(){

    printf("%d",multiply(4,3));

    return 0;
}


