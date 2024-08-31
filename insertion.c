///@brief insertion sort
#include<stdio.h>
void insertion(int arr[], int n) {
    int i, j, t;
    for (i = 1; i < n; i++) {
        t = arr[i];
        j = i - 1; // placing element
        while ((j >= 0) && (arr[j] > t)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = t;
    }
}

int main(void){
    int arr[]={2,4,3,5,7,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion(arr,n);
    printf("sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}