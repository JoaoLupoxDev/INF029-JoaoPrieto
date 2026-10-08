#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int q4(char *strtexto, char *strbusca, int posicoes[30]){
    int tam1 = strlen(strtexto);
    int tam2 = strlen(strbusca);
    int cont = 0;
    int index = 0;
    int contagemPalavras = 0;

    for (int i = 0; i < tam1; i++){
        if (strtexto[i] == strbusca[0]){
            int inicio = i;
            int j = 0;
            cont = 0; // Zera a contagem para cada nova tentativa
            
            // Avança no texto e na busca simultaneamente enquanto forem iguais
            while (j < tam2 && strtexto[inicio + j] == strbusca[j]){
                cont++;
                j++;
            }
            
            if (cont == tam2){
                posicoes[index] = inicio + 1;             // Posição inicial (base 1)
                index++;
                posicoes[index] = inicio + tam2;         // Posição final (base 1)
                index++;
                contagemPalavras++;
            }
        }
    }
    return contagemPalavras;
}

int main(){
    char texto[250];
    char busca[50];

    int posicoes[30];

    texto[strcspn(texto, "\r\n")] = '\0';
    busca[strcspn(busca, "\r\n")] = '\0';
    

    strcpy(texto, "Laboratorio de programacao: para ratos de programação");
    strcpy(busca, "rato");
    printf("%d\n", q4(texto, busca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);

    return 0;
}