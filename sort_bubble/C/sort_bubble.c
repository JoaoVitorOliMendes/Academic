#include <stdio.h>

void bubbleSort(int arr[], int length) {
    int i, j;

    for (i = 0; i < length-1; i++) {
        for (j = 0; j < length-1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 64, 25, 12, 22, 11};
    int length = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, length);
    printf("Sorted array: \n");
    printArray(arr, length);
    return 0;
}
