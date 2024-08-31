#include<stdio.h>
struct area{
    int l;
    int b;
};
int rectangle(struct area rect){
    return rect.l*rect.b;
};
int main(void){
    struct area rect;
    rect.l=10;
    rect.b=20;
    printf("%d",rectangle(rect));
}