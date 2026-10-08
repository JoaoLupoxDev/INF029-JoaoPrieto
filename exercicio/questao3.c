#include <stdlib.h>
#include <stdio.h>

int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    for (int i=0;texto[i] != '\0';i++){
        if (isCaseSensitive == 1){
            if (c == texto[i]){
                qtdOcorrencias++;
            }
        }else{
            if (c == texto[i] || (c-32) == texto[i]){
                qtdOcorrencias++;
            }
        }
    }

    return qtdOcorrencias;
}

int main(){

}