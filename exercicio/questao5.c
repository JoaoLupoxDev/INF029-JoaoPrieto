#include <stdlib.h>
#include <stdio.h>

int q5(int num)
{
    int invertido = 0;

    while (num != 0) {
        int ultimoDigito = num % 10;
        invertido = (invertido * 10) + ultimoDigito;
        num /= 10; 
    }

    return invertido;
}

int main(){
    int num;
    printf("Digite um numero para inverte-lo: ");
    scanf("%d", &num);
    int res = q5(num);
    printf("\n%d", res);
}