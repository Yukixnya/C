#include<stdio.h>

void swap(int *x, int *y) {
    int c = *x;
    *x = *y;
    *y = c;
}

// Bubble sort
void bubble(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection sort
void selection(int arr[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) { 
            swap(&arr[i], &arr[min]);
        }
    }
}

// Insertion sort
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
//quick sort
int divide(int arr[],int start,int end){
    int pivot = arr[end];
    int i = start-1;
    for(int j = start ; j <= end-1 ; j++){
        if ( arr[j] < pivot){
            ++i;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[end]); 
    return i+1;
}
void quick(int arr[], int start, int end){
    if (start >= end){
        return;
    }
    int pivot = divide(arr,start,end);
    quick(arr,start,pivot-1);
    quick(arr,pivot+1,end);
}

//merge sort
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}
void Merge(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high)/2;
        Merge(A, low, mid);
        Merge(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main(void) {
    int i;
    int arr1[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {5, 4, 3, 2, 1};
    int arr3[] = {5, 4, 3, 2, 1};
    int arr4[] = {5, 4, 3, 2, 1};
    int arr5[] = {5, 4, 3, 2, 1};

    // Bubble sort
    bubble(arr1, n);
    printf("Bubble\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Selection sort
    selection(arr2, n);
    printf("Selection\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Insertion sort
    insertion(arr3, n);
    printf("Insertion\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    //Quick
    quick(arr4,0,n-1);
    printf("Quick\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\n");

    //merge
    Merge(arr5,0,4);
    printf("Merge\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr5[i]);
    }
    printf("\n");
}