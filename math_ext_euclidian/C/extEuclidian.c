#include <stdio.h>

void extEuclidian(int *result, int x, int y) {
    int s = 1, ti = 1;
    int si = 0, t = 0;
    int quo = 0;

    while (y!=0) {
        quo = x / y;
        int temp = x;
        x = y;
        y = temp % y;

        temp = s;
        s = si;
        si = temp - (quo * si);

        temp = t;
        t = ti;
        ti = temp - (quo * ti);
    }

    result[0] = s;
    result[1] = t;
    result[2] = x;
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int result[3] = {0};
    extEuclidian(result, 65, 26);
    printArray(result, 3);
    return 0;
}