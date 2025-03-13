#include <stdio.h>

#define PRECO_PAS 45
#define PRECO_REGADORES 30
#define PRECO_VASOS 25

// Função para calcular a comissão do vendedor
float CalcularComissao(int* vendas) 
{
    int total_vendas = 0;
    
    // Processa os registros de vendas
    for (int i = 0; vendas[i] != -1; i += 3) 
    {
        if (vendas[i] == -1) break;
        
        int pas = vendas[i];
        int regadores = vendas[i + 1];
        int vasos = vendas[i + 2];
        
        // Validação das quantidades vendidas
        if (pas < 1 || pas > 70) return -1.0; // Erro E01
        if (regadores < 0 || regadores > 80) return -2.0; // Erro E02 (aceita zero agora)
        if (vasos < 1 || vasos > 90) return -3.0; // Erro E03
        
        // Calcula o valor total das vendas
        total_vendas += (pas * PRECO_PAS) + (regadores * PRECO_REGADORES) + (vasos * PRECO_VASOS);
    }
    
    // Calcula a comissão por faixas
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
    int vendas[300]; // Array para armazenar vendas
    int i = 0;
    
    printf("Insira as vendas (pas, regadores, vasos). Digite -1 para finalizar:\n");
    while (1) {
        printf("Cidade %d: ", (i / 3) + 1);
        scanf("%d", &vendas[i]);
        if (vendas[i] == -1) {
            vendas[i + 1] = -1; // Garante que a sequência termina corretamente
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
