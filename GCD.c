//GCD
#include<stdio.h>
int gcd(int x,int y){
    if(x%y==0){
        return y;
    }
    else{
        return gcd(y,x%y);
    }                                                                                                     
}

int GCD(int x,int y){
    int a;
    while(x!=y){
        a=x-y;
        x=y;
        y=a;
    }
    return a;
} 

int main(void){
    int x,y;
    printf("enetr numberes : \n");
    scanf("%d%d",&x,&y);
    printf("GCD is %d",gcd(x,y));
    printf("\nGCD is %d",GCD(x,y));
}