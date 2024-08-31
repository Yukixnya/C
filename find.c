#include<stdio.h>
int prime(int data){
    int c=0;
    for(int i=2;i<data;i++){
        if(data%i == 0){
            c++;
        }
    }
    if(c==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    int num,c=0;
    printf("enter a number: ");
    scanf("%d",&num);
    while(num>0){
        int r= num%10;
        num = num/10;
        if(prime(r)){
            c++;
        }
    }
    printf("total prime count is %d",c);
}