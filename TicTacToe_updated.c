#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[9];

void initBoard();
void printBoard();
char checkWinner();
int movesLeft();
void playerMove(char turn);
void easyMode();
int minimax(int depth, int isMax);
void hardMode();
void Game();


int main(){
    srand(time(NULL));

    char playAgain;
    do{
        initBoard();
        Game();

        printf("Play again? (Y/N): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'Y' || playAgain == 'y');

    printf("Thanks for playing!\n");
    return 0;
}


void initBoard(){
    for(int i = 0; i < 9; i++){
        board[i] = ' ';
    }
}

void printBoard(){
    printf("\n");
    for(int i=0; i < 9; i++){
        printf(" %c ", board[i]);
        if(i%3 != 2){
            printf("|");
        }
        if(i%3 == 2 && i != 8){
            printf("\n---|---|---\n");
        }
    }
}

char checkWinner(){
    int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for(int i = 0; i < 8; i++){
        int a = winPatterns[i][0];
        int b = winPatterns[i][1];
        int c = winPatterns[i][2];

        if(board[a] != ' ' && board[a] == board[b] && board[a] == board[c]){
            return board[a];
        }
    }
    return ' ';
}

int movesLeft(){
    for(int i = 0; i < 9; i++){
        if(board[i] == ' '){
            return 1;
        }
    }
    return 0;
}

void playerMove(char turn){
    int pos;
    printf("Enter position (1-9): ");
    scanf("%d", &pos);
    pos--;

    if(pos < 0 || pos > 8 || board[pos] != ' '){
        printf("Invalid move! Try again.\n");
        playerMove(turn);
    }
    else{
        board[pos] = turn;
    } 
}

void easyMode(){
    int move;
    do{
        move = rand() % 9;
    }while(board[move] != ' ');
    
    board[move] = 'O';
}

int minimax(int depth, int isMax){
    char winner = checkWinner();

    if(winner == 'O') return 10 - depth;   
    if(winner == 'X') return depth - 10;   
    if(!movesLeft()) return 0; 

    if(isMax){
        int best = - 1000;

        for(int i = 0; i < 9; i++){
            if(board[i] == ' '){
                board[i] = 'O';
                int score = minimax(depth + 1, 0);
                board[i] = ' ';
                if(score > best){
                    best = score;
                }
            }
        }
        return best;
    }
    else{
        int best = 1000;

        for(int i = 0; i < 9; i++){
            if(board[i] == ' '){
                board[i] = 'X';
                int score = minimax(depth + 1, 1);
                board[i] = ' ';
                if(score < best){
                    best = score;
                }
            }
        }
        return best;
    }
}

void hardMode(){
    int bestScore = -1000;
    int move = -1;

    for(int i = 0; i < 9; i++){
        if(board[i] == ' '){
            board[i] = 'O';
            int score = minimax(0,0);
            board[i] = ' ';

            if(score > bestScore){
                bestScore = score;
                move = i;
            }
        }
    }
    if(move != -1) board[move] = 'O';
}


void Game(){
    char choice;
    printf("Choose game mode: \n1. Easy Mode \n2. Hard Mode \n3. Multiplayer Mode \nEnter Choice: ");
    scanf(" %c", &choice);

    if (choice != '1' && choice != '2' && choice != '3') {
        printf("Invalid choice. Exiting.\n");
        return;
    }

    char winner = ' ';
    int turn = 0;
    while (winner == ' ' && movesLeft()) {
        printBoard();

        if(choice == '1' || choice == '2'){ 
            // Singleplayer
            if (turn == 0) {
                printf("\nYour turn (X)\n");
                playerMove('X');
                turn = 1;
            } 
            else{
                printf("\nAI turn (O)\n");
                if(choice == '1'){
                    easyMode();
                }
                else{
                    hardMode();
                }
                turn = 0;
            }
        } 
        else{ 
            // Multiplayer
            printf("\nPlayer %c turn\n", (turn == 0) ? 'X' : 'O');
            playerMove((turn == 0) ? 'X' : 'O');
            turn = 1 - turn;
        }
        winner = checkWinner();
    }

    printBoard();
    if(winner != ' '){
        if(winner == 'O' && (choice == '1' || choice == '2')){
            printf("AI wins!\n");
        }
        else{
            printf("Player %c wins!\n", winner);
        }
    } 
    else{
        printf("\nIt's a draw!\n");
    }

}
