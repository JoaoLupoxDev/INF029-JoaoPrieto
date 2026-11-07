#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

EstruturaPrincipal vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;   
        return retorno;
    }

    if (tamanho < 1){
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }
    
    // Corrigido para posicao - 1
    if (vetorPrincipal[posicao-1].vetorauxiliar != NULL){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    vetorPrincipal[posicao-1].vetorauxiliar = (int*) malloc(tamanho * sizeof(int));
    if (vetorPrincipal[posicao-1].vetorauxiliar == NULL){
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }

    vetorPrincipal[posicao-1].quantidade = 0;
    vetorPrincipal[posicao-1].tamanho = tamanho;
    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else
    {
        if (vetorPrincipal[posicao-1].vetorauxiliar != NULL)
        {
            if (vetorPrincipal[posicao-1].quantidade < vetorPrincipal[posicao-1].tamanho)
            {
                int quant = vetorPrincipal[posicao-1].quantidade;
                vetorPrincipal[posicao-1].vetorauxiliar[quant] = valor;
                vetorPrincipal[posicao-1].quantidade++;

                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno;

    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }    

    if (vetorPrincipal[posicao-1].vetorauxiliar == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    if (vetorPrincipal[posicao-1].quantidade == 0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    vetorPrincipal[posicao-1].quantidade--; //exclusão logica decrementando a quantidade

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno;

    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if (vetorPrincipal[posicao-1].vetorauxiliar == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    if (vetorPrincipal[posicao-1].quantidade == 0){
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    int quant = vetorPrincipal[posicao-1].quantidade;
    int validador = 0;

    for (int i=0; i<quant; i++){
        if (vetorPrincipal[posicao-1].vetorauxiliar[i] == valor){
            validador = 1;
            for (int j=i; j<quant-1; j++){
                vetorPrincipal[posicao-1].vetorauxiliar[j] = vetorPrincipal[posicao-1].vetorauxiliar[j+1];
            }

            vetorPrincipal[posicao-1].quantidade--;
            break;
        }
        
    }

    if (validador == 0){
        retorno = NUMERO_INEXISTENTE;
        return retorno;
    }



    retorno = SUCESSO;
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno;
    
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if (vetorPrincipal[posicao-1].vetorauxiliar == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    for (int i=0; i<vetorPrincipal[posicao-1].quantidade; i++){
        vetorAux[i] = vetorPrincipal[posicao-1].vetorauxiliar[i];
    }
    
    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

    // Se houve algum erro (posição inválida ou sem estrutura), retorna o erro imediatamente
    if (retorno != SUCESSO) {
        return retorno;
    }

    int quant = vetorPrincipal[posicao - 1].quantidade;

    // Ordenação (Bubble Sort) dos elementos apenas dentro do vetorAux
    for (int i = 0; i < quant - 1; i++) {
        for (int j = 0; j < quant - i - 1; j++) {
            if (vetorAux[j] > vetorAux[j + 1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = temp;
            }
        }
    }

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno, vazios=0;

    for (int i=0; i<10; i++){
        if (vetorPrincipal[i].quantidade == 0 || vetorPrincipal[i].vetorauxiliar == NULL){
            vazios++;
        }
    }
    
    if (vazios == 10){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    }

    int indiceAux=0;

    for (int i=0; i<10; i++){
        for (int j=0; j<vetorPrincipal[i].quantidade; j++){
            if (vetorPrincipal[i].vetorauxiliar != NULL){
                vetorAux[indiceAux] = vetorPrincipal[i].vetorauxiliar[j];
                indiceAux++;
            }
        }
    }
    
    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno;

    if (getDadosDeTodasEstruturasAuxiliares(vetorAux) == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS){
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    }

    int totalelementos=0;

    for (int i=0; i<10; i++){
        if (vetorPrincipal[i].vetorauxiliar != NULL){
            totalelementos += vetorPrincipal[i].quantidade;
        }   
    }

    for (int i=0; i<totalelementos-1; i++){
        for (int j=0; j<totalelementos-i-1; j++){
            if (vetorAux[j] > vetorAux[j+1]){
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            }
        }
    }

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno;

    if (posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao-1].vetorauxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int novoTamanhoFinal = vetorPrincipal[posicao-1].tamanho + novoTamanho;

    // Corrigido para < 1 (o tamanho mínimo é 1)
    if (novoTamanhoFinal < 1){
        return NOVO_TAMANHO_INVALIDO;
    }

    int *realocar = (int*) realloc(vetorPrincipal[posicao-1].vetorauxiliar, novoTamanhoFinal * sizeof(int));

    if (realocar == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao-1].vetorauxiliar = realocar;
    vetorPrincipal[posicao-1].tamanho = novoTamanhoFinal;

    if (vetorPrincipal[posicao-1].quantidade > novoTamanhoFinal){
        vetorPrincipal[posicao-1].quantidade = novoTamanhoFinal;
    }

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno;

    if (posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[posicao-1].vetorauxiliar == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (vetorPrincipal[posicao-1].quantidade == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int quantidade = vetorPrincipal[posicao-1].quantidade;

    return quantidade;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    // Aloca o nó cabeçote
    No *cabecote = (No *) malloc(sizeof(No));
    if (cabecote == NULL) {
        return NULL;
    }
    cabecote->prox = NULL;

    No *ultimo = cabecote;
    int possuiElementos = 0;

    // Percorre todas as estruturas do vetorPrincipal
    for (int i = 0; i < 10; i++) {
        if (vetorPrincipal[i].vetorauxiliar != NULL) {
            for (int j = 0; j < vetorPrincipal[i].quantidade; j++) {
                // Criar novo nó para o elemento
                No *novo = (No *) malloc(sizeof(No));
                if (novo != NULL) {
                    novo->conteudo = vetorPrincipal[i].vetorauxiliar[j];
                    novo->prox = NULL;

                    // Encadeia no final da lista
                    ultimo->prox = novo;
                    ultimo = novo;

                    possuiElementos = 1;
                }
            }
        }
    }

    // Se nenhuma estrutura tinha números, libera o cabeçote e retorna NULL
    if (!possuiElementos) {
        free(cabecote);
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    if (inicio == NULL) {
        return;
    }

    int i = 0;
    // Pula o nó cabeçote e começa a leitura do primeiro nó de dados
    No *atual = inicio->prox;

    while (atual != NULL) {
        vetorAux[i] = atual->conteudo;
        i++;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    if (inicio == NULL || *inicio == NULL) {
        return;
    }

    No *atual = *inicio;
    No *proximo = NULL;

    // Percorre a lista liberando nó por nó (incluindo o cabeçote)
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    // Faz o ponteiro original apontar para NULL
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i].vetorauxiliar = NULL;
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].quantidade = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetorauxiliar != NULL) {
            free(vetorPrincipal[i].vetorauxiliar);
            vetorPrincipal[i].vetorauxiliar = NULL;
            vetorPrincipal[i].tamanho = 0;
            vetorPrincipal[i].quantidade = 0;
        }
    }
} 
