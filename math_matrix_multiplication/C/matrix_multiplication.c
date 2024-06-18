
#include <stdlib.h>
#include <stdio.h>


void printMatrix(int **matrix, int sizeRows, int sizeCols) {
    for (int i=0; i < sizeRows; i++) {
        for (int j=0; j < sizeCols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int** multiply(int *rows, int *cols, int rowsA, int colsA, int rowsB, int colsB, int matrixA[rowsA][colsA], int matrixB[rowsB][colsB]) {
    int sizeK;
    if (colsA==rowsB) {
        *rows = rowsA;
        *cols = colsB;
        sizeK = colsA;
    } else if (colsB==rowsA) {
        *rows = rowsB;
        *cols = colsA;
        sizeK = colsB;
    } else {
        printf("This matrix is not multipliable.\n");
        return NULL;
    }
    
    int **matrix = (int**)malloc((*cols)*(sizeof(int*)));
    if (matrix==NULL) {
        printf("Memory not allocated.\n");
        return NULL;
    }
    for (int i=0; i<(*cols); i++) {
        matrix[i] = (int*)malloc((*rows)*(sizeof(int)));
        if (matrix[i]==NULL) {
            printf("Memory not allocated.\n");
            return NULL;
        }
    }

    for (int i=0; i < *rows; i++) {
        for (int j=0; j < *cols; j++) {
            int temp = 0;
            for (int k=0; k < sizeK; k++) {
                matrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrix;
}

int main() {
    int rows, cols;
    int matrixA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrixB[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rowsA = sizeof(matrixA) / sizeof(matrixA[0]);
    int colsA = sizeof(matrixA[0]) / sizeof(matrixA[0][0]);
    int rowsB = sizeof(matrixB) / sizeof(matrixB[0]);
    int colsB = sizeof(matrixB[0]) / sizeof(matrixB[0][0]);
    int **result = multiply(&rows, &cols, rowsA, colsA, rowsB, colsB, matrixA, matrixB);
    printMatrix(result, rows, cols);
    return 0;
}