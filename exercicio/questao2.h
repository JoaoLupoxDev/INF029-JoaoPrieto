#ifndef QUESTAO2_H
#define QUESTAO2_H

typedef struct {
    int retorno;
    int qtdDias;   // ou int dias; conforme definido por você
    int qtdMeses;  // ou int meses;
    int qtdAnos;   // ou int anos;
} DiasMesesAnos;

DiasMesesAnos q2(char datainicial[], char datafinal[]);

#endif