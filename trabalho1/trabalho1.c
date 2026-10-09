// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: João Vitor Bittencourt Prieto
//  email: 20261160007@ifba.edu.br
//  Matrícula: 20261160007
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

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

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
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
      DataQuebrada dqI = quebraData(datainicial);
      DataQuebrada dqF = quebraData(datafinal);

      int diaI = dqI.iDia;
      int mesI = dqI.iMes;
      int anoI = dqI.iAno;

      int diaF = dqF.iDia;
      int mesF = dqF.iMes;
      int anoF = dqF.iAno;

      if (anoI < 100) {
          anoI = anoI + 2000;
      }
      if (anoF < 100) {
          anoF = anoF + 2000;
      }

      int dataI = anoI * 10000 + mesI * 100 + diaI;
      int dataF = anoF * 10000 + mesF * 100 + diaF;

      if (dataI > dataF) {
          dma.retorno = 4; 
          return dma;
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


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    for (int i = 0; texto[i] != '\0'; i++){
        if (isCaseSensitive == 1){
            if (c == texto[i]){
                qtdOcorrencias++;
            }
        }else{
            if (c == texto[i] || (c - 32) == texto[i] || (c + 32) == texto[i]){
                qtdOcorrencias++;
            }
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
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
            cont = 0;
            
            while (j < tam2 && strtexto[inicio + j] == strbusca[j]){
                cont++;
                j++;
            }
            
            if (cont == tam2){
                posicoes[index] = inicio + 1;
                index++;
                posicoes[index] = inicio + tam2;
                index++;
                contagemPalavras++;
            }
        }
    }
    return contagemPalavras;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

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

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

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

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[5])
{
    int i, j, k, dir;
    int tam = strlen(palavra);

    if (tam == 0) return 1;

    int d_lin[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int d_col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 10; j++) {
            for (dir = 0; dir < 8; dir++) {
                int r = i;
                int c = j;

                for (k = 0; k < tam; k++) {
                    if (r < 0 || r >= 8 || c < 0 || c >= 10) break;
                    if (matriz[r][c] != palavra[k]) break;

                    r += d_lin[dir];
                    c += d_col[dir];
                }

                if (k == tam) return 1;
            }
        }
    }

    return 0;
}

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i; 

  for (i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];	
  }
  if(i == 1 || i == 2){
    sDia[i] = '\0';
  }else {
    dq.valido = 0;
    return dq;
  }  
	

  int j = i + 1;
  i = 0;

  for (; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if(i == 1 || i == 2){
    sMes[i] = '\0';
  }else {
    dq.valido = 0;
    return dq;
  }
	

  j = j + 1;
  i = 0;
	
  for(; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if(i == 2 || i == 4){
    sAno[i] = '\0';
  }else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  dq.valido = 1;
    
  return dq;
}