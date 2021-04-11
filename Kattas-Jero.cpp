#include <iostream>
using namespace std;

class Board {
public:
	string options;
	string winner;
	int max_moves;
	char board[3][3];
	char turn;
	int moves;
	string player1;
	string player2;
	int score1;
	int score2;

	Board() {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				board[i][j] = ' ';
			}
		}
		options = "1) PLAY\n2) SCORE\n3) EXIT\n\n";
		turn = 'X';
		max_moves = 9;
		moves = 0;
		score1 = 0;
		score2 = 0;
	}

	void display_board() {
		cout << "\t\t" << " " << "  |  " << " " << "  |  " << " " << endl;
		cout << "\t\t" << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
		cout << "\t     " << "--------------------" << endl;
		cout << "\t\t" << " " << "  |  " << " " << "  |  " << " " << endl;
		cout << "\t\t" << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
		cout << "\t     " << "--------------------" << endl;
		cout << "\t\t" << " " << "  |  " << " " << "  |  " << " " << endl;
		cout << "\t\t" << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2];
		cout << "\n\n";
	}

	void make_move(int i, int j) {
		if (board[i][j] == ' ') {
			board[i][j] = turn;
		}
		moves += 1;
		change_turn();
	}

	void change_turn() {
		if (turn == 'X') {
			turn = 'O';
		}
		else if (turn == 'O') {
			turn = 'X';
		}
	}

	int game_over() {
		/*int dir[8][2] = { {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1} };
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; i < 3; ++j) {
				for (int a = 0; a < 8; ++a) {
					char coin = board[i][j];
					if (coin != ' ') {
						bool flag = true;
						for (int k = 1; k < 3; ++k) {
							int x = i + k * dir[a][0];
							int y = j + k * dir[a][1];
							if (0 <= x < 3) {
								if (0 <= y < 3) {
									if (coin != board[x][y]) {
										flag = false;
										break;
									}
								}
							}
							else {
								flag = false;
							}
						}
						if (flag == true) {
							winner = turn;
							return true;
						}
						else {
							return false;
						}
					}
				}
			}
		}
	}*/

		if (board[0][0] != ' ') {
			if (board[0][1] != ' ') {
				if (board[0][2] != ' ') {
					if (board[0][0] == board[0][1]) {
						if (board[0][1] == board[0][2]) {
							winner = turn;
							return true;
						}
					}
				}
			}
		}
		else if (board[1][0] != ' ') {
			if (board[1][1] != ' ') {
				if (board[1][2] != ' ') {
					if (board[1][0] == board[1][1]) {
						if (board[1][1] == board[1][2]) {
							winner = turn;
							return true;
						}
					}
				}
			}
		}
		else if (board[2][0] != ' ') {
			if (board[2][1] != ' ') {
				if (board[2][2] != ' ') {
					if (board[2][0] == board[2][1]) {
						if (board[2][1] == board[2][2]) {
							winner = turn;
							return true;
						}
					}
				}
			}
		}
		else if (board[0][0] != ' ') {
			if (board[1][0] != ' ') {
				if (board[2][0] != ' ') {
					if (board[0][0] == board[1][0]) {
						if (board[1][0] == board[2][0]) {
							winner = turn;
							return true;
						}
					}
				}
			}
		}
		else if (board[0][1] != ' ') {
			if (board[1][1] != ' ') {
				if (board[2][1] != ' ') {
					if (board[0][0] == board[1][1]) {
						if (board[1][1] == board[2][1]) {
							winner = turn;
							return true;
						}
					}
				}
			}
		}
		else if (board[0][2] != ' ') {
			if (board[1][2] != ' ') {
				if (board[2][2] != ' ') {
					if (board[0][2] == board[1][2]) {
						if (board[1][2] == board[2][2]) {
							winner = turn;
							return true;
						}
					}
				}
			}
		}
		else if (board[0][0] != ' ') {
			if (board[1][1] != ' ') {
				if (board[2][2] != ' ') {
					if (board[0][0] == board[1][1]) {
						if (board[1][1] == board[2][2]) {
							winner = turn;
							return true;
						}
					}
				}
			}
		}
		else if (board[2][0] != ' ') {
			if (board[1][1] != ' ') {
				if (board[0][2] != ' ') {
					if (board[2][0] == board[1][1]) {
						if (board[1][1] == board[0][2]) {
							winner = turn;
							return true;
						}
					}
				}
			}
		}
	}

	string Winner() {
		if (game_over() == true) {
			if (turn == 'X') {
				return player2;
			}
			else {
				return player1;
			}
		}
	}

	string current_player() {
		if (turn == 'X') {
			return player1;
		}
		else {
			return player2;
		}
	}

	int score() {
		if (Winner() == player2) {
			score2 += 1;
			return score2;
		}
		else {
			score1 += 1;
			return score1;
		}
	}
};