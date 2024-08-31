//wap to define as well as traverse the elements of an array and search a element.
#include<stdio.h>
#include<stdbool.h>
int main(void){
    int n;

    printf("enter array size : ");
    scanf("%d",&n);

    int arr[n];

    printf("enter array elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    //traverse and print
    printf("array elements are \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    //search 
    int num;
    bool a = false;
    printf("enter the srearch number\n");
    scanf("%d",&num);
    for(int i=0;i<n;i++){
        if(num==arr[i]){
            printf("element found");
            a = true;
        }
    }
    if(false){
        printf("element not found");
    }
}