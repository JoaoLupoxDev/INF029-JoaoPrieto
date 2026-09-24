#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q1(char data[])
{
    int dia, mes, ano;
    int bissexto = 0;

    // 1. Extrai os dados
    int lidos = sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    if (lidos != 3){
        return 0;
    } 

    // 2. Ajusta ano com 2 dígitos
    if (ano < 100){
        ano += 2000;  
    } 

    // 3. Verifica ano bissexto PRIMEIRO
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        bissexto = 1;
    }

    // 4. Valida Mês (1 a 12)
    if (mes < 1 || mes > 12){
        return 0;
    } 

    // 5. Valida Dia (1 a 31)
    if (dia < 1 || dia > 31){
        return 0;
    } 

    // 6. Valida Fevereiro
    if (mes == 2) {
        if (bissexto == 1 && dia > 29){
            return 0;
        } 
        if (bissexto == 0 && dia > 28){
            return 0;
        } 
    }

    // 7. Valida meses com 30 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return 0;
    }

    // Se passou por tudo, a data é válida!
    return 1;
}

int main() {
    int res = q1("/9/2014");
    printf("\n>>> RESPOSTA DA QUESTAO: %d <<<\n", res);
    return 0;
}