#include <iostream>
#include <cxxopts.hpp>
#include <ctype.h>

struct {
	const int None = 0;
	
	const int WKing = 1;
	const int WQueen = 2;
	const int WRook = 3;
	const int WBishop = 4;
	const int WKnight = 5;
	const int WPawn = 6;
	
	const int BKing = -WKing;
	const int BQueen = -WQueen;
	const int BRook = -WRook;
	const int BBishop = -WBishop;
	const int BKnight = -WKnight;
	const int BPawn = -WPawn;
} Piece;

void new_game(void) {
	int board[64];
	std::string fen;

	for (int i = 0; i < 64; i++) {
		board[i] = Piece.None;
	}
}

int main(int argc, char *argv[]) {
	cxxopts::Options options("chesspp", "Chesspp");

	options.add_options()
		("h,help", "Print usage")
		("n,new", "Start new game")
	;
	auto args = options.parse(argc, argv);

	if (args.count("help") || argc == 1) {
		std::cout << options.help() << std::endl;
		return 0;
	} else if (args.count("new")) {
		new_game();
		return 0;
	}

	return 0;
}
