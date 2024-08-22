#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double uniforme()
{
    double u = rand() / ((double)RAND_MAX + 1);
    // u == 0 -> ln(u) ?
    // limitando entre (0,1)

    u = (double)1.0 - u;

    return u;
}

int main()
{
    // Na Exponencial, o valor esperado -> E[X] = 1/l
    double l;
    printf("informe o tempo médio: ");
    scanf("%lF", &l);
    l = 1.0 / l;

    // iniciando a sequencia pseudo aleatória
    int semente = time(NULL);
    srand(semente);

    // gerando os valores

    double qtd_valor_gerados = 10000000;
    double soma = 0.0;

    for (int i = 0; i < qtd_valor_gerados; i++)
    {
        double valor = (-1.0 / l) * log(uniforme());
        soma += valor;
        printf("%lF\n", valor);
        getchar();
    }

    double media = soma / qtd_valor_gerados;

    printf("Media dos valores gerados:  %lF\n", media);

    return 0;
}