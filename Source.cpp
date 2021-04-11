#include <iostream>
#include <stdlib.h>
#include "Kattas-Jero.cpp"
using namespace std;

Board Board1;
int row, col;

bool cell_check() {
	if (0 <= row < 3 && 0 <= col < 3 && Board1.board[row][col] == ' ') {
		return true;
	}
}

int play() {
	char back;
	int val;
	cout << Board1.options;
	cout << "Enter ur command (1, 2, 3): ";
	cin >> val;
	if (val == 1) {
		system("CLS");
		cout << "Enter ur name: ";
		cin >> Board1.player1;
		cout << "Enter ur opponent's name: ";
		cin >> Board1.player2;
		cout << endl;

		while (Board1.game_over() != false) {
			cout << Board1.current_player() << "'s turn" << endl;
			cout << endl;
			cout << "Enter the row and column: ";
			cin >> row >> col;
			while (cell_check() != true) {
				cout << "Plzz enter an empty/valid cell: ";
				cin >> row >> col;
			}
			system("CLS");
			cout << "\n\n";
			Board1.make_move(row, col);
			Board1.display_board();
		}

		if (Board1.game_over() == true) {
			cout << "\n\n";
			cout << Board1.Winner() << " won the game!";
			Board1.score();
			Board1.turn = 'X';
			cout << "\n\n";
			cout << "To go back (press any alphabet): ";
			cin >> back;
			if (back == 'a') {
				system("CLS");
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						Board1.board[i][j] = ' ';
					}
				}
				play();
			}
			else {
				system("CLS");
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						Board1.board[i][j] = ' ';
					}
				}
				play();
			}
		}

		else if (Board1.moves == Board1.max_moves) {
			cout << "\n\n";
			cout << "Draw Match";
			cout << "\n\n";
			Board1.turn = 'X';
			cout << "To go back (press 'b'): ";
			cin >> back;
			if (back == 'b') {
				system("CLS");
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						Board1.board[i][j] = ' ';
					}
				}
				play();
			}
		}
	}
	else if (val == 2) {
		system("CLS");
		cout << Board1.player1 << " = " << Board1.score1;
		cout << "\n";
		cout << Board1.player2 << " = " << Board1.score2;
		cout << "\n\n";
		cout << "\n\n";
		cout << "To go back (press any alphabet): ";
		cin >> back;
		if (back == 'b') {
			system("CLS");
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					Board1.board[i][j] = ' ';
				}
			}
			play();
		}
		else {
			system("CLS");
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					Board1.board[i][j] = ' ';
				}
			}
			play();
		}
	}
	else if (val == 3) {
		system("CLS");
		return 0;
	}
	else {
		system("CLS");
		cout << "Please enter correct value";
		cout << "\n\n";
		play();
	}
}

int main() {
	play();
	return 0;
}