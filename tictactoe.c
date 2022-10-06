#include <stdio.h>
void printOptions(){
	printf("Options:\n");
	printf("a) tictactoe\n");
	printf("Enter option: ");
}

void tictactoe(){

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
