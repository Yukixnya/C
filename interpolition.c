///@brief interpolation search 
// same as binary search just mid formula changed
///@param mid formula of interpolation search
#include<stdio.h>
int interpol(int arr[],int n,int element){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+((element-arr[low])*(high-low)/(arr[high]-arr[low]));
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
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("[%d]",interpol(arr,n,5));
}