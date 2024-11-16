#include <stdio.h>
#include "tc.h"
#include <conio.h>


char board[3][3];
const char PLAYER1 = 'X' ;
const char PLAYER2 = 'O';

void printBoard(int cursorRow, int cursorCol);
void resetBoard();
int checkFreespaces();
int playerMove(char player);
void computerMove();
char checkWinner();
void printWinner(char winner );



void main(){
tc_clear_screen();
char winner = ' ';
resetBoard();
do
{

if (playerMove(PLAYER1)==1)
{
    winner='q';
    break;
}
winner=checkWinner();
if (winner != ' ' || checkFreespaces()==0  )
{
    break;
}

printBoard(-1,-1);
// playerMove(PLAYER2);
if (playerMove(PLAYER2)==1)
{
    winner='q';
    break;
}

winner=checkWinner();
if (winner != ' ' || checkFreespaces()==0  )
{
    break;
}
} while (winner == ' ' && checkFreespaces() != 0);
printBoard(-1,-1);
printWinner(winner);
}


void printBoard(int cursorRow, int cursorCol) {
    tc_clear_screen();
    printf(" %s-----------------\n", TC_B_YEL);
    for (int i = 0; i < 3; i++) {
        printf("%s|", TC_B_YEL);
        for (int j = 0; j < 3; j++) {
            if (i == cursorRow && j == cursorCol) {
                printf(" [%c] ", board[i][j] == ' ' ? ' ' : board[i][j]);
            } else if (board[i][j] == PLAYER1) {
                printf("  %s%c  ", TC_B_GRN, PLAYER1);
            } else if (board[i][j] == PLAYER2) {
                printf("  %s%c  ", TC_B_BLU, PLAYER2);
            } else {
                printf("     ");
            }
            printf("%s|", TC_B_YEL);
        }
        printf("\n%s|-----|-----|-----|%s\n", TC_B_YEL, TC_NRM);
    }
}
void resetBoard(){
    for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        board[i][j]= ' ';
    }
    
}

};


int checkFreespaces(){
int freeSpaces = 9;
for (int i = 0; i < 3 ; i++)
{
    for (int j = 0; j < 3 ; j++)
    {
    if (board[i][j] != ' ')
    {
        freeSpaces--;         
    }       
    }
}
return freeSpaces;
};
int playerMove(char player){
int cursorRow = 0, cursorCol = 0;
char key;
int occupiedPos=0;
do
{
printBoard(cursorRow, cursorCol);
if (occupiedPos)
{
    printf("%sPosition already Occupied ! , Try again %s\n",TC_BG_RED,TC_BG_NRM);
    occupiedPos=0;
}

printf("%s Player %s%c's %sturn %s\n",TC_B_MAG, player=='X' ? TC_B_GRN:TC_B_BLU,player,TC_B_MAG,TC_BG_NRM);

        key = _getch(); // Read key press

        // Detect arrow keys (multi-byte sequence in Windows)
        if (key == 0 || key == -32) {
            key = _getch(); // Read actual arrow key
            switch (key) {
                case 72: // Up arrow
                    cursorRow = (cursorRow > 0) ? cursorRow - 1 : 2;
                    break;
                    return 0;
                case 80: // Down arrow
                    cursorRow = (cursorRow < 2) ? cursorRow + 1 : 0;
                    break;
                    return 0;
                case 75: // Left arrow
                    cursorCol = (cursorCol > 0) ? cursorCol - 1 : 2;
                    break;
                    return 0;
                case 77: // Right arrow
                    cursorCol = (cursorCol < 2) ? cursorCol + 1 : 0;
                    break;
                    return 0;
            }
        } else if (key == 13) { // Enter key to place the marker
            if (board[cursorRow][cursorCol] == ' ') {
                board[cursorRow][cursorCol] = player;
                break;
                return 0;
            } else {
                occupiedPos = 1;    
            }
        } 
        else
        {
            return 1;
        }
        
          
               
    }while (1);

};

// void computerMove(){

// };

char checkWinner(){
for (int i = 0; i < 3 ; i++)
{
    // checking rows
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
    {
        return board[i][0];
        
    }
    // checking columns
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
    {
        return board[0][i];
    }
}
    // checking diagonals
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[2][0] == board[1][1] && board[2][0] == board[0][2] ) )
    {
        return board[1][1];
    }
    return ' '; 
};

void printWinner(char winner){

if (winner == PLAYER1 )
{
    printf("Congrats Player %c Wins !",PLAYER1);
}
else if (winner == PLAYER2 )
{
    printf("Congrats Player %c Wins !",PLAYER2);
}
else if (winner == 'q')
{
    printf("Game Quitted");
}
else
{
    printf("It's a tie ! ");
}
};