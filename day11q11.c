#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    // Read rows and columns
    scanf("%d %d", &m, &n);

    // Allocate memory for matrices
    int **matrix1 = (int **)malloc(m * sizeof(int *));
    int **matrix2 = (int **)malloc(m * sizeof(int *));
    int **result  = (int **)malloc(m * sizeof(int *));

    for(int i = 0; i < m; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
        matrix2[i] = (int *)malloc(n * sizeof(int));
        result[i]  = (int *)malloc(n * sizeof(int));
    }

    // Read first matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Read second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Add matrices
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print result matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", result[i][j]);
            if(j < n - 1)
                printf(" ");
        }
        printf("\n");
    }

    // Free allocated memory
    for(int i = 0; i < m; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
