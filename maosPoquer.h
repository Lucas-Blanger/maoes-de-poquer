/*
********************************************************************************
* Header para o problema das maos de poquer.
* Este codigo tem fins educacionais e pode conter erros. Nao ha garantias de que
* o mesmo funcione sempre como esperado.
* Versao: 0.2 antonio.candia@ufsm.br
********************************************************************************
*/
#ifndef MAOSPOQUER_H

#define TAM_DEQUE	52
#define SEMENTE		1
#define VALOR		0
#define	NAIPE		1

typedef enum {OUROS, ESPADAS, COPAS, BASTOS} NAIPES_T;

/* tipo a ser usado para as cartas */
typedef struct n {
	int valor;
	int naipe;
	struct n *prox;
} MAO_T;

void imprimeBaralhoVetor(int cartas[][2]);
void criaBaralho(int cartas[][2]);
void embaralha(int cartas[][2], unsigned int semente);
int contaPontos(MAO_T *mao);


#define MAOSPOQUER_H
#endif
