#include <stdio.h>
#include "imposto.h"

int main(void)
{
    double renda;
    double imposto;

    printf("Digite sua renda mensal: ");
    if (scanf("%lf", &renda) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    imposto = calcular_imposto(renda);

    printf("Imposto devido: R$ %.2f\n", imposto);

    return 0;
}