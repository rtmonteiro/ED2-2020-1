#include <stdio.h>
#include <stdlib.h>
#include "joseph.h"

int main() {

    char n_string[10], m_string[10];

    printf("Digite a quantidade de participantes: \n");
    scanf("%s", n_string);
    int n = (int) strtof(n_string, NULL);

    printf("Digite a M-esima posicao: \n");
    scanf("%s", m_string);
    int m = (int) strtof(m_string, NULL);

    startThePlay(n, m);

    return 0;
}