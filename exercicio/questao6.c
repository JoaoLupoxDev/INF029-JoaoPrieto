#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int q6(int numerobase, int numerobusca) {
    if (numerobase < 0){
        numerobase = -numerobase;
    } 
    if (numerobusca < 0){
        numerobusca = -numerobusca;
    } 

    int multiplicador = 1;
    int temp = numerobusca;
    
    do {
        multiplicador *= 10;
        temp /= 10;
    } while (temp > 0);

    int qtdOcorrencias = 0;

    while (numerobase >= numerobusca) {

        if (numerobase % multiplicador == numerobusca) {
            qtdOcorrencias++;
        }
        numerobase /= 10; 
    }

    return qtdOcorrencias;
}

int main(){
    int res = q6(3393939, 39);
    printf(" A quantidade de ocorrencias foi de %d vezes", res);
}