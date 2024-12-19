#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a; // get the value at address a
    *a = *b;       // put the value at address b into address a
    *b = temp;      // put temp into address b
}

int main(void) {
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);

    // Pass addresses to swap function
    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}
