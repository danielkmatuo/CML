#include <assert.h>
#include <stdlib.h>

#include "../headers/vector.h"

Vector createVector(size_t len) {
    Vector vec;
    vec.len = len;
    vec.transposed = false;

    return vec;
}

Vector initVector(double* data, size_t len) {
    Vector vec = createVector(len); 
    vec.data = malloc(len * sizeof(*data));
    
    size_t idx = vec.len;

    while (idx > 0) {
        vec.data[idx - 1] = data[idx - 1];
        idx--;
    }

    return vec;
}

void freeVector(Vector* vec) {
    if (vec == NULL) {
        printf("Passed already NULL vector\n");
        return;
    }

    free(vec->data);
    vec->data = NULL;

    return;
}

size_t length(Vector* vec) {
    return vec->len;
}

void transposeVector(Vector* vec) {
    vec->transposed = true;

    return;
}

double innerProduct(Vector* vec1, Vector* vec2) {
    size_t len1 = length(vec1);
    size_t len2 = length(vec2);

    assert(len1 == len2);

    double sum = 0.0; 

    size_t n = len1;
    size_t m = len2;
    
    while (n > 0 && m > 0) {
        sum += vec1->data[n - 1] * vec2->data[m - 1];
        n--;
        m--;
    }

    return sum;
}
