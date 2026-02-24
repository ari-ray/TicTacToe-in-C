#include<stdio.h>
#include<time.h>
#include<stdlib.h>

char one = '1', two = '2', three = '3';
char four  = '4', five = '5', six = '6';
char seven = '7',  eight = '8', nine = '9';


void printBoard();
void printLabelledBoard(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine);
int multiplayer(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine);
int checkWinner(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine, char player);
int singleplayer(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine);
int checkWinner2(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine, char player, char computer);
void Game();


int main(){

    Game();

    do{
    char n;
    printf("\nDo you want to play again? type Y or N: \n");
    scanf(" %c", &n);

    if(n == 'Y')
        Game();
    else if (n == 'N' || n == 'Q'){
        printf("Bye");
        break;
    }
    else
        printf("Invalid\n");
    }while(1);

    return 0;
}

void Game(){

    printBoard();
    char a,b;


    printf("\nPress any key to start the game: ");
    scanf(" %c", &a);

    if(a == 'Q')
        return 0;

    printLabelledBoard(one, two, three, four, five, six, seven, eight, nine);

    do{
    printf("\nFor Single Player Mode press: '1' \nFor Multiplayer Mode press: '2'\nFor exiting the game press Q\n");
    scanf(" %c", &b);


    if(b == '1'){
        singleplayer(one, two, three, four, five, six, seven, eight, nine);
        return 0;
    }
    else if(b == '2'){
        multiplayer(one, two, three, four, five, six, seven, eight, nine);
        return 0;
    }
    else if(b == 'Q'){
        printf("Goodbye");
    }
    else{
        printf("Invalid. Follow the instructions properly");
    }
    }while(b!='1' || b!='2' || b!='Q');


}

void printBoard(){

    printf("   |   |   ");
    printf("\n---|---|---");
    printf("\n   |   |   ");
    printf("\n---|---|---");
    printf("\n   |   |   ");

}

void printLabelledBoard(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine){

    printf("\n %c | %c | %c ", one, two, three);
    printf("\n---|---|---");
    printf("\n %c | %c | %c ", four, five, six);
    printf("\n---|---|---");
    printf("\n %c | %c | %c\n ", seven, eight, nine);

}

int multiplayer(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine){

    char player = 'X';
    char position;


    for(int i=1; i<=9;i++){


        printf("\nPlayer %c enter your move(1-9): ", player);
        scanf(" %c", &position);

        if(position == '1' && one != 'X' && one != 'O')
            one = player;
        else if(position == '2' && two != 'X' && two != 'O')
            two = player;
        else if(position == '3' && three != 'X' && three != 'O')
            three = player;
        else if(position == '4' && four != 'X' && four != 'O')
            four = player;
        else if(position == '5' && five != 'X' && five != 'O')
            five = player;
        else if(position == '6' && six != 'X' && six != 'O')
            six = player;
        else if(position == '7' && seven != 'X' && seven != 'O')
            seven = player;
        else if(position == '8' && eight != 'X' && eight != 'O')
            eight = player;
        else if(position == '9' && nine != 'X' && nine != 'O')
            nine = player;
        else if(position == 'Q'){
            printf("Goodbye");
            goto end;
        }
        else{
            printf("Follow the instructions properly\n");
            i--;
            continue;
        }


        printLabelledBoard(one, two, three, four, five, six, seven, eight, nine);


        if(checkWinner(one, two, three, four, five, six, seven, eight, nine, player) == 1){
           printLabelledBoard(one, two, three, four, five, six, seven, eight, nine);
           printf("\nPlayer %c wins!", player);
           goto end;
        }


        if(player == 'X')
            player = 'O';
        else if(player == 'O')
            player = 'X';
    }

    printLabelledBoard(one, two, three, four, five, six, seven, eight, nine);
    printf("\nIt's a draw!");

    end:
        return 0;
}

int checkWinner(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine, char player){

    //rows
    if((one == player && two == player && three == player ) || (four == player && five == player && six == player) || (seven == player && eight == player && nine == player))
        return 1;
    //columns
    else if((one == player && four == player && seven == player ) || (two == player && five == player && eight == player) || (three == player && six == player && nine == player))
        return 1;
    //diagonals
    else if((one == player && five == player && nine==player)||(three==player && five==player && seven==player))
        return 1;
    else
        return 0;

}

