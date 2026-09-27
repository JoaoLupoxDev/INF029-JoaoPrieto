#include <stdio.h>
#include <stdlib.h>

int q6(int numerobase, int numerobusca){
    int tambase=10, contbase=0, tambusca=10, contbusca=0;
    while (numerobase > tambase){
        tambase *= 10;
        contbase++;
    }
    contbase++;

    while (numerobusca > tambusca){
        tambusca *= 10;
        contbusca++;
    }
    contbusca++;

    int vetorbase[contbase];
    int div=10, calc, divsec=1;
    for (int i=contbase-1;i>-1;i--){
        calc = numerobase % div;
        calc /= divsec;
        vetorbase[i] = calc;
        div *= 10;
        divsec *= 10;
    }

    div=10;
    divsec=1;

    int vetorbusca[contbusca];
    for (int i=contbusca-1;i>-1;i--){
        calc = numerobusca % div;
        calc /= divsec;
        vetorbusca[i] = calc;
        div *= 10;
        divsec *= 10;
    }

    int qtdOcorrencias=0, cont=0, j=0, temp;
    for (int i=0;i<contbase;i++){
        if (vetorbase[i] == vetorbusca[0]){
            temp = i;
            for (int j=0;vetorbase[i] == vetorbusca[j] && j<contbusca;j++){
                cont++;
                i++;
                if (cont == contbusca){
                    qtdOcorrencias++;
                    cont=0;
                }
            }
            i = temp;
        }
    }

    return qtdOcorrencias;
}

int main(){
    int res = q6(3539343, 39);
    printf(" A quantidade de ocorrencias foi de %d vezes", res);
}