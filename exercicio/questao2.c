#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao1.h"
#include "questao2.h"

DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      int diaI = (datainicial[0] - '0') * 10 + (datainicial[1] - '0');
      int mesI = (datainicial[3] - '0') * 10 + (datainicial[4] - '0');
      int anoI = (datainicial[6] - '0') * 1000 + (datainicial[7] - '0') * 100 + (datainicial[8] - '0') * 10 + (datainicial[9] - '0');

      int diaF = (datafinal[0] - '0') * 10 + (datafinal[1] - '0');
      int mesF = (datafinal[3] - '0') * 10 + (datafinal[4] - '0');
      int anoF = (datafinal[6] - '0') * 1000 + (datafinal[7] - '0') * 100 + (datafinal[8] - '0') * 10 + (datafinal[9] - '0');
      
      int dataI = anoI * 10000 + mesI * 100 + diaI;
      int dataF = anoF * 10000 + mesF * 100 + diaF;

      if (dataI > dataF) {
          dma.retorno = 4; 
          return dma;
      } 
      
      int bissextoF = 0;
      if ((anoF % 4 == 0 && anoF % 100 != 0) || (anoF % 400 == 0)) {
        bissextoF = 1;
      }

      int bissextoI = 0;
      if ((anoI % 4 == 0 && anoI % 100 != 0) || (anoI % 400 == 0)) {
        bissextoI = 1;
      }

      int difAno = anoF - anoI;
      int difMes = mesF - mesI;
      int difDia = diaF - diaI;

      if (diaI == diaF && mesI == mesF){
        dma.qtdAnos = difAno;
        dma.qtdMeses = difMes;
        dma.qtdDias = difDia;
      }else{
        if (difDia < 0) {
            difMes--;
            
            int mesAnterior = mesF - 1;
            int anoDoMesAnterior = anoF;
            if (mesAnterior == 0) {
                mesAnterior = 12;
                anoDoMesAnterior--;
            }

            int diasNoMesAnterior;
            if (mesAnterior == 2) {
                if ((anoDoMesAnterior % 4 == 0 && anoDoMesAnterior % 100 != 0) || (anoDoMesAnterior % 400 == 0)) {
                    diasNoMesAnterior = 29;
                } else {
                    diasNoMesAnterior = 28;
                }
            } else if (mesAnterior == 4 || mesAnterior == 6 || mesAnterior == 9 || mesAnterior == 11) {
                diasNoMesAnterior = 30;
            } else {
                diasNoMesAnterior = 31;
            }

            difDia += diasNoMesAnterior;
        }

        if (difMes < 0) {
            difMes += 12;
            difAno--;
        }

        dma.qtdDias = difDia;
        dma.qtdMeses = difMes;
        dma.qtdAnos = difAno;
      }

      dma.retorno = 1;
      return dma;
    }
}

void show_log(const char *msg) {
    printf("--- %s ---\n", msg);
    fflush(stdout); // Força a impressão imediata no terminal
}

void testQ2()
{
    show_log("testQ2()");
    char datainicial[11], datafinal[11];
    DiasMesesAnos dma;

    // teste 1
    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);

    // teste 2 - retornos de erro/validação
    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 2);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 3);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 4);

    // teste 3
    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 1);
    printf("%d\n", dma.qtdMeses == 1);
    printf("%d\n", dma.qtdAnos == 0);
}

int main()
{
    testQ2();
    return 0;
}