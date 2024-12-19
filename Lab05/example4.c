#include <stdio.h>

int main(void) {
    int x = 10;
    int y = 20;

    // Pointer to a constant integer (the integer value cannot be changed through this pointer)
    const int *ptr1 = &x;
    // *ptr1 = 15; // Error: cannot modify the value through ptr1
    ptr1 = &y;      // But ptr1 can point to a different variable

    // Constant pointer to an integer (pointer cannot change what it points to)
    int * const ptr2 = &x;
    *ptr2 = 30;      // Allowed: we can change the value
    // ptr2 = &y;    // Error: cannot change the pointer’s target

    return 0;
}
