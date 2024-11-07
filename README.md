# Poker Hands

**Course:** Data Structures  
**Student:** Lucas Blanger  
**University:** Federal University of Santa Maria  

This project is a "Poker Hands" game developed in C, created as part of an assignment for the Data Structures course. In this game, the player must build five poker hands from cards drawn from a shuffled deck. The final score is calculated based on the hands formed.

## Features

- **Deck Shuffling:** The deck is shuffled using a seed to ensure randomness.
- **Discard and Draw Pile Management:** Discarded cards are stored in a discard pile and can be reused when the draw pile is empty.
- **Poker Hand Formation:** The player can arrange their cards to form up to five poker hands, scoring points according to a scoring table.
- **Final Score:** The score is calculated based on the card combinations in each hand.

## Code Structure

- **Data Structures:**  
  - `LISTA_T`: Linked list to store cards in the discard pile and the player’s hand.
  - `MAO_T`: Structure to represent each card.

- **Main Functions:**
  - `criaPesca`: Creates the list of cards to be drawn.
  - `iniciaJogo`: Starts the game by distributing the initial cards.
  - `realizaJogada`: Executes a move, where the player can discard or add a card to one of their hands.
  - `verificaFim`: Checks if all hands are complete.
  - `calculaPontuacao`: Calculates the final score based on the combinations in each hand.
  - `jogar`: Main function that controls the game loop.

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/Lucas-Blanger/maoes-de-poquer.git
Compile the code:

gcc -o maosDePoquer maosDePoquer.c -lm

Run the game:

    ./maosDePoquer

## Game Instructions

  - Initialize the Game: At the start, you need to provide a seed for shuffling the deck.
  - Make Moves: Choose cards to add to one of the five hands or to discard.
  - Complete the Hands: When all hands are complete, the game ends.
  - Final Score: The score is displayed at the end of the game.

## Requirements

  - C Compiler (like GCC)
  - pokerHands.h header file (includes additional definitions and functions to shuffle the deck and score hands)

## Folder Structure

   - maosPoquer.h: Header containing structure definitions and auxiliary functions.
   - maosPoquer.c: Main source code file with game logic.
