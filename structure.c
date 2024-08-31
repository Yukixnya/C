#include<stdio.h>
#include<string.h>
struct one{
    int a;
    struct two{
        char b[10];
    };
};
int main(void){
    struct one first;
    first.a=10;
    strcpy(first.b,"hello");
    printf("%s %d",first.b,first.a);
}