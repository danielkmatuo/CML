#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int rows;
    double* data;
} Vector;

Vector createVector(int rows);

Vector initVector(double* data);

#endif
