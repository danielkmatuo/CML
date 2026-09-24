#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

#include "vector.h"

typedef struct {
    size_t rows;
    size_t cols;
} Shape;

typedef struct {
    Shape shape;
    double** data;
} Matrix;

Matrix createMatrix(size_t rows, size_t cols);

Matrix initMatrix(size_t rows, size_t cols, double** data);

void freeMatrix(Matrix* mat);

Shape shape(Matrix* mat);

void scalarMul(double scalar, Matrix* mat);

void scalarSum(double scalar, Matrix* mat);

Matrix matMul(Matrix* mat1, Matrix* mat2);

Matrix matSum(Matrix* mat1, Matrix* mat2);

Matrix vecTVecMul(Vector* vec1, Vector* vec2);

#endif
