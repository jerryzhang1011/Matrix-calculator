#define MAX_SIZE 10
#include <stdio.h>
#include "io_opers.h"
#include <string.h>

void get_matrix(int size, int matrix[MAX_SIZE][MAX_SIZE]) {
    printf("Enter the elements of the matrix:\n");
    printf("You may eperate each row by pressing ENTER\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int get_matrix_size() {
    int size;
    printf("Enter the size of the matrix (1-10): ");
    scanf("%d", &size);

    while (size < 1 || size > MAX_SIZE) {
        printf("Invalid size. Please enter a size between 1 and 10: ");
        scanf("%d", &size);
    }

    return size;
}

void matrix_mult(int size) {
    int matrix1[size][size], matrix2[size][size], result[size][size];
    int i, j, k;

    // Input the elements of first matrix
    printf("Enter elements of first matrix:\n");
    printf("Seperate each row by pressing ENTER\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input the elements of second matrix
    printf("Enter elements of second matrix:\n");
    printf("Seperate each row by pressing ENTER\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Multiply the matrices and store the result in result[][] array
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = 0;
            for (k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the result matrix
    printf("Resultant matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int calculate_determinant(int size, int matrix[MAX_SIZE][MAX_SIZE]) {
    int i, j, k, sign = 1, det = 0;
    int temp[MAX_SIZE][MAX_SIZE];

    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        for (i = 0; i < size; i++) {
            int subi = 0;

            for (j = 1; j < size; j++) {
                int subj = 0;

                for (k = 0; k < size; k++) {
                    if (k == i) {
                        continue;
                    }

                    temp[subi][subj] = matrix[j][k];
                    subj++;
                }

                subi++;
            }

            det += sign * matrix[0][i] * calculate_determinant(size - 1, temp);
            sign = -sign;
        }
    }

    return det;
}

void cal_det_io(int size) {
    int matrix[MAX_SIZE][MAX_SIZE];
    get_matrix(size, matrix);
    int determinant = calculate_determinant(size, matrix);
    printf("The determinant is %d\n", determinant);
}

void matrix_io_driver() {
    int size = -1;
    char cmd[50] = {'\0'};

    while (1) {
        printf("##########  Command List\n");
        printf("##########  \"EX\" to EXIT program\n");
        printf("##########  \"MULT\" to Multiplying matrix\n");
        printf("##########  \"DET\" to calculate Determinant of a\n");
        printf("##########  Note: Matrix Calculator can only calculate A∈nxn\n");
        printf("##########  Enter Command: ");
        int retval = scanf("%s", cmd);
        if (retval <= 0) {
            break;
        }
        if (strcmp("MULT", cmd) == 0 || strcmp("mult", cmd) == 0) {
            size = get_matrix_size();
            matrix_mult(size);
        } else if (strcmp("DET", cmd) == 0 || strcmp("det", cmd) == 0) {
            size = get_matrix_size();
            cal_det_io(size);
        } else if (strcmp("EX", cmd) == 0 || strcmp("ex", cmd) == 0) {
            printf("Successfully Exit Program!\n");
            break;
        } else {
            printf("Invalid Command Please Try Again!\n");
            continue;
        }
    }

}