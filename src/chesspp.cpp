#include <iostream>
#include <cxxopts.hpp>

#define WHITE 1 
#define BLACK 2

const char initial_board[8][8] = { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
				 { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
				 { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				 { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				 { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				 { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				 { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
				 { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};

void print_board_white(char board[8][8]) {

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
	std::cout << "Choose your color: ";
	std::cin >> color;
	char board[8][8] = initial_board;
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
