#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/matrix.h"

double getMatrixElem(Matrix* mat, u32 row, u32 col) {
    return mat->data[row * mat->shape.cols + col];
}

u32 getMatrixPos(Matrix* mat, u32 row, u32 col) {
    return row * mat->shape.cols + col;
}

Matrix createMatrix(u32 rows, u32 cols) {
    double* matData = calloc(rows * cols, sizeof(*matData));

    Matrix mat;
    mat.shape.rows = rows;
    mat.shape.cols = cols;
    mat.data = matData;

    return mat;
}

Matrix createMatrixFromData(u32 rows, u32 cols, double* data) {
    Matrix mat;
    mat.shape.rows = rows;
    mat.shape.cols = cols;
    mat.data = data;

    return mat;
}

void freeMatrix(Matrix* mat) {
    if (mat == NULL) {
        printf("Passed NULL matrix\n");
        return;
    } 

    free(mat->data);
    mat->data = NULL;

    return;
}

Shape shape(Matrix* mat) {
    Shape s;
    s.rows = mat->shape.rows;
    s.cols = mat->shape.cols;

    return s;
}

void scalarMul(double scalar, Matrix* mat) {
    for (u32 i = 0; i < mat->shape.rows; i++) {
        for (u32 j = 0; j < mat->shape.cols; j++) {
            u32 idx = getMatrixPos(mat, i, j);
            mat->data[idx] *= scalar;
        }
    }

    return;
}

void scalarSum(double scalar, Matrix* mat) {
    for (u32 i = 0; i < mat->shape.rows; i++) {
        for (u32 j = 0; j < mat->shape.cols; j++) {
            u32 idx = getMatrixPos(mat, i, j);
            mat->data[idx] += scalar;
        }
    }

    return;
}

//TODO: Find a way to do this using only for loops and indexes i, j and k
Matrix matMul(Matrix* mat1, Matrix* mat2) { 
    assert(mat1->shape.cols == mat2->shape.rows);

    u32 totalRows = mat1->shape.rows;
    u32 totalCols = mat2->shape.cols;

    Matrix finalMat = createMatrix(totalRows, totalCols);

    Vector vecX = createVector(totalRows);
    Vector vecY = createVector(totalCols);

    return finalMat;
}

Matrix matSum(Matrix* mat1, Matrix* mat2) {
    u32 rows = mat1->shape.rows;
    u32 cols = mat1->shape.cols;

    assert(rows == mat2->shape.rows && cols == mat2->shape.cols);

    double** matData = malloc(rows * cols * sizeof(**matData));

    Matrix finalMat = createMatrix(rows, cols);

    for (u32 i = 0; i < rows; i++) {
        for (u32 j = 0; j < cols; j++) {
            u32 idx = getMatrixPos(&finalMat, i, j);
            finalMat.data[idx] = mat1->data[idx] + mat2->data[idx];
        }
    }

    return finalMat;
}
