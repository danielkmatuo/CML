#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef int32_t i32;
typedef int64_t i64;
typedef uint32_t u32;
typedef uint64_t u64;

typedef struct {
    u32 len;
    double* data;
} Vector;

Vector createVector(u32 len);

Vector initVector(double* data, u32 len);

void freeVector(Vector* vec);

u32 length(Vector* vec);

double innerProduct(Vector* vec1, Vector* vec2);

double euclideanNorm(Vector* vec);

double distance(Vector* vec1, Vector* vec2);

#endif
