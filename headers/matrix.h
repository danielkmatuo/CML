#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdint.h>

#include "vector.h"

typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t i32;
typedef int64_t i64;

typedef struct {
    u32 rows;
    u32 cols;
} Shape;

typedef struct {
    Shape shape;
    double** data;
} Matrix;

Matrix createMatrix(size_t rows, size_t cols);

Matrix initMatrix(u32 rows, u32 cols, double** data);

void freeMatrix(Matrix* mat);

Shape shape(Matrix* mat);

void scalarMul(double scalar, Matrix* mat);

void scalarSum(double scalar, Matrix* mat);

Matrix matMul(Matrix* mat1, Matrix* mat2);

void matSum(Matrix* mat1, Matrix* mat2, Matrix* target); //avoid creating a new matrix for this function also

#endif
