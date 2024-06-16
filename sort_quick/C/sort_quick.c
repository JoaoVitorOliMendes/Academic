#include <stdio.h>

void quickSort(int arr[], int length, int left, int right) {
    int i, j, x, temp;

    x = arr[(left+right) / 2];
    i = left, j = right;

    do {
        while (x > arr[i]) i++;
        while (x < arr[j]) j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }while (i <= j);

    if (left < j) quickSort(arr, length, left, j);
    if (i < right) quickSort(arr, length, i, right);
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
    quickSort(arr, length, 0, (length-1));
    printf("Sorted array: \n");
    printArray(arr, length);
    return 0;
}
