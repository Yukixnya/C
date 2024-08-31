#include<stdio.h>
struct{
    int a:3;
    char b:1;
}no1;
union {
    int a:3;
    char b:1;
}no2;

int main(void){
    printf("Size of structure is %d bytes",sizeof(no1));
    printf("\nSize of union is %d bytes",sizeof(no2));

//    int arr[5]={1,2,3,4,5};
//    int size=sizeof(arr)/sizeof(int);
//    for(int i=0;i<size;i++){
//        printf("\naddress of arr[%d] is %d",i, 0x1000 + (i*sizeof(int)));
//    }

    // int arr[2][3][3]={
    //     {
    //         {1,2,3},
    //         {4,5,6},
    //         {7,8,9}
    //     },
    //     {
    //         {9,8,7},
    //         {6,5,4},
    //         {3,2,1}
    //     }
    // };
    // printf("\nelements\n");
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<3;j++){
    //         for(int k=0;k<3;k++){
    //             printf("%d ",arr[i][j][k]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }


    

}

