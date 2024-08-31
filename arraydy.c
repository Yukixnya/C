#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int **arr, r, c, nr, nc, i, j;

    printf("Enter r and c: \n");
    scanf("%d %d", &r, &c);

    // Allocation
    arr = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++) {
        arr[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Enter elements:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter nr and nc: \n");
    scanf("%d %d", &nr, &nc);

    // Reallocating memory
    arr = (int **)realloc(arr, nr * sizeof(int *));
    for (i = 0; i < nr; i++) {
        arr[i] = (int *)realloc(arr[i], nc * sizeof(int));
    }
    for (i = r; i < nr; i++) {
        arr[i] = (int *)malloc(nc * sizeof(int));
    }

    // Reading additional elements
    if (nr > r) {
        printf("Enter %d additional elements:\n", (nr - r) * nc);
        for (i = r; i < nr; i++) {
            for (j = 0; j < nc; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
    }
    if (nc > c) {
        printf("Enter %d additional elements:\n", (nc - c) * nr);
        for (i = 0; i < nr; i++) {
            for (j = c; j < nc; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
    }

    // Printing the array
    printf("Array:\n");
    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Freeing memory
    for (i = 0; i < nr; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
