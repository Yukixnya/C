#include<stdio.h>
struct structure{
    int a;
    int b;
};
struct structure sum(int a,int b){
    struct structure num;
    num.a=a;
    num.b=b;
    a+b;
    return num;
};
int main(void){
    struct structure val={10,20};
    printf("sum = %d",sum(val.a,val.b));
}