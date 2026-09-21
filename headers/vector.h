#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int rows;
    double* data;
} Vector;

Vector createVector(int rows);

Vector initVector(double data[], int rows);

void freeVector(Vector* vec);

double innerProduct(Vector* vec1, Vector* vec2);

#endif
