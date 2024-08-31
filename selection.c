///@brief selection sort
///@param swap swap function
#include<stdio.h>
void swap(int *x, int *y){
    int c=*x;
    *x=*y;
    *y=c;
}
int selection(int arr[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);      // note we gotta swap arr[i] and arr[min] not arr[j] and arr[min]
    }
}
int main(void){
    int arr[]={2,4,3,5,7,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    printf("sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}