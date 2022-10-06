#include <stdio.h>
void printOptions(){
	printf("Options:\n");
	printf("a) tictactoe\n");
	printf("Enter option: ");
}

void tictactoe(){

	// print dialog
	printf("First or second (1 = first, 2 = second): ");
	int turnCounter;
	scanf("%d", &turnCounter);

	// initialize board to be empty
	int board[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = 0;
		}
	}

	// track if game is finished
	bool gameFinished = false;
	int row;
	int column
	// game main loop
	while(!gameFinished){

		printf("Input the row: ");
		scanf("%d", &row);
		printf("Input the column: ");
		scanf("%d", &column);
		board[column][row] = turnCounter;
		printBoard(&board);
		if(turnCounter == 1){
			turnCounter == 2;
		} else {
			turnCounter = 1;
		}
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
