#include <stdio.h>

void mergeSortMerge(int arr[], int left, int middle, int right) {
    int leftLength = (middle - left) + 1;
    int rightLength = (right - middle);

    int leftArray[leftLength], rightArray[rightLength];

    for (int i = 0; i < leftLength; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < rightLength; ++j)
        rightArray[j] = arr[(middle + j) + 1];

    int i = 0, j = 0;
    int k = left;
    while (i < leftLength && j < rightLength) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    while (i < leftLength) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightLength) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSortSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right-left) / 2;
        mergeSortSort(arr, left, middle);
        mergeSortSort(arr, middle + 1, right);
        mergeSortMerge(arr, left, middle, right);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {699, 94, 544, 646, 200, 308, 419, 778, 414, 645, 54, 33, 170, 385, 383, 374, 56, 972, 483, 467, 136, 702, 355, 861, 280, 688, 648, 692, 983, 593, 882, 180, 568, 512, 46, 747, 162, 468, 842, 785, 6, 85, 738, 26, 960, 64, 874, 196, 464, 792, 562, 745, 422, 586, 833, 492, 187, 306, 452, 775, 515, 558, 231, 834, 942, 571, 189, 438, 538, 761, 705, 105, 658, 135, 257, 389, 357, 945, 521, 14, 654, 598, 97, 405, 23, 216, 800, 776, 913, 49, 409, 607, 272, 661, 858, 395, 739, 52, 638, 862};
    int length = sizeof(arr)/sizeof(arr[0]);
    mergeSortSort(arr, 0, (length-1));
    printf("Sorted array: \n");
    printArray(arr, length);
    return 0;
}
