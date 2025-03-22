#include <stdio.h>

const char* triangulo(int a, int b, int c) 
{
    if (a < 1 || a > 200 || b < 1 || b > 200 || c < 1 || c > 200) 
    {
        return "Valor fora do intervalo";
    }
    
    if (a >= b + c || b >= a + c || c >= a + b) 
    {
        return "Nao e um Triangulo";
    }
    
    if (a == b && b == c) 
    {
        return "Equilatero";
    } 
    else if (a == b || a == c || b == c) 
    {
        return "Isosceles";
    } 
    else 
    {
        return "Escaleno";
    }
}

int main() 
{
    int a, b, c;
    printf("Digite os tres lados do triangulo: ");
    scanf("%d %d %d", &a, &b, &c);
    
    printf("%s\n", triangulo(a, b, c));
    
    return 0;
}