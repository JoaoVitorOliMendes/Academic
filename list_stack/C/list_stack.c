#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int length;
    int* array;
};

void initializeStack(struct Stack* stack, int length) {
    stack = (struct Stack*)malloc(sizeof(*stack));
    if (!stack) {
        return;
    }
    stack->length = length;
    stack->array = (int*)malloc(stack->length * sizeof(int));
    if (!stack->array) {
        free(stack);
        return;
    }
}

int main() {
    struct Stack* stack;
    initializeStack(stack, 10);
    
    return 0;
}