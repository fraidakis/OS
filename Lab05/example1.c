#include <stdio.h>

int main(void) {
    int x = 10;      // A normal integer variable
    int *p;          // p is a pointer to an integer

    p = &x;          // p now holds the address of x

    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value of p: %p\n", (void*)p);
    printf("Value pointed to by p: %d\n", *p);

    *p = 20;         // Change the value of x using the pointer
    printf("New value of x: %d\n", x);

    return 0;
}
