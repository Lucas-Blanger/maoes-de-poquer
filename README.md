# Mãos de Pôquer

**Disciplina:** Estrutura de Dados  
**Aluno:** Lucas Blanger  
**Universidade:** Universidade Federal de Santa Maria  

Este projeto é um jogo de "Mãos de Pôquer" desenvolvido em C, parte de um trabalho para a disciplina de Estrutura de Dados. No jogo, o jogador deve construir cinco mãos de pôquer a partir de cartas retiradas de um baralho embaralhado. A pontuação final é calculada com base nas mãos formadas.

## Funcionalidades

- **Embaralhamento do baralho:** O baralho é embaralhado usando uma semente para garantir aleatoriedade.
- **Manipulação de pilha de descarte e pesca:** As cartas descartadas são armazenadas em uma pilha de descarte e podem ser reutilizadas quando a pilha de pesca estiver vazia.
- **Formação de Mãos de Pôquer:** O jogador pode organizar suas cartas para formar até cinco mãos de pôquer, pontuando de acordo com uma tabela de pontuação.
- **Pontuação final:** A pontuação é calculada com base nas combinações de cartas em cada mão.

## Estrutura do Código

- **Estruturas de Dados:**  
  - `LISTA_T`: Lista encadeada para armazenar as cartas da pilha de descarte e da mão.
  - `MAO_T`: Estrutura para representar cada carta.

- **Funções principais:**
  - `criaPesca`: Cria a lista de cartas a serem pescadas.
  - `iniciaJogo`: Inicia o jogo distribuindo as cartas iniciais.
  - `realizaJogada`: Realiza uma jogada, onde o jogador pode descartar ou adicionar uma carta a uma das mãos.
  - `verificaFim`: Verifica se todas as mãos estão completas.
  - `calculaPontuacao`: Calcula a pontuação final com base nas combinações de cada mão.
  - `jogar`: Função principal que controla o laço do jogo.

## Como Executar

1. Clone o repositório:
   ```bash
   git clone https://github.com/seu-usuario/maos-de-poquer.git

Compile o código:

gcc -o maosDePoquer maosPoquer.c -lm

Execute o jogo:

    ./maosDePoquer

## Instruções do Jogo

  - Inicialize o Jogo: Ao iniciar, você deve fornecer uma semente para o embaralhamento do baralho.
  - Realize Jogadas: Escolha cartas para adicionar a uma das cinco mãos ou para descartar.
  - Complete as Mãos: Quando todas as mãos estiverem completas, o jogo termina.
  - Pontuação Final: A pontuação é exibida ao final do jogo.

## Requisitos

  - Compilador C (como GCC)
  - Biblioteca maosPoquer.h (inclui definições adicionais e funções para embaralhar o baralho e pontuar mãos)

## Estrutura de Pastas

  - maosPoquer.h: Cabeçalho contendo as definições de estruturas e funções auxiliares.
  - maosPoquer.c: Código fonte principal com a lógica do jogo.
