#include <stdio.h>

/*

Everyone asks What are pointers?
But the real mainngful question is
Why are pointers?
Pointers for laughing, crying, angering
Pointers for intspiring,
But lost in the void of reality
I continue to ask myself
Why do i want
To be a pointer;

*/

int main() {
    int number = 21;
    int *pNumber = &number;

    *pNumber = 22;
    
    printf("Address of number: %p\n", &number);
    printf("Value of number: %i\n", number);
    printf("Value of pNumber: %p\n", pNumber);
    printf("Value at stored address of pNumber: %i\n", *pNumber);

    return 0;
}