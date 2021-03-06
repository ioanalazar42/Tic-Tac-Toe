#include "stdafx.h"
#include <iostream>

using namespace std;

char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int gameStatus();
void drawBoard();

int main() {
	int player = 1, i, choice;
	char mark;
	do {
		drawBoard();

		//player chooses square
		player = (player % 2) ? 1 : 2;
		cout << "Player " << player << ", enter a number: ";
		cin >> choice;
		
		/*
			player 1 uses X
			player 2 uses O
		*/
		mark = (player == 1) ? 'X' : 'O';

		//the chosen sqaure is marked with X or O
		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else {
			cout << "Invalid moves";
			player--;
			cin.ignore();
			cin.get();
		}
		//update game status
		i = gameStatus();
		player++;
	} while (i == -1); // executes while the game is  not over
	drawBoard();
	if (i == 1)
		cout << "\tPlayer " << --player << " won!";
	else
		cout << "\tIt's a draw!";
	cin.ignore();
	cin.get();
	return 0;
}


/*
FUNCTION TO UPDATE GAME STATUS
1 if win-lose
0 if draw
-1 if game is in progress
*/
int gameStatus() {
	//check lines
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	if (square[4] == square[5] && square[5] == square[6])
		return 1;
	if (square[7] == square[8] && square[8] == square[9])
		return 1;

	//check columns
	if (square[1] == square[4] && square[4] == square[7])
		return 1;
	if (square[2] == square[5] && square[5] == square[8])
		return 1;
	if (square[3] == square[6] && square[6] == square[9])
		return 1;

	//check diagonals
	if (square[1] == square[5] && square[5] == square[9])
		return 1;
	if (square[3] == square[5] && square[5] == square[7])
		return 1;

	/* 
		if none of the above cases are met, the game is a draw
		the vector must contain only 0 and X
		if the vector contains a numerical value, the game is not a draw
	*/
	if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
		square[4] != '4' && square[5] != '5' && square[6] != '6' &&
		square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	return -1;
}

//FUNCTION THAT DRAWS THE BOARD
void drawBoard() {
	system("cls");
	cout << "\tTic Tac Toe\n\n";

	cout << "Player 1 (X) - Player 2 (O)" << endl << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}



