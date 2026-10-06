#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "../include/vector.h"

Vector createVector(u32 len) {
    Vector vec;
    vec.len = len;

    return vec;
}

Vector initVector(double* data, u32 len) {
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

u32 length(Vector* vec) {
    return vec->len;
}

double innerProduct(Vector* vec1, Vector* vec2) {
    u32 len1 = length(vec1);
    u32 len2 = length(vec2);

    assert(len1 == len2);

    double sum = 0.0; 
    
    while (len1 > 0 && len2 > 0) {
        sum += vec1->data[len1 - 1] * vec2->data[len2 - 1];
        len1--;
        len2--;
    }

    return sum;
}

double euclideanNorm(Vector* vec) {
    double sum = 0.0;

    for (u32 i = 0; i < vec->len; i++) {
        sum += pow(vec->data[i], 2);    
    }     

    return sqrt(sum);
}

double distance(Vector* vec1, Vector* vec2) {
    assert(vec1->len == vec2->len);

    double sum = 0.0;

    for (u32 i = 0; i < vec1->len; i++) {
        double sub = vec1->data[i] - vec2->data[i];
        sum += pow(sub, 2);
    }

    return sqrt(sum);
}
