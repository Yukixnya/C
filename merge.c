///@brief merge sort
///@param merge dividing work
///@param mergesort final sorting and merging
//mergesort use of recursion
#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int low,int mid,int high){
    int* b=(int*)malloc((high-low+1)*sizeof(int));
    if (b == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    int i=low;
    int j=mid+1;
    int k=0;                            //k not be low
    while(i <= mid && j <= high)
    {
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i <= mid)
    {
        b[k++]=a[i++];
    }
    while(j <= high)
    {
        b[k++]=a[j++];
    }
    for(i=0;i<k;i++){                 //i from 0 not from low {and same goes for k}
        a[low + i] = b[i];                  //a[i] and b[i] is wrong
    }
    free(b);
}

void mergesort(int a[], int low, int high){
    if(low<high){
        int mid = (low + high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main(void){
    int arr[]={6,4,4,9,1};                     //octal constant error because of 08,09,...
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);                    //pass n-1
    printf("sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}