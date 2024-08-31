//Fibonacci series

#include<stdio.h>

int main(void){
    int a=0,b=1,num=4;
    for(int i=0;i<num;i++){
        int sum=a+b;
        printf("%d ",a);
        a=b;
        b=sum;
    }
}