int singleplayer(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine){

    char player = 'X';
    char position;
    srand(time(0));
    int x;
    char computer ='O';

    for(int i=1; i<=5;i++){
        printf("\nPlayer %c enter your move(1-9): ", player);
        scanf(" %c", &position);

        if(position == '1' && one != 'X' && one != 'O')
            one = player;
        else if(position == '2' && two != 'X' && two != 'O')
            two = player;
        else if(position == '3' && three != 'X' && three != 'O')
            three = player;
        else if(position == '4' && four != 'X' && four != 'O')
            four = player;
        else if(position == '5' && five != 'X' && five != 'O')
            five = player;
        else if(position == '6' && six != 'X' && six != 'O')
            six = player;
        else if(position == '7' && seven != 'X' && seven != 'O')
            seven = player;
        else if(position == '8' && eight != 'X' && eight != 'O')
            eight = player;
        else if(position == '9' && nine != 'X' && nine != 'O')
            nine = player;
        else if(position == 'Q'){
            printf("Goodbye");
            return 0;
        }
        else{
            printf("Follow the instructions properly");
            i--;
            continue;
        }

        printLabelledBoard(one, two, three, four, five, six, seven, eight, nine);

        if(checkWinner2(one, two, three, four, five, six, seven, eight, nine, player, computer) == 1){
            printLabelledBoard(one, two, three, four, five, six, seven, eight, nine);
            printf("\nYou Win!");
            return 0;
        }
        else if(checkWinner2(one, two, three, four, five, six, seven, eight, nine, player, computer)==2){
            printf("\nYou Lose!");
            return 0;
        }

        if(i<5){
            do{
                x = (rand() % 9) + 1;

                while(x==position){
                    x = (rand() % 9) + 1;
                }
                if(x == 1 && one != 'X' && one != 'O'){
                    one = computer;
                    break;
                }
                else if(x == 2 && two != 'X' && two != 'O'){
                    two = computer;
                    break;
                }
                else if(x == 3 && three != 'X' && three != 'O'){
                    three = computer;
                    break;
                }
                else if(x == 4 && four != 'X' && four != 'O'){
                    four = computer;
                    break;
                }
                else if(x == 5 && five != 'X' && five != 'O'){
                    five = computer;
                    break;
                }
                else if(x == 6 && six != 'X' && six != 'O'){
                    six = computer;
                    break;
                }
                else if(x == 7 && seven != 'X' && seven != 'O'){
                    seven = computer;
                    break;
                }
                else if(x == 8 && eight != 'X' && eight != 'O'){
                    eight = computer;
                    break;
                }
                else if(x == 9 && nine != 'X' && nine != 'O'){
                    nine = computer;
                    break;
                }
            }while(one == computer|| two == computer || three == computer || four == computer || five == computer || six == computer || seven == computer || eight == computer || nine == computer);
        }

        printLabelledBoard(one, two, three, four, five, six, seven, eight, nine);

        if(checkWinner2(one, two, three, four, five, six, seven, eight, nine, player, computer) == 1){
            printLabelledBoard(one, two, three, four, five, six, seven, eight, nine);
            printf("\nYou Win!");
            return 0;
        }
        else if(checkWinner2(one, two, three, four, five, six, seven, eight, nine, player, computer)==2){
            printf("\nYou Lose!");
            return 0;
        }

    }

    printf("\nIt's a draw");
    return 0;


}


int checkWinner2(char one, char two, char three, char four, char five, char six, char seven, char eight, char nine, char player, char computer){

    //rows for player
    if((one == player && two == player && three == player ) || (four == player && five == player && six == player) || (seven == player && eight == player && nine == player))
        return 1;
    //columns for player
    else if((one == player && four == player && seven == player ) || (two == player && five == player && eight == player) || (three == player && six == player && nine == player))
        return 1;
    //diagonals for player
    else if((one == player && five == player && nine==player)||(three==player && five==player && seven==player))
        return 1;
    //rows for comp
    else if((one == computer && two == computer && three == computer ) || (four == computer && five == computer && six == computer) || (seven == computer && eight == computer && nine == computer))
        return 2;
    //columns for comp
    else if((one == computer && four == computer && seven == computer ) || (two == computer && five == computer && eight == computer) || (three == computer && six == computer && nine == computer))
        return 2;
    //diagonals for comp
    else if((one == computer && five == computer && nine==computer)||(three==computer && five==computer && seven==computer))
        return 2;
    else
        return 0;
}