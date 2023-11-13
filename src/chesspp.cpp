#include <iostream>
#include <cxxopts.hpp>

#define WHITE 0
#define BLACK 1

#define DIM 8

const char initial_board[8][8] = {{ 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
				  { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
				  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				  { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				  { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
				  { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

void copy_board(const char from[8][8], char to[8][8]) {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			to[i][j] = from[i][j];
		}
	}
}

void print_board_white(char board[8][8]) {
	for (int i = 0; i < DIM; i++) {
		std::cout << DIM-i << " | ";
		for (int j = 0; j < DIM; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "    - - - - - - - -" << std::endl;
	std::cout << "    a b c d e f g h" << std::endl;
}

void print_board_black(char board[8][8]) {

}

void print_board(char board[8][8], int color) {
	switch (color) {
		case WHITE:
			print_board_white(board);
			break;
		case BLACK:
			print_board_black(board);
			break;
		default:
			break;
	}
}

void new_game(void) {
	char board[8][8];
	int color;
	std::cout << "Choose your color (0 - White, 1 - Black): ";
	std::cin >> color;
	copy_board(initial_board, board);
	print_board(board, color);
}

int main(int argc, char** argv) {
	cxxopts::Options options("chesspp", "Chesspp");
	
	options.add_options()
		("h,help", "Print usage")
		("n,new", "Start new game")
	;
	auto args = options.parse(argc, argv);

	if (args.count("help")) {
		std::cout << options.help() << std::endl;
		exit(0);
	} else if (args.count("new")) {
		new_game();
		exit(0);
	}

	return 0;
}
