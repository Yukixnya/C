#include<stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int main(void){
    int a=10,b=32;
    printf("%d and %d",max(a,b),min(a,b));
}