/**
 * !Creates a simple C program that implements a function called add() and takes
 * !in 3 integers and returns their sum. The integers should be passed by reference.
 */

#include <stdio.h>

int add(int *a, int *b, int *c)
{
    return *a + *b + *c;
}

int main()
{
    int x = 25, y = 12, z = 2024;

    // printf("Enter three numbers: ");
    // scanf("%d %d %d", &x, &y, &z);

    int sum = add(&x, &y, &z); // Pass by reference

    printf("\nResult : %d + %d + %d = %d\n", x, y, z, sum);
    return 0;
}
