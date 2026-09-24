#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    size_t len;
    bool transposed;
    double* data;
} Vector;

Vector createVector(size_t len);

Vector initVector(double* data, size_t len);

void freeVector(Vector* vec);

size_t length(Vector* vec);

void transposeVector(Vector* vec);

double innerProduct(Vector* vec1, Vector* vec2);

#endif
