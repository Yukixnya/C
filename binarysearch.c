///@brief binary search
///@param mid exclusive for binary search
///@param m ceil can skip decimal part
#include<stdio.h>
#include<math.h>
int binary(int arr[],int n,int element){
    int low=0,high=n-1;
    while(low<=high){
        // double m=low+(double)(high-low)/2;
        // printf("\n%lf",m);
        // int mid = ceil(m);
        // printf("\n%d",mid);
        int mid = (low+high)/2;
        if(arr[mid]==element){
            printf("found at index ");
            return mid;
        }
        else if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return 0;
}
int main(void){
    int arr[]={3,6,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("[%d]",binary(arr,n,10));
}