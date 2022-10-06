#include <stdio.h>
#include <stdbool.h>

void printOptions(){
	printf("Options:\n");
	printf("a) tictactoe\n");
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
	for(int i = 0; i < 3; i++){
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-'){
			return true;
		}
	}
	for(int i = 0; i < 3; i++){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-'){
			return true;
		}
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-'){
		return true;
	}
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != '-'){
		return true;
	}
	return false;
}

void tictactoe(){
	int turnCounter = 1;
	// initialize board to be empty
	char board[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = '-';
		}
	}

	// track if game is finished
	bool gameFinished = false;
	int row;
	int column;
	// game main loop
	while(!gameFinished){

		printBoard(board);
		printf("Input the row (0-2): ");
		scanf("%d", &row);
		printf("Input the column (0-2): ");
		scanf("%d", &column);

		if(turnCounter == 1){
			if(board[row][column] == '-'){
				board[row][column] = 'x';
			}
			if(row < 3 && row >= 0 && column < 3 && column >= 0){
				turnCounter = 2;
			} else{
				printf("Invalid row/column combination. Pick again.\n");
			}
		} else {
			if(board[row][column] == '-'){
				board[row][column] = 'o';
			}
			if(row < 3 && row >= 0 && column < 3 && column >= 0){
				turnCounter = 1;
			} else{
				printf("Invalid row/column combination. Pick again.\n");
			}
		}
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
			tictactoe();
	}

	// bool gameFinished = false;
	// // while the game has not concluded
	// while(!gameFinished){
	// 	// if it's the oppon
	// }
	return 0;
}
