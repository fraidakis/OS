#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int)); // allocate array of 5 integers

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize and print the dynamic array
    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr); // free the allocated memory
    return 0;
}
