#include <stdio.h>

void insertionSort(int arr[], int length) {
    int i, j;

    for (i = 1; i < length; i++) {
        int j = i-1;
        int temp = arr[i];
        for (; j >= 0 && temp < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
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
    insertionSort(arr, length);
    printf("Sorted array: \n");
    printArray(arr, length);
    return 0;
}
