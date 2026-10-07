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
    double* data;
} Matrix;

double getMatrixElem(Matrix* mat, u32 row, u32 col);

u32 getMatrixPos(Matrix* mat, u32 row, u32 col);

Matrix createMatrix(u32 rows, u32 cols);

Matrix createMatrixFromData(u32 rows, u32 cols, double* data);

void freeMatrix(Matrix* mat);

Shape shape(Matrix* mat);

void scalarMul(double scalar, Matrix* mat);

void scalarSum(double scalar, Matrix* mat);

Matrix matMul(Matrix* mat1, Matrix* mat2);

Matrix matSum(Matrix* mat1, Matrix* mat2); 

#endif
