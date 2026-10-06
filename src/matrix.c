#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/matrix.h"

Matrix initMatrix(u32 rows, u32 cols) {
    Matrix mat;
    mat.shape.rows = rows;
    mat.shape.cols = cols;

    return mat;
}

Matrix createMatrix(u32 rows, u32 cols, double** data) {
    Matrix mat = initMatrix(rows, cols);

    mat.data = malloc(rows * cols * sizeof(**data));

    for (size_t i = 0;  i < rows; i++) {
        for (u32 j = 0; j < cols; j++) {
            mat.data[i][j] = data[i][j];
        }
    }

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
    double* pScalar = NULL;

    for (u32 i = 0; i < mat->shape.rows; i++) {
        for (u32 j = 0; j < mat->shape.cols; j++) {
            pScalar = &mat->data[i][j]; 
            *pScalar = scalar * *pScalar;
        }
    }

    return;
}

void scalarSum(double scalar, Matrix* mat) {
    double* pScalar = NULL;

    for (u32 i = 0; i < mat->shape.rows; i++) {
        for (u32 j = 0; j < mat->shape.cols; j++) {
            pScalar = &mat->data[i][j]; 
            *pScalar = scalar + *pScalar;
        }
    }

    return;
}

Matrix matMul(Matrix* mat1, Matrix* mat2) {
    assert(mat1->shape.cols == mat2->shape.rows);

    u32 totalRows = mat1->shape.rows;
    u32 totalCols = mat2->shape.cols;

    double** dataMat = malloc(totalRows * totalCols * sizeof(**dataMat));
    Matrix finalMat = createMatrix(totalRows, totalCols, dataMat);

    double* dataVecX = malloc(totalRows * sizeof(*dataVecX));
    double* dataVecY = malloc(totalCols * sizeof(*dataVecY));
    Vector vecX = initVector(dataVecX, totalCols);
    Vector vecY = initVector(dataVecY, totalRows); 

    Shape coord;
    coord.rows = 0;
    coord.cols = 0;
    
    u32* pRows = &coord.rows;
    u32* pCols = &coord.cols;

    while (coord.rows < totalRows) {
        if (*pCols > totalCols) {
            *pCols = 0;
            *pRows = *pRows + 1;
        }

        u32 temp = *pCols;

        while (*pCols < totalCols) {
            vecX.data[*pCols] = mat1->data[*pRows][*pCols];
            *pCols = *pCols + 1;
        }
        *pCols = temp;
        temp = *pRows;

        while (*pRows < totalRows) {
            vecY.data[*pRows] = mat2->data[*pRows][*pCols];
            *pRows = *pRows + 1;
        }
        *pRows = temp;

        finalMat.data[*pRows][*pCols] = innerProduct(&vecX, &vecY);

        *pCols = *pCols + 1;
    }

    freeVector(&vecX);
    freeVector(&vecY);

    return finalMat;
}

Matrix matSum(Matrix* mat1, Matrix* mat2) {
    u32 rows = mat1->shape.rows;
    u32 cols = mat1->shape.cols;

    assert(rows == mat2->shape.rows && cols == mat2->shape.cols);

    double** matData = malloc(rows * cols * sizeof(**matData));

    Matrix finalMat = createMatrix(rows, cols, matData);

    for (u32 i = 0; i < rows; i++) {
        for (u32 j = 0; j < cols; j++) {
            finalMat.data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }

    return finalMat;
}
