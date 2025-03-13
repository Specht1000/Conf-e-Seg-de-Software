#include <stdio.h>

const char* ClassificarTriangulo(int a, int b, int c) {
    // Verifica se os valores estão dentro do intervalo permitido
    if (a < 1 || a > 200 || b < 1 || b > 200 || c < 1 || c > 200) {
        return "Valor fora do intervalo";
    }
    
    // Verifica se satisfazem a condição de existência de um triângulo
    if (a >= b + c || b >= a + c || c >= a + b) {
        return "Nao e um Triângulo";
    }
    
    // Classificação do triângulo
    if (a == b && b == c) {
        return "Equilatero";
    } else if (a == b || a == c || b == c) {
        return "Isosceles";
    } else {
        return "Escaleno";
    }
}

int main() {
    int a, b, c;
    printf("Digite os tres lados do triangulo: ");
    scanf("%d %d %d", &a, &b, &c);
    
    printf("%s\n", ClassificarTriangulo(a, b, c));
    
    return 0;
}