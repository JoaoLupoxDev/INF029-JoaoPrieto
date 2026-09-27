#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questao1.h"

int q1(char data[])
{
    char sDia[3];
    char sMes[3];
    char sAno[5];
    
    int i = 0;
    int k = 0;

    while (data[i] != '/' && data[i] != '\0') {
        sDia[k] = data[i];
        i = i + 1;
        k = k + 1;
    }
    sDia[k] = '\0';

    if (data[i] == '/') {
        i = i + 1;
    }
    
    k = 0;

    while (data[i] != '/' && data[i] != '\0') {
        sMes[k] = data[i];
        i = i + 1;
        k = k + 1;
    }
    sMes[k] = '\0';

    if (data[i] == '/') {
        i = i + 1;
    }
    
    k = 0;

    while (data[i] != '\0') {
        sAno[k] = data[i];
        i = i + 1;
        k = k + 1;
    }
    sAno[k] = '\0';

    int dia = atoi(sDia);
    int mes = atoi(sMes);
    int ano = atoi(sAno);


    if (ano < 100) {
        ano = ano + 2000;
    }

    if (mes < 1 || mes > 12) {
        return 0; 
    }

    int bissexto = 0;
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        bissexto = 1;
    }

    int diasNoMes;
    if (mes == 2) {
        if (bissexto == 1) {
            diasNoMes = 29;
        } else {
            diasNoMes = 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    } else {
        diasNoMes = 31;
    }

    if (dia < 1 || dia > diasNoMes) {
        return 0; 
    }
    return 1;
}

int main() {
    int res = q1("10/9/2014");
    printf("\n>>> RESPOSTA DA QUESTAO: %d <<<\n", res);
    return 0;
}