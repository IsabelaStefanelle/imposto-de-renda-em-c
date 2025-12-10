#include "imposto.h"

/*
 * Calcula o imposto de renda mensal a partir de maio de 2025,
 * usando a tabela progressiva da Receita Federal.
 */
double calcular_imposto(double renda)
{
    double imposto;

    if (renda <= 2428.80) {
        imposto = 0.0;
    } else if (renda <= 2826.65) {
        imposto = renda * 0.075 - 182.16;
    } else if (renda <= 3751.05) {
        imposto = renda * 0.15 - 394.16;
    } else if (renda <= 4664.68) {
        imposto = renda * 0.225 - 675.49;
    } else {
        imposto = renda * 0.275 - 908.73;
    }

    if (imposto < 0.0) {
        imposto = 0.0;
    }

    return imposto;
}