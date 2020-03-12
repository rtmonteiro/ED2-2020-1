//
// Created by Pichau on 12/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "crivo.h"



int *createListNumbers(int n) {
    int *vec = (int *) malloc(sizeof(int) * (n-1));

    return vec;
}

void printThePrimeNumbers(int *vec, int n) {
    for (int i = 0; i <= n - 2; ++i) {
        if (vec[i] != 1) {
            printf("%d ", i + 2);
        }
    }
}

int *travelTheArray(int *vec, int n) {
    int i, j;
    for (i = 2; i <= n; ++i) {
        for (j = i; i*j <= n; ++j) {
            vec[i*j - 2] = 1;
        }
        if (i == j) break;
    }
    return vec;
}

void startThePlay(unsigned int n) {
    int *vec = createListNumbers(n);

    vec = travelTheArray(vec, n);

    printThePrimeNumbers(vec, n);

    free(vec);
}