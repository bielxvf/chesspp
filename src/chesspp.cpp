#include <iostream>
#include <cxxopts.hpp>
#include <cstdio>

#define WHITE 0
#define BLACK 1

#define DIM 8

struct Square {
	int file;
	int rank;
}

const std::string initial_board[8][8] = {{ "♜", "♞", "♝", "♛", "♚", "♝", "♞", "♜"},
					  { "♟︎", "♟︎", "♟︎", "♟︎", "♟︎", "♟︎", "♟︎", "♟︎"},
					  { " ", " ", " ", " ", " ", " ", " ", " "},
					  { " ", " ", " ", " ", " ", " ", " ", " "},
					  { " ", " ", " ", " ", " ", " ", " ", " "},
					  { " ", " ", " ", " ", " ", " ", " ", " "},
					  { "♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙"},
					  { "♖", "♘", "♗", "♕", "♔", "♗", "♘", "♖"}};

void make_move(std::string board[8][8]) {
	Square from;
	Square to;
	std::cin >> from.file >> from.rank;
	std::cin >> to.file >> to.rank;
	// move the piece on from to to
}

void copy_board(const std::string from[8][8], std::string to[8][8]) {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			to[i][j] = from[i][j];
		}
	}
}

void print_board_white(std::string board[8][8]) {
	for (int i = 0; i < DIM; i++) {
		printf("\033[30;47m");
		std::cout << DIM-i << " | ";
		for (int j = 0; j < DIM; j++) {
			std::cout << board[i][j] << " ";
		}
		printf("\033[0m");
		std::cout << std::endl;
	}
	printf("\033[30;47m");
	std::cout << "   ―――――――――――――――― ";
	printf("\033[0m");
	std::cout << std::endl;

	printf("\033[30;47m");
	std::cout << "    a b c d e f g h ";
	printf("\033[0m");
	std::cout << std::endl;
}

void print_board_black(std::string board[8][8]) {

}

void print_board(std::string board[8][8], int color) {
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
	std::string board[8][8];
	int color;
	bool white_wins = false;
	bool black_wins = false;

	std::cout << "Choose your color (0 - White, 1 - Black): ";
	std::cin >> color;

	copy_board(initial_board, board);

	do {
		print_board(board, color);
		make_move(board);
	} while (!white_wins && !black_wins);
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
