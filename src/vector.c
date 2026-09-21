#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/vector.h"

Vector createVector(int rows) {
    double* p = malloc(rows * sizeof(double)); 

    Vector vec;
    vec.rows = rows;
    vec.data = p;

    return vec;
}

Vector initVector(double data[], int rows) {
    Vector vec = createVector(rows); 
    
    int idx = vec.rows;

    while (idx > 0) {
        vec.data[idx - 1] = data[idx - 1];
        idx--;
    }

    return vec;
}

void freeVector(Vector* vec) {
    if (vec == NULL) {
        printf("Passed already NULL pointer");
        return;
    }

    free(vec->data);
    vec->data = NULL;

    return;
}

double innerProduct(Vector* vec1, Vector* vec2) {
    assert(vec1->rows == vec2->rows);

    double sum = 0.0; 

    int n = vec1->rows;
    int m = vec2->rows;
    
    while (n > 0 && m > 0) {
        sum += vec1->data[n - 1] * vec2->data[m - 1];
        n--;
        m--;
    }

    return sum;
}
