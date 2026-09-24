#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrix.h"

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t i32;
typedef int64_t i64;

Matrix createMatrix(size_t rows, size_t cols) {
    Matrix mat;
    mat.shape.rows = rows;
    mat.shape.cols = cols;

    return mat;
}

Matrix initMatrix(size_t rows, size_t cols, double** data) {
    Matrix mat = createMatrix(rows, cols);

    mat.data = malloc(rows * sizeof(*data));

    for (size_t i = 0;  i < rows; i++) {
        for (u32 j = 0; j < cols; j++) {
            mat.data[i][j] = data[i][j];
        }
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

    double* pRow = NULL;
    double* pCol = NULL;
    double sum = 0;

    u32 totalRows = mat1->shape.rows;
    u32 totalCols = mat2->shape.cols;

}

Matrix matSum(Matrix* mat1, Matrix* mat2) {
    u32 rows = mat1->shape.rows;
    u32 cols = mat1->shape.cols;

    double* colsP = malloc(cols * sizeof(*colsP));
    colsP = NULL;
    
    for (u32 j = 0; j < cols; j++) {
        colsP[j] = 0.0;
    }

    double** finalMatData = malloc(rows * sizeof(colsP));

    for (u32 i = 0; i < rows; i++) {
        finalMatData[i] = colsP;
    }
    
    Matrix finalMat = initMatrix(rows, cols, finalMatData);

    for (u32 i = 0; i < rows; i++) {
        for (u32 j = 0; j < cols; j++) {
            finalMat.data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }

    return finalMat;
}

Matrix vecTVecMul(Vector* vec1, Vector* vec2) {
    if (!vec2->transposed) {
        transposeVector(vec2);
    }

    u32 rows = length(vec1);
    u32 cols = length(vec2);
}
