#include <stdio.h>

int main(void) {
    int a = 5;
    int b = 100;
    int *ptr = &a;   // ptr points to a

    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);

    // Change *ptr (which currently points to a)
    *ptr = 10;
    printf("After *ptr = 10, a: %d, b: %d\n", a, b);

    // Make ptr point to b now
    ptr = &b;
    *ptr = 200;
    printf("After *ptr = 200, a: %d, b: %d\n", a, b);

    return 0;
}
