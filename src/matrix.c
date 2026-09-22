#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrix.h"

Matrix createMatrix(size_t rows, size_t cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;

    return mat;
}

Matrix initMatrix(size_t rows, size_t cols, double** data) {
    Matrix mat = createMatrix(rows, cols);

    mat.data = malloc(rows * sizeof(*data));

    for (size_t i = 0;  i < rows; i++) {
        mat.data[i] = data[i];
    }

    return mat;
}

void freeMatrix(Matrix* mat) {
    if (mat == NULL) {
        printf("Passed already NULL matrix\n");
        return;
    } 

    free(mat->data);
    mat->data = NULL;

    return;
}

Shape shape(Matrix* mat) {
    Shape s;
    s.rows = mat->rows;
    s.cols = mat->cols;

    return s;
}

Matrix scalarMul(double scalar, Matrix* mat) {

}

Matrix scalarSum(double scalar, Matrix* mat) {

}

Matrix matMul(Matrix* mat1, Matrix mat2, Shape s) {

}

Matrix matSum(Matrix* mat1, Matrix* mat2, Shape s) {

}
