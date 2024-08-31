//Factorial
#include<stdio.h>

int factorial(int x){
    if(x==0){
        return 1;
    }
    return factorial(x-1)*x;
}
int main(void){
    int num;
    printf("enter a number: ");
    scanf("%d",&num);
    printf("factorial is %d",factorial(num));
}