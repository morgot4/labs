#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8 

void printMatrix(int n, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matrix[MAX_SIZE][MAX_SIZE];
    FILE *file;

    file = fopen("matrix.txt", "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла matrix.txt"); 
        return EXIT_FAILURE;
    }

    if (fscanf(file, "%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Ошибка: порядок матрицы должен быть в диапазоне от 1 до %d.\n", MAX_SIZE);
        fclose(file);
        return EXIT_FAILURE;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Ошибка: файл должен содержать только целые числа.\n");
                fclose(file);
                return EXIT_FAILURE;
            }
        }
    }

    fclose(file);
    int maxLower = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) { 
            if (matrix[i][j] > maxLower) {
                maxLower = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            matrix[i][j] *= maxLower;
        }
    }

    printf("\nРезультирующая матрица:\n");
    printMatrix(n, matrix);

    return EXIT_SUCCESS;
}
