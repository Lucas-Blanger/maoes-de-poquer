/*
Nome: Lucas Blanger
Disciplina: Estrutura de Dados
Ciência da Computação
Universidade Federal de Santa Maria
Trabalho 1 - Mãos de Pôquer
*/

#include <stdio.h>
#include <stdlib.h>
#include "maosPoquer.h"

#define CARTAS_POR_MAO 5
#define CARTAS_PESCA 30
int pontos = 0;

// Definindo a lista encadeada para pilha de descarte e mãos
typedef struct lista {
    MAO_T *carta;
    struct lista *prox;
} LISTA_T;

// Funções para a manipulação da lista
LISTA_T *criaNo(MAO_T *carta) {
    LISTA_T *novo = (LISTA_T *)malloc(sizeof(LISTA_T));
    novo->carta = carta;
    novo->prox = NULL;
    return novo;
}

void adicionaCarta(LISTA_T **lista, MAO_T *carta) {
    LISTA_T *novo = criaNo(carta);
    novo->prox = *lista;
    *lista = novo;
}

MAO_T *removeCarta(LISTA_T **lista) {
    if (*lista == NULL){
        return NULL;
    } 
    LISTA_T *temp = *lista;
    MAO_T *carta = temp->carta;
    *lista = (*lista)->prox;
    free(temp);
    return carta;
}

// Função para imprimir cartas da pilha de descarte
void imprimeLista(LISTA_T *lista) {
    LISTA_T *ptr = lista;
    while (ptr != NULL) {
        printf("[%d %d] ", ptr->carta->valor, ptr->carta->naipe);
        ptr = ptr->prox;
    }
    printf("\n");
}

// Função para imprimir uma mão
void imprimeMao(MAO_T *mao[]) {
    for (int i = 0; i < CARTAS_POR_MAO; i++) {
        if (mao[i] != NULL)
            printf("[%d %d] ", mao[i]->valor, mao[i]->naipe);
        else
            printf("[   ] ");
    }
    printf("\n");
}

// Função para criar a lista de pesca
LISTA_T *criaPesca(int baralho[][2]) {
    LISTA_T *pesca = NULL;
    for (int i = 0; i < CARTAS_PESCA; i++) {
        MAO_T *novaCarta = (MAO_T *)malloc(sizeof(MAO_T));
        novaCarta->valor = baralho[i][VALOR];
        novaCarta->naipe = baralho[i][NAIPE];
        adicionaCarta(&pesca, novaCarta);
    }
    return pesca;
}

// Função para iniciar o jogo e distribuir a mão inicial
void iniciaJogo(int baralho[][2], LISTA_T **pesca, MAO_T *maoJogo[]) {
    *pesca = criaPesca(baralho);
    for (int i = 0; i < CARTAS_POR_MAO; i++) {
        maoJogo[i] = removeCarta(pesca);
    }
}

// Exibe o estado atual do jogo
void exibeEstadoDoJogo(MAO_T *maoJogo[], LISTA_T *descarte, MAO_T *maos[5][CARTAS_POR_MAO]) {
    printf("\nMao do Jogo: ");
    imprimeMao(maoJogo);
    
    printf("\nPilha de Descarte: ");
    imprimeLista(descarte);

    for (int i = 0; i < 5; i++) {
        printf("Mao %d: ", i + 1);
        imprimeMao(maos[i]);
    }
    printf("\n");
}

//Realizar uma jogada
void realizaJogada(MAO_T *maoJogo[], LISTA_T **descarte, MAO_T *maos[5][CARTAS_POR_MAO], LISTA_T **pesca) {
    int escolhaCarta, escolhaMao;

    do {
        printf("Escolha uma carta da mao (0 a 4): ");
        scanf("%d", &escolhaCarta);
        if (escolhaCarta < 0 || escolhaCarta >= CARTAS_POR_MAO) {
            printf("Erro: Escolha invalida! Por favor, insira um numero entre 0 e 4.\n");
        }
    } while (escolhaCarta < 0 || escolhaCarta >= CARTAS_POR_MAO);

    // Verificação de entrada para escolha da mão ou descarte
    do {
        printf("Escolha uma mao (1 a 5) ou descarte (0): ");
        scanf("%d", &escolhaMao);
        if (escolhaMao < 0 || escolhaMao > 5) {
            printf("Erro: Escolha invalida! Por favor, insira um numero entre 0 e 5.\n");
        }
    } while (escolhaMao < 0 || escolhaMao > 5);

    // Adiciona a carta ao descarte ou a uma das mãos
    if (escolhaMao == 0) {
        adicionaCarta(descarte, maoJogo[escolhaCarta]);
    } else {
        for (int i = 0; i < CARTAS_POR_MAO; i++) {
            if (maos[escolhaMao - 1][i] == NULL) {
                maos[escolhaMao - 1][i] = maoJogo[escolhaCarta];
                break;
            }
        }
    }

    // Puxar nova carta da pesca ou do descarte
    if (*pesca != NULL) {
        maoJogo[escolhaCarta] = removeCarta(pesca);
    } else {
        maoJogo[escolhaCarta] = removeCarta(descarte);
    }
}

// Verificar se todas as mãos estão completas
int verificaFim(MAO_T *maos[5][CARTAS_POR_MAO]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < CARTAS_POR_MAO; j++) {
            if (maos[i][j] == NULL) {
                return 0; 
            }
        }
    }
    return 1; 
}

// Função para ordenar a mão em ordem ascendente pelo valor da carta
void ordenaMao(MAO_T *mao[]) {
    for (int i = 0; i < CARTAS_POR_MAO - 1; i++) {
        for (int j = i + 1; j < CARTAS_POR_MAO; j++) {
            if (mao[i] != NULL && mao[j] != NULL && mao[i]->valor > mao[j]->valor) {
                MAO_T *temp = mao[i];
                mao[i] = mao[j];
                mao[j] = temp;
            }
        }
    }
}

// Calcula os pontos finais do jogador
int calculaPontuacao(MAO_T *maos[5][CARTAS_POR_MAO]) {
    int pontuacaoFinal = 0;
    for (int i = 0; i < 5; i++) {
        ordenaMao(&maos[i][0]);

        MAO_T *mao = maos[i][0];
        for (int j = 1; j < CARTAS_POR_MAO; j++) {
            mao->prox = maos[i][j];
            mao = mao->prox;
        }

        pontuacaoFinal += contaPontos(*maos[i]);
    }
    return pontuacaoFinal;
}

// Função principal do jogo com o laço do jogo
void jogar(){
    int baralho[TAM_DEQUE][2];
    LISTA_T *pesca = NULL, *descarte = NULL;
    MAO_T *maoJogo[CARTAS_POR_MAO];
    MAO_T *maos[5][CARTAS_POR_MAO] = {NULL};

    unsigned int semente;
    printf("Informe a semente para embaralhar: ");
    scanf("%u", &semente);

    criaBaralho(baralho);
    embaralha(baralho, semente);
    
    iniciaJogo(baralho, &pesca, maoJogo);

    while (verificaFim(maos) == 0) {
        exibeEstadoDoJogo(maoJogo, descarte, maos);

        realizaJogada(maoJogo, &descarte, maos, &pesca);
    }
    
    int pontuacao = calculaPontuacao(maos);
    printf("\n--------------------------------\n");
    printf("\nParabéns, você chefou ao final.");
    printf("\nPontuação final: %d\n", 50);
    printf("\n--------------------------------");
}

int main() {
    jogar();
}
