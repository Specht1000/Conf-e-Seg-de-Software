#include <stdio.h>

#define PRECO_PAS 45
#define PRECO_REGADORES 30
#define PRECO_VASOS 25

float CalcularComissao(int* vendas) 
{
    int total_vendas = 0;

    for (int i = 0; vendas[i] != -1; i += 3) 
    {
        int pas = vendas[i];
        int regadores = vendas[i + 1];
        int vasos = vendas[i + 2];
        
        if (pas < 1 || pas > 70) return -1.0; 
        if (regadores < 1 || regadores > 80) return -2.0; 
        if (vasos < 1 || vasos > 90) return -3.0; 
        
        total_vendas += (pas * PRECO_PAS) + (regadores * PRECO_REGADORES) + (vasos * PRECO_VASOS);
    }

    float comissao = 0;
    if (total_vendas <= 1000) 
    {
        comissao = total_vendas * 0.10;
    } 
    else if (total_vendas <= 1800) 
    {
        comissao = (1000 * 0.10) + ((total_vendas - 1000) * 0.15);
    } 
    else 
    {
        comissao = (1000 * 0.10) + (800 * 0.15) + ((total_vendas - 1800) * 0.20);
    }
    
    return comissao;
}

int main() 
{
    int vendas[300];
    int i = 0;
    
    printf("Insira as vendas na ordem [pa, regador, vaso, pa, regador, vaso, ..., -1]:\n");
    while (1) 
    {
        scanf("%d", &vendas[i]);
        if (vendas[i] == -1) {
            vendas[i] = -1;
            break;
        }
        scanf("%d %d", &vendas[i + 1], &vendas[i + 2]);
        i += 3;
    }
    
    float comissao = CalcularComissao(vendas);
    if (comissao < 0) 
    {
        printf("Erro E0%d: Valor invalido nas vendas!\n", (int)-comissao);
    } 
    else 
    {
        printf("Comissao do vendedor: R$%.2f\n", comissao);
    }
    
    return 0;
}
