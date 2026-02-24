# Tic Tac Toe in C: PROTOTYPE & REFACTORED VERSION

This project is a console based Tic Tac Toe game in C, featuring multiplayer mode and single player mode with two difficulty levels: 
- Easy Mode: AI just randomly selects a position for its turn without any planning
- Hard Mode: AI uses Minimax algorithm and selects the best position to win in the shortest number of turns possible

I originally built this based on the fundamentals of C (without arrays), the prototype is saved in the **Prototype** folder. I used to struggle with recursion so I challenged myself to improve the prototype using the Minimax algorithm, which primarily uses recursion. Instead of just reading about recursion to understand it, I implemented it in a real decision-making system, which made everything click.


## Features 
- Multiplayer Mode (PvP)
- AI mode HARD (using Minimax)
- AI mode EASY (using random seed generator)
- Reursie decision-making
- Optimal move selection (AI never loses)
- Clean and simple terminal interface


## What I Learned
- How reursion actually works in practice (not just theory)
- Implementing the Minimax algorithm for game AI
- Breaking down problems into smaller problems
- Managing game state and backtracking
- Writing cleaner and more structure C code


## How It Works
The AI uses the Minimax algorithm, which:
- Simulates all possible future moves
- Evaluates each outcome (win, lose, draw)
- Chooses the move that maximises the chances of winning

Scoring system:
- +10 : AI wins
- -10 : Player wins
- 0 : Draw

Depth is used to:
- Prefer faster wins
- Delay losses as much as possible


## How to Run
- Open a terminal in the folder where TicTacToe_updated.c is located
- Compile the program:
  ```bash
  gcc TicTacToe_updated.c -o TicTacToe
- Run the executable:
  ```bash
  ./TicTacToe
- Follow the interactive menu to play the game


## Why This Project Matters
This project wasn't just about building a game, it was more for learning recursion. The prototype "tictactoe.c" is one of the first games I had made after learning the fundamentals of C. However after being introduced to recursion, I struggled to understand the concept and implemention of it initially. So instead of learning the theory only, I thought of impplementing it practically which would help me understand the concept as well as develop the already built foundational game. Implementaing Minimax turned a concept I found confusing into something I can now apply.

## Author
Arittri Ray 
Software Engineering | Building strong foundation in problem solving and data algorithms

