#include <stdio.h>

void selectionSort(int arr[], int length) {
    int i, j, min_idx;

    for (i = 0; i < length-1; i++) {
        min_idx = i;
        for (j = i+1; j < length; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if(min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
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
    int arr[] = {64, 25, 12, 22, 11};
    int length = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, length);
    printf("Sorted array: \n");
    printArray(arr, length);
    return 0;
}
