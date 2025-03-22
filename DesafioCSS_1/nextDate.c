#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehBissexto(int ano) 
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

char* NextDate(int mes, int dia, int ano) 
{
    static char data[11];
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ehBissexto(ano)) 
    {
        diasNoMes[2] = 29;
    }
    
    if (mes < 1 || mes > 12) 
    {
        return "E01";
    }
    if (ano < 1900 || ano > 2099) 
    {
        return "E03";
    }
    if (dia < 1 || dia > diasNoMes[mes]) 
    {
        return "E02";
    }

    if ((mes == 2 && dia > diasNoMes[2]) || dia > diasNoMes[mes]) 
    {
        return "E04";
    }
    
    dia++;
    if (dia > diasNoMes[mes]) 
    {
        dia = 1;
        mes++;
        if (mes > 12) 
        {
            mes = 1;
            ano++;
        }
    }
    
    snprintf(data, sizeof(data), "%02d/%02d/%04d", dia, mes, ano);
    return data;
}

int main() 
{
    int dia, mes, ano;
    printf("Digite o dia, mes e ano: ");
    scanf("%d %d %d", &dia, &mes, &ano);
    
    printf("Proxima data: %s\n", NextDate(mes, dia, ano));
    return 0;
}
