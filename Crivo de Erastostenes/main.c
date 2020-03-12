#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "crivo.h"

int main() {

    char n_string[10];

    printf("Digite o valor de n: \n");
    scanf("%s", n_string);
    unsigned int n = (int) strtof(n_string, NULL);
    clock_t seconds = clock(NULL);
    startThePlay(n);
    printf("\n%ld", clock(NULL) - seconds);
    return 0;
}
