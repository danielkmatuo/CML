#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

typedef struct {
    size_t rows;
    size_t cols;
    double** data;
} Matrix;

typedef struct {
    size_t rows;
    size_t cols;
} Shape;

Matrix createMatrix(size_t rows, size_t cols);

Matrix initMatrix(size_t rows, size_t cols, double** data);

void freeMatrix(Matrix* mat);

Shape shape(Matrix* mat);

Matrix scalarMul(double scalar, Matrix* mat);

Matrix scalarSum(double scalar, Matrix* mat);

Matrix matMul(Matrix* mat1, Matrix mat2, Shape s);

Matrix matSum(Matrix* mat1, Matrix* mat2, Shape s);

#endif
