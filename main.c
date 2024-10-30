#include <stdio.h>



char board[3][3];
const char PLAYER1 = 'X' ;
const char PLAYER2 = 'O';

void printBoard();
void resetBoard();
int checkFreespaces();
void playerMove(char player);
void computerMove();
char checkWinner();
void printWinner(char winner );



void main(){

char winner = ' ';


// char currentMove = 
resetBoard();
do
{
printBoard();
playerMove(PLAYER1);
winner=checkWinner();
if (winner != ' ' || checkFreespaces()==0  )
{
    break;
}

printBoard();

playerMove(PLAYER2);
winner=checkWinner();
if (winner != ' ' || checkFreespaces()==0  )
{
    break;
}
} while (winner == ' ' && checkFreespaces() != 0);
printBoard();
printWinner(winner);












}


void printBoard(){
    
printf(" -----------------\n");
printf("|  %c  |  %c  |  %c  |",board[0][0],board[0][1],board[0][2]);
printf("\n|-----|-----|-----|\n");
printf("|  %c  |  %c  |  %c  |",board[1][0],board[1][1],board[1][2]);
printf("\n|-----|-----|-----|\n");
printf("|  %c  |  %c  |  %c  |",board[2][0],board[2][1],board[2][2]);
printf("\n -----------------\n");



};
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
void playerMove(char player){
int col,row;
do
{
printf("Player %c's turn.\n",player );

printf("Enter column between (1-3) : ");
scanf("%d",&col);
col--; // minusing one so that we get the base 0
printf("Enter row between (1-3) : ");
scanf("%d",&row);
row--; // minusing one so that we get the base 0
if (col > 2 || col < 0 || row > 2 || row < 0 || board[row][col] != ' ')
{
    printf("Invalid input , please try again ! \n");
}
else
{
board[row][col] = player;
break;
}

} while (col > 2 || col < 0 || row > 2 || row < 0 || board[row][col] != ' ');


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
else
{
    printf("It's a tie ! ");
}

};