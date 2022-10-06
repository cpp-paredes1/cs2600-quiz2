#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void printOptions(){
	printf("Options:\n");
	printf("a) 2 player mode\n");
	printf("b) 1 player mode (vs CPU)\n");
	printf("Enter option: ");
}

void printBoard(char board[3][3]){	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
bool checkWin(char board[3][3]){
	// horizontal check
	for(int i = 0; i < 3; i++){
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-'){
			return true;
		}
	}
	// vertical check
	for(int i = 0; i < 3; i++){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-'){
			return true;
		}
	}
	// diagonal check
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-'){
		return true;
	}
	// diagonal check
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != '-'){
		return true;
	}
	return false;
}
bool checkValidMove(int row, int column, char board[3][3]){
	// if the board spot is empty and the spot isn't out of bounds it is valid
	if(board[row][column] == '-' && row >= 0 && row < 3 && column >= 0 && column < 3){
		return true;
	}
	return false;
}
void tictactoe(bool p2Human){

	// setup random based on time
	time_t t;
	srand((unsigned)time(&t));

	int turnCounter = 1;
	if(!p2Human){
		printf("Would you like to go first or second (1 = 1st; 2 = 2nd): ");
		scanf("%d",&turnCounter);
	}

	// initialize board to be empty
	char board[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = '-';
		}
	}

	// track if game is finished
	bool gameFinished = false;
	bool validMove = false;

	// variables to track which row/column
	int row;
	int column;

	// game main loop
	while(!gameFinished){

		// output board
		printBoard(board);
		
		// if vs CPU, computer picks random spot
		if(!p2Human && turnCounter == 2){
			// random spot
			row = rand()%3;
			column = rand()%3;
			// check validity
			while(!checkValidMove(row, column, board)){
				// remake random spot
				row = rand()%3;
				column = rand()%3;
			}
			printf("The computer has picked: (%d,%d).\n", row,column);
		} else{
			// get p2 input
			printf("Input the row (0-2): ");
			scanf("%d", &row);
			printf("Input the column (0-2): ");
			scanf("%d", &column);
		}
		// check validity
		validMove = checkValidMove(row, column, board);
		// update board / turn counter
		if(turnCounter == 1){
			if(validMove){
				board[row][column] = 'x';
				turnCounter = 2;
			} else{
				printf("Invalid row/column combination. Pick again.\n");
			}
		} else {
			if(validMove){
				board[row][column] = 'o';
				turnCounter = 1;
			} else{
				printf("Invalid row/column combination. Pick again.\n");
			}
		}
		// check if board is in a winning state
		gameFinished = checkWin(board);
	}
	printBoard(board);
	if(turnCounter == 2){
		printf("Player 1 wins.");
	} else{
		printf("Player 2 wins.");
	}
}

int main(){
	// prompt for which gaem they wish to play
	printOptions();
	// read their option
	char option;
	scanf("%c",&option);
	// if its tictactoe --> run tictactoe program
	switch(option){
		case 'a':
			tictactoe(true);
			break;
		case 'b':
			tictactoe(false);
			break;
	}
	return 0;
}